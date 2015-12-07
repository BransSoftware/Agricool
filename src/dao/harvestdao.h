#ifndef HARVESTDAO_H
#define HARVESTDAO_H

#include "src/dao/plotdao.h"

class HarvestDao : public DaoBase<Harvest>
{
public:
    HarvestDao(DbService * parent, QSqlDatabase db);
    Harvest* createFromDb(QSqlRecord record);
    QString exportToDb(Harvest* model, QHash<QString, QString> &fields);
};

#endif // HARVESTDAO_H
