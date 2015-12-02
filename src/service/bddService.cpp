#include "src/service/bddService.h"
#include "src/dao/culturecycledao.h"
#include "src/dao/plotdao.h"

BddService::BddService(QObject *parent) : QObject(parent)
{    
    QFileInfo dbPath( QFileInfo(QCoreApplication::applicationFilePath()).absolutePath() + "/db.sqlite");
    bool createSchema = true; //!dbPath.exists();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath.absoluteFilePath());
    db.setConnectOptions("QSQLITE_BUSY_TIMEOUT");
    if (!db.open())
    {
        qDebug() << db.lastError();
    }

    if (createSchema)
    {
        this->createSchema();
        this->createData();
    }

    models.append(new PlotDao(this, db));
    models.append(new CultureCycleDao(this, db));
    models.append(new EventDao(this, db));
    models.append(new EventDao(this, db));
    models.append(new HarvestDao(this, db));
    models.append(new OperationDao(this, db));
    models.append(new ProductDao(this, db));
    models.append(new ProductUsageDao(this, db));
    models.append(new ToolDao(this, db));
    models.append(new ToolUsageDao(this, db));
}

BddService::~BddService()
{
    db.close();
}

void BddService::createSchema()
{
    qDebug() << "Create a new schema";

    db.exec("DROP TABLE `ToolUsage`");
    db.exec("DROP TABLE `Tool`");
    db.exec("DROP TABLE `ProductUsage`");
    db.exec("DROP TABLE `Product`");
    db.exec("DROP TABLE `Plot`");
    db.exec("DROP TABLE `Operation`");
    db.exec("DROP TABLE `Harvest`");
    db.exec("DROP TABLE `Event`");
    db.exec("DROP TABLE `CultureCycle`");

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
    "   `name`	TEXT,"
    "	`area`	REAL,"
    "	`startDate`	INTEGER,"
    "	`endDate`	INTEGER,"
    "	`isComplete`	INTEGER DEFAULT 0,"
    "	`estimatedCost`	REAL,"
    "	`estimatedIncome`	REAL,"
    "	`openComment`	TEXT,"
    "	FOREIGN KEY(`plotID`) REFERENCES Plot"
    ");"));
}

void BddService::createData()
{
    qDebug() << "Create data";

    db.exec("INSERT INTO `Plot` (plotID,name,size,isOwned,yearlyRent,comment,soilQuality,waterDrainage,rocksQuantity,animalDamageRisks,climateDamageRisks) VALUES (1,'Parcelle_Routeau',4.4,1,NULL,NULL,3,0,0,0,0)");
    db.exec("INSERT INTO `CultureCycle` (cycleID,plotID,name,area,startDate,endDate,isComplete,estimatedCost,estimatedIncome,openComment) VALUES (1,1,'Culture Cycle 1',3,1449005000,NULL,0,10000.0,12000.0,NULL)");
}
