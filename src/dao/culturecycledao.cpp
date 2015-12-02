#include "src/dao/culturecycledao.h"

CultureCycleDao::CultureCycleDao(QObject * parent, QSqlDatabase db)
    : DaoBase<CultureCycle>(parent, db)
{
    setTable("CultureCycle");
}

CultureCycle* CultureCycleDao::fillFromDb(QSqlRecord record)
{
    Plot* plot = bddService->getDao<PlotDao>()->get(record.value(1).toInt());

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
