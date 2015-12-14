#include "harvestdao.h"

HarvestDao::HarvestDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Harvest>(parent, db)
{
    setTable("Harvest");
}

Harvest* HarvestDao::createFromDb(QSqlRecord record)
{
    return createFromDb(record);
}

Harvest* HarvestDao::createFromDb(QSqlRecord record, CultureCycle* cycle)
{
    if (cycle == NULL)
    {
        cycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    }

    return new Harvest(record.value(0).toInt(), // id
        cycle, // culture cycle
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
    if (!model->getPlantName().isEmpty())
    {
        fields["harvestProduct"] = "'" + model->getPlantName() + "'";
    }
    fields["harvestQuantity"] = QString::number(model->getQuantity());
    fields["incomePerQuantityUnit"] = QString::number(model->getIncomePerQuantityUnit());
    fields["quantityUnit"] = QString::number(static_cast<int>(model->getQuantityUnit()));
    if (!model->getQualityComment().isEmpty())
    {
        fields["qualityComment"] = "'" + model->getQualityComment() + "'";
    }

    return "harvestID";
}

QList<Harvest*> HarvestDao::getByCultureCycle(CultureCycle* cycle)
{
    QList<Harvest*> harvests;
    QString req = QString("SELECT * FROM " + tableName() + " WHERE cycleID=:id");
    qDebug() << "HarvestDao::getByCultureCycle: " << req;

    QSqlQuery q(database());
    q.prepare(req);
    q.bindValue(":id", cycle->getCycleID());
    if (!q.exec())
    {
        qWarning() << q.lastError();
    }

    while (q.next())
    {
        Harvest* harvest = createFromDb(q.record(), cycle);
        harvests.append(harvest);
    }

    return harvests;
}
