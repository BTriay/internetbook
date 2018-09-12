#ifndef DB_H
#define DB_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>

#include <fstream>

class Db {

private:
    QSqlDatabase a_db;
    bool a_saved;

    void createDB();

    void test();

public:
    Db(QString db_name = QString());
    ~Db();

    bool saved() const { return a_saved; }

};

#endif // DB_H
