#include "harvestdao.h"

HarvestDao::HarvestDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Harvest>(parent, db)
{
    setTable("Harvest");
}

Harvest* HarvestDao::fillFromDb(QSqlRecord record)
{
    /*CultureCycle* cultureCycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    
    return new Harvest(record.value(0).toInt(), // id
        cultureCycle, // culture cycle
        record.value(2).toString(), // plant name
        record.value(3).toInt(), // quantity
        record.value(4).toInt(), // income per quantity unit
        static_cast<QuantityUnit>(record.value(5).toInt()), // quantity unit
        record.value(6).toString() // comment
    );*/
    return NULL;
}
