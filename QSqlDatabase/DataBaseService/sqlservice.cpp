#include "sqlservice.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

SqlService::SqlService()
{

}

QSqlDatabase SqlService::GetSqlDatabase()
{

    static QString dataBaseName = "MyDataBase.db";
    static QString connectName = "TableDataBase";
    QSqlDatabase database;

    if (QSqlDatabase::contains(connectName))
    {
        database = QSqlDatabase::database(connectName);
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE", connectName);
        database.setDatabaseName(dataBaseName);
    }

    return database;
}

QSqlQuery SqlService::Exe(QString sql)
{
    QSqlQuery sqlQuery;
    static QSqlDatabase database = GetSqlDatabase();
    if(!database.open())
    {
        qDebug() << "SQL Error : Database open failed!";
        return sqlQuery;
    }

    sqlQuery.prepare(sql);
    if(!sqlQuery.exec())
    {
        qDebug() << "Sql Error : " << sqlQuery.lastError();
        qDebug() << "Sql : " << sql;
    }
    return sqlQuery;
}
