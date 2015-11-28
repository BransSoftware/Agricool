#include "bddService.h"

BddService::BddService()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("bdd.sqlite");
    //db.setConnectOptions("QSQLITE_BUSY_TIMEOUT");
    if (!db.open())
    {
        qDebug() << db.lastError();
    }
    else
    {
        executeQuery("SELECT * FROM Plot");
    }
}

BddService::~BddService()
{
    db.close();
}

void BddService::executeQuery(QString request)
{
    QSqlQuery query(db);
    query.prepare(request);
    query.exec();

    qDebug() << "Query result count: " << query.record().count();

    while (query.next())
    {
        qDebug() << query.value(1).toString();
    }
}
