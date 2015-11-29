#include "bddService.h"

BddService::BddService()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QFileInfo( QCoreApplication::applicationFilePath() ).absolutePath() + "/bdd.sqlite");
    db.setConnectOptions("QSQLITE_BUSY_TIMEOUT");
    if (!db.open())
    {
        qDebug() << db.lastError();
    }

    models.append(new PlotModel(new QObject(), db));
}

BddService::~BddService()
{
    db.close();
    db = NULL;
}
