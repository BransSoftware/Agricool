#include "bddService.h"

BddService::BddService(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QFileInfo( QCoreApplication::applicationFilePath() ).absolutePath() + "/bdd.sqlite");
    db.setConnectOptions("QSQLITE_BUSY_TIMEOUT");
    if (!db.open())
    {
        qDebug() << db.lastError();
    }

    models.append(new PlotModel(this, db));
}

BddService::~BddService()
{
    db.close();
}
