#include "bddService.h"

BddService::BddService(QObject *parent) : QObject(parent)
{    
    QFileInfo dbPath( QFileInfo(QCoreApplication::applicationFilePath()).absolutePath() + "/db.sqlite");
    bool createSchema = !dbPath.exists();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath.absoluteFilePath());
    db.setConnectOptions("QSQLITE_BUSY_TIMEOUT");
    if (!db.open())
    {
        qDebug() << db.lastError();
    }

    //if (createSchema)
    {
        this->createSchema();
    }

    models.append(new PlotDao(this, db));
    models.append(new CultureCycleDao(this, db));
}

BddService::~BddService()
{
    db.close();
}

void BddService::createSchema()
{
    qDebug() << "Create schema";

    // Plot Table
    db.exec(QString("CREATE TABLE `Plot` ("
            "`plotID`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,"
            "`name`	TEXT NOT NULL,"
            "`size`	REAL,"
            "`isOwned`	INTEGER DEFAULT 1,"
            "`yearlyRent`	REAL,"
            "`comment`	TEXT,"
            "`soilQuality`	INTEGER DEFAULT 1,"
            "`waterDrainage`	INTEGER DEFAULT 1,"
            "`rocksQuantity`	INTEGER DEFAULT 0,"
            "`animalDamageRisks`	INTEGER DEFAULT 0,"
            "`climateDamageRisks`	INTEGER DEFAULT 0)"));
    db.exec("INSERT INTO `Plot`(`plotID`,`name`,`size`,`yearlyRent`,`comment`) VALUES (1,'Plot1',NULL,NULL,NULL);");
    db.exec("INSERT INTO `Plot`(`plotID`,`name`,`size`,`yearlyRent`,`comment`) VALUES (2,'Plot2',NULL,NULL,NULL);");
    db.exec("INSERT INTO `Plot`(`plotID`,`name`,`size`,`yearlyRent`,`comment`) VALUES (3,'Plot3',NULL,NULL,NULL);");

    // CultureCycle Table
    db.exec(QString("CREATE TABLE `CultureCycle` ("
            "`cultureCycleID`	INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE,"
            "`name`	TEXT NOT NULL)"));
    db.exec("INSERT INTO `CultureCycle`(`cultureCycleID`,`name`) VALUES (1,'CultureCycle1');");
}
