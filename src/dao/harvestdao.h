#ifndef HARVESTDAO_H
#define HARVESTDAO_H

#include "src/dao/plotdao.h"

class HarvestDao : public DaoBase<Harvest>
{

public:
    HarvestDao(DbService * parent, QSqlDatabase db);
    QList<Harvest*> getByCultureCycle(CultureCycle* cycle);

protected:
    Harvest* createFromDb(QSqlRecord record);
    QString exportToDb(Harvest* model, QHash<QString, QString> &fields);

private:
    Harvest* createFromDb(QSqlRecord record, CultureCycle* cycle);
};

#endif // HARVESTDAO_H
