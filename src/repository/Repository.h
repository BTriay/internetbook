#ifndef REPOSITORY_HEADER
#define REPOSITORY_HEADER

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>

#include <fstream>

class Repository {

private:
    QSqlDatabase a_repository;

    void create_repository();

public:
    Repository(QString db_name = QString());
    ~Repository();

    void test();

};

#endif // REPOSITORY_H
