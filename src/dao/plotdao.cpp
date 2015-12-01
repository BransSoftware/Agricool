#include "src/dao/plotdao.h"

PlotDao::PlotDao(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setTable("Plot");
    setEditStrategy(QSqlTableModel::OnRowChange);
    QSqlTableModel::select();
}

QList<Plot*> PlotDao::getAll()
{
    QList<Plot*> plots;
    QSqlTableModel::select();

    for(int i=0; i < rowCount(); i++)
    {
        Plot *plot = new Plot(record(i).value(0).toInt(), // id
                  record(i).value(1).toString(), // name
                  record(i).value(2).toDouble(), // surface
                  record(i).value(3).toBool(), // isOwned
                  record(i).value(4).toInt(), // rent
                  record(i).value(5).toString(), // comment
                  static_cast<SubjectiveQuality>(record(i).value(6).toInt()), // soil quality
                  static_cast<SubjectiveQuality>(record(i).value(7).toInt()), // waterDrainage
                  static_cast<SubjectiveFrequency>(record(i).value(8).toInt()), // rocksQuantity
                  static_cast<SubjectiveFrequency>(record(i).value(9).toInt()), // animalDamageRisks
                  static_cast<SubjectiveFrequency>(record(i).value(10).toInt()), // climateDamageRisks
                  this);
        plots.append(plot);
    }

    return plots;
}

Plot* PlotDao::get(int id)
{
    query().exec(QString("SELECT * FROM " + tableName() + " WHERE plotID = %1").arg(id));

    if (query().first())
    {
        return new Plot(query().value(0).toInt(), // id
            query().value(1).toString(), // name
            query().value(2).toDouble(), // surface
            query().value(3).toBool(), // isOwned
            query().value(4).toInt(), // rent
            query().value(5).toString(), // comment
            static_cast<SubjectiveQuality>(query().value(6).toInt()), // soil quality
            static_cast<SubjectiveQuality>(query().value(7).toInt()), // waterDrainage
            static_cast<SubjectiveFrequency>(query().value(8).toInt()), // rocksQuantity
            static_cast<SubjectiveFrequency>(query().value(9).toInt()), // animalDamageRisks
            static_cast<SubjectiveFrequency>(query().value(10).toInt()), // climateDamageRisks
            this);
    }
    return NULL;
}

void PlotDao::add(Plot plot)
{

}

void PlotDao::update(Plot plot)
{

}

void PlotDao::remove(int id)
{
    QString req = QString("DELETE FROM " + tableName() + " WHERE plotID = %1").arg(id);
    query().exec(req);
}

void PlotDao::removeAll()
{
    query().exec("DELETE FROM " + tableName());
}
