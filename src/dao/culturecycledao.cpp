#include "src/dao/culturecycledao.h"

CultureCycleDao::CultureCycleDao(DbService * parent, QSqlDatabase db)
    : DaoBase<CultureCycle>(parent, db)
{
    setTable("CultureCycle");
}

CultureCycle* CultureCycleDao::createFromDb(QSqlRecord record)
{
    Plot* plot = dbService->getDao<PlotDao>()->get(record.value(1).toInt());

    QDateTime startDate;
    startDate.setTime_t(record.value(4).toUInt());

    QDateTime endDate;
    endDate.setTime_t(record.value(5).toUInt());

    return new CultureCycle(
        record.value(0).toInt(), // id
        plot, // associated plot
        record.value(2).toString(), // name
        record.value(3).toDouble(), // area
        startDate, // start date
        endDate, // end date
        record.value(6).toBool(), // is complete
        record.value(9).toString(), // comment
        record.value(7).toDouble(), // estimated cost
        record.value(8).toDouble() // estimated income
      );
}

QString CultureCycleDao::exportToDb(CultureCycle* model, QHash<QString, QString> &fields)
{
    fields["cycleID"] = QString::number(model->getCycleID());
    fields["plotID"] = QString::number(model->getCultivatedPlot()->getPlotID());
    if (!model->getCycleName().isEmpty())
    {
        fields["name"] = "'" + model->getCycleName() + "'";
    }
    fields["area"] = QString::number(model->getActualCultivatedArea());
    fields["startDate"] = QString::number(model->getStartDate().toTime_t());
    fields["endDate"] = QString::number(model->getEndDate().toTime_t());
    fields["isComplete"] = QString::number(model->getIsComplete());
    fields["estimatedCost"] = QString::number(model->getEstimatedCost());
    fields["estimatedIncome"] = QString::number(model->getEstimatedIncome());
    if (!model->getComment().isEmpty())
    {
        fields["openComment"] = "'" + model->getComment() + "'";
    }

    return "cycleID";
}
