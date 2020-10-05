#include "Repository.h"
#include "../config/logger.h"

Repository::Repository(QString db_name) {

    a_repository = QSqlDatabase::addDatabase("QSQLITE");

    std::ifstream f(db_name.toStdString(), std::ios_base::in);
    if (!f.good())
        create_repository();
    else {
        LOG_DEBUG("Setting the database name: " + db_name.toStdString());
        a_repository.setDatabaseName(db_name);
    }

    bool ok = a_repository.open();
    if (!ok) {
        LOG_ERROR("Could not open the db connection"); //todo: could not open. Throw error
    }
    else
        LOG_DEBUG("Db connection open");
}

Repository::~Repository() {
    LOG_DEBUG("Closing the db connection");
    a_repository.close();
}

void Repository::test() {
    a_repository.exec("insert into category (category_name) values ('programming');");
    a_repository.exec("insert into category (category_name) values ('electronics');");
    a_repository.exec("insert into category (category_name) values ('litterature');");
    a_repository.exec("insert into category (category_name) values ('python');");

    QSqlQuery query("select category_name from category;");
    while (query.next())
        LOG_DEBUG(query.value(0).toString().toStdString())
}

void Repository::create_repository() {

    LOG_DEBUG("Creating the db structure");

    a_repository.setDatabaseName("internetbook.sqlite");
    bool ok = a_repository.open();

    if (ok) {
        QString create_category =
                "create table category ("
                    "category_id integer primary key,"
                    "parent_category_id integer default 0 references category(category_id),"
                    "category_name text,"
                    "ordering integer"
                ");";

        QString create_link =
        "create table link ("
            "link_id integer primary key,"
            "url text not null,"
            "link_name text,"
            "category_id integer default 0 references category(category_id)"
            ");";

        QString create_keyword =
        "create table keywork ("
            "keyword_id integer primary key,"
            "keyword text"
            ");";

        QString create_link_keyword =
        "create table link_keyword ("
            "link_id integer not null references link(link_id) on delete cascade,"
            "keyword_id integer not null references keyword(keyword_id) on delete cascade"
            ");";

        a_repository.exec(create_category);
        a_repository.exec(create_link);
        a_repository.exec(create_keyword);
        a_repository.exec(create_link_keyword);

        a_repository.close();

    } else {
        ; //could not open db. throw error
    }

}
