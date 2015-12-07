#include "harvestdao.h"

HarvestDao::HarvestDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Harvest>(parent, db)
{
    setTable("Harvest");
}

Harvest* HarvestDao::createFromDb(QSqlRecord record)
{
    CultureCycle* cultureCycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    
    return new Harvest(record.value(0).toInt(), // id
        cultureCycle, // culture cycle
        record.value(2).toString(), // plant name
        record.value(3).toInt(), // quantity
        record.value(4).toInt(), // income per quantity unit
        static_cast<QuantityUnit>(record.value(5).toInt()), // quantity unit
        record.value(6).toString() // comment
    );
}

QString HarvestDao::exportToDb(Harvest* model, QHash<QString, QString> &fields)
{
    fields["harvestID"] = QString::number(model->getHarvestID());
    fields["cycleID"] = QString::number(model->getCycle()->getCycleID());
    fields["harvestProduct"] = model->getPlantName();
    fields["harvestQuantity"] = QString::number(model->getQuantity());
    fields["incomePerQuantityUnit"] = QString::number(model->getIncomePerQuantityUnit());
    fields["quantityUnit"] = QString::number(static_cast<int>(model->getQuantityUnit()));
    fields["qualityComment"] = model->getQualityComment();

    return "harvestID";
}
