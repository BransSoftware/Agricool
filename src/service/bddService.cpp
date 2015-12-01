#include "src/service/bddService.h"

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

    // ToolUsage table
    db.exec(QString("CREATE TABLE `ToolUsage` ("
    "	`toolUsageID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`operationID`	INTEGER NOT NULL,"
    "	`toolID`	INTEGER NOT NULL,"
    "	`toolUsageDuration`	REAL,"
    "	`toolUsageDate`	INTEGER, "
    "	FOREIGN KEY(`operationID`) REFERENCES `Operation`,"
    "	FOREIGN KEY(`toolID`) REFERENCES Tool "
    ");"));
    
    // Tool table
    db.exec(QString("CREATE TABLE `Tool` ("
    "	`toolID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`toolName`	TEXT NOT NULL,"
    "	`costPerHour`	REAL,"
    "	`toolType`	TEXT"
    ");"));
    
    // ProductUsage table
    db.exec(QString("CREATE TABLE `ProductUsage` ("
    "	`productUsageID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`operationID`	INTEGER NOT NULL,"
    "	`productID`	INTEGER NOT NULL,"
    "	`productQuantities`	REAL,"
    "	`productUsageDate`	INTEGER,"
    "	FOREIGN KEY(`operationID`) REFERENCES `Operation`,"
    "	FOREIGN KEY(`productID`) REFERENCES Product"
    ");"));
    
    // Product table
    db.exec(QString("CREATE TABLE `Product` ("
    "	`productID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`productName`	TEXT NOT NULL,"
    "	`quantityUnitSymbol`	TEXT,"
    "	`pricePerQuantityUnit`	REAL, "
    "	`productType`	TEXT"
    ");"));
    
    // Plot table
    db.exec(QString("CREATE TABLE `Plot` ("
    "	`plotID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`name`	TEXT NOT NULL,"
    "	`size`	REAL,"
    "	`isOwned`	INTEGER,"
    "	`yearlyRent`	REAL,"
    "	`comment`	TEXT,"
    "	`soilQuality`	INTEGER DEFAULT 0,"
    "	`waterDrainage`	INTEGER DEFAULT 0,"
    "	`rocksQuantity`	INTEGER DEFAULT 0,"
    "	`animalDamageRisks`	INTEGER DEFAULT 0,"
    "	`climateDamageRisks`	INTEGER DEFAULT 0"
    ");"));
    
    // Operation table
    db.exec(QString("CREATE TABLE `Operation` ("
    "	`operationID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`cycleID`	INTEGER NOT NULL,"
    "	`operationDate`	INTEGER,"
    "	`duration`	REAL,"
    "	`employeeWorkHourCost`	REAL,"
    "	`operationType`	INTEGER NOT NULL,"
    "	`openComment`	TEXT,"
    "	FOREIGN KEY(`cycleID`) REFERENCES CultureCycle"
    ");"));
    
    // Harvest table
    db.exec(QString("CREATE TABLE `Harvest` ( "
    "	`harvestID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`cycleID`	INTEGER NOT NULL,"
    "	`harvestProduct`	TEXT,"
    "	`harvestQuantity`	INTEGER,"
    "	`quantityUnitSymbol`	TEXT,"
    "	`pricePerQuantity`	REAL,"
    "	`qualityComment`	TEXT,"
    "	FOREIGN KEY(`cycleID`) REFERENCES CultureCycle"
    ");"));
    
    // Event table
    db.exec(QString("CREATE TABLE `Event` ("
    "	`eventID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`cycleID`	INTEGER NOT NULL,"
    "	`financialIncome`	REAL,"
    "	`financialCost`	REAL,"
    "	`actualAreaGained`	REAL,"
    "	`actualAreaLost`	REAL,"
    "	`eventDescription`	TEXT,"
    "	FOREIGN KEY(`cycleID`) REFERENCES CultureCycle"
    ");"));
    
    // CultureCycle table
    db.exec(QString("CREATE TABLE `CultureCycle` ("
    "	`cycleID`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
    "	`plotID`	INTEGER NOT NULL,"
    "	`startDate`	INTEGER,"
    "	`endDate`	INTEGER,"
    "	`isComplete`	INTEGER,"
    "	`estimatedCost`	REAL,"
    "	`estimatedIncome`	REAL,"
    "	`openComment`	TEXT,"
    "	FOREIGN KEY(`plotID`) REFERENCES Plot"
    ");"));
}
