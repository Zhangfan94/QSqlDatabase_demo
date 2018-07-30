#ifndef SQLSERVICE_H
#define SQLSERVICE_H

#include <QSqlDatabase>
#include <QString>

class SqlService
{
public:
    SqlService();
    static QSqlDatabase GetSqlDatabase();
    static QSqlQuery Exe(QString sql);
};

#endif // SQLSERVICE_H
