#include "src/dao/plotdao.h"

PlotDao::PlotDao(DbService *parent, QSqlDatabase db)
    : DaoBase<Plot>(parent, db)
{
    setTable("Plot");
}

Plot* PlotDao::createFromDb(QSqlRecord record)
{
    return new Plot(record.value(0).toInt(), // id
        record.value(1).toString(), // name
        record.value(2).toDouble(), // surface
        record.value(3).toBool(), // isOwned
        record.value(4).toInt(), // rent
        record.value(5).toString(), // comment
        static_cast<SubjectiveQuality>(record.value(6).toInt()), // soil quality
        static_cast<SubjectiveQuality>(record.value(7).toInt()), // waterDrainage
        static_cast<SubjectiveFrequency>(record.value(8).toInt()), // rocksQuantity
        static_cast<SubjectiveFrequency>(record.value(9).toInt()), // animalDamageRisks
        static_cast<SubjectiveFrequency>(record.value(10).toInt()), // climateDamageRisks
        this);
}

QString PlotDao::exportToDb(Plot* model, QHash<QString, QString> &fields)
{
    fields["plotID"] = QString::number(model->getPlotID());
    if (!model->getPlotName().isEmpty())
    {
        fields["name"] = "'" + model->getPlotName() + "'";
    }
    fields["size"] = QString::number(model->getSize());
    fields["isOwned"] = QString::number(model->getIsOwned());
    fields["yearlyRent"] = QString::number(model->getYearlyRent());
    if (!model->getComment().isEmpty())
    {
        fields["comment"] ="'" +  model->getComment() + "'";
    }
    fields["soilQuality"] = QString::number(static_cast<int>(model->getSoilQuality()));
    fields["waterDrainage"] = QString::number(static_cast<int>(model->getWaterDrainage()));
    fields["rocksQuantity"] = QString::number(static_cast<int>(model->getRocksQuantity()));
    fields["animalDamageRisks"] = QString::number(static_cast<int>(model->getAnimalDamageRisks()));
    fields["climateDamageRisks"] = QString::number(static_cast<int>(model->getClimateDamageRisks()));

    return "plotID";
}
