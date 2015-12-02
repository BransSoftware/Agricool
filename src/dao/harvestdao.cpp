#include "harvestdao.h"

HarvestDao::HarvestDao(QObject * parent, QSqlDatabase db)
    : DaoBase<Harvest>(parent, db)
{
    setTable("Harvest");
}

Harvest* HarvestDao::fillFromDb(QSqlRecord record)
{
    //return new Harvest(record.value(1));
    return NULL;
}
