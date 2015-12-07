#include "daofactory.h"
#include "src/dao/plotdao.h"

DaoFactory::DaoFactory(QObject * parent, QSqlDatabase db)
    : QObject(parent)
{
    DbService *dbService = dynamic_cast<DbService*>(parent);
    models.append(new PlotDao(dbService, db));
    models.append(new CultureCycleDao(dbService, db));
    models.append(new EventDao(dbService, db));
    models.append(new EventDao(dbService, db));
    models.append(new HarvestDao(dbService, db));
    models.append(new OperationDao(dbService, db));
    models.append(new ProductDao(dbService, db));
    models.append(new ProductUsageDao(dbService, db));
    models.append(new ToolDao(dbService, db));
    models.append(new ToolUsageDao(dbService, db));
}

