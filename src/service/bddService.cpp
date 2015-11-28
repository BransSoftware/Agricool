#include "bddService.h"

BddService::BddService()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QFileInfo( QCoreApplication::applicationFilePath() ).absolutePath() + "/bdd.sqlite");
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

    while (query.next())
    {
        qDebug() << "Row: " << query.value(1).toString();
    }
}
