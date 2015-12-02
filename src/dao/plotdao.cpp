#include "src/dao/plotdao.h"

PlotDao::PlotDao(QObject *parent, QSqlDatabase db)
    : DaoBase<Plot>(parent, db)
{
    setTable("Plot");
}

Plot* PlotDao::fillFromDb(QSqlRecord record)
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
