#include "src/dao/plotdao.h"

PlotDao::PlotDao(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setTable("Plot");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
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
                  SubjectiveQuality::Undef,
                  SubjectiveQuality::Undef,
                  SubjectiveFrequency::none,
                  SubjectiveFrequency::none,
                  SubjectiveFrequency::none,
                  this);

        plots.append(plot);
    }

    return plots;
}
