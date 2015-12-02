#ifndef HARVESTDAO_H
#define HARVESTDAO_H

#include "src/dao/plotdao.h"

class HarvestDao : public DaoBase<Harvest>
{
public:
    HarvestDao(QObject * parent, QSqlDatabase db);
    Harvest* fillFromDb(QSqlRecord record);
};

#endif // HARVESTDAO_H
