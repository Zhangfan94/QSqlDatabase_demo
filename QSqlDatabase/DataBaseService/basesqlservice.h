#ifndef BASESQLSERVICE_H
#define BASESQLSERVICE_H

#include "sqlservice.h"

template <class T>
class BaseSqlService : SqlService
{
public:
    BaseSqlService()
    {

    }

    void GetRecord(QList<T> &list)
    {
        QString sql = "select" + keyName + "from" + tableName;

        QSqlQuery sqlQuery;
        sqlQuery = Exe(sqlQuery);
        setMode(sqlQuery);
    }

    void SaveRecord(QList<T> &list)
    {

    }

    virtual void setMode(QSqlQuery sqlQuery) = 0;
    virtual void GetMode() =  0;

public:
    QString tableName;
    QString keyName;
};

#endif // BASESQLSERVICE_H
