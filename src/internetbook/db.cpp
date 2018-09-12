#include "db.h"

Db::Db(QString db_name) : a_saved{true} {

    a_db = QSqlDatabase::addDatabase("QSQLITE");

    std::ifstream f(db_name.toStdString(), std::ios_base::in);
    if (!f.good())
        createDB();
    else {
        a_db.setDatabaseName(db_name);
        bool ok = a_db.open();
        if (!ok)
            ; //could not open. Throw error
    }

    test();

}

Db::~Db() {
    a_db.close();
}

void Db::test() {
    a_db.exec("insert into category (category_name) values ('programming');");
    a_db.exec("insert into category (category_name) values ('linux');");
    a_db.exec("insert into category (category_name) values ('windows');");
    a_db.exec("insert into category (category_name) values ('python');");
    a_db.exec("insert into category (category_name) values ('c++');");
    a_db.exec("insert into category (category_name) values ('cryptography');");
    a_db.exec("insert into category (category_name) values ('misc');");
    a_db.exec("insert into category (category_name) values ('electronics');");
    a_db.exec("insert into category (category_name) values ('github');");

    a_db.exec("update category set parent_category_id=(select category_id from category where category_name='programming') where category_name='c++';");
    a_db.exec("update category set parent_category_id=(select category_id from category where category_name='programming') where category_name='github';");
    a_db.exec("update category set parent_category_id=(select category_id from category where category_name='programming') where category_name='python';");
    a_db.exec("update category set parent_category_id=(select category_id from category where category_name='programming') where category_name='cryptography';");

    QSqlQuery query("select category_name from category;");
    while (query.next())
        qDebug(query.value(0).toString().toStdString().c_str());

}

void Db::createDB() {

    a_db.setDatabaseName(":memory:");
    bool ok = a_db.open();

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

        a_db.exec(create_category);
        a_db.exec(create_link);
        a_db.exec(create_keyword);
        a_db.exec(create_link_keyword);
        a_saved = false;

    } else {
        ; //could not open db. throw error
    }

}
