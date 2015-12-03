#include "harvestdao.h"

HarvestDao::HarvestDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Harvest>(parent, db)
{
    setTable("Harvest");
}

Harvest* HarvestDao::fillFromDb(QSqlRecord record)
{
    CultureCycle* cultureCycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    return new Harvest(record.value(0).toInt(), // id
        
    );
    return NULL;
}
