#include "src/dao/culturecycledao.h"

CultureCycleDao::CultureCycleDao(QObject * parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    bddService = dynamic_cast<BddService*>(parent);
    setTable("CultureCycle");
    setEditStrategy(QSqlTableModel::OnRowChange);
}

QList<CultureCycle*> CultureCycleDao::getAll()
{
    QList<CultureCycle*> cultureCycles;
    QSqlTableModel::select();

    for(int i=0; i < rowCount(); i++)
    {
        Plot* plot = bddService->getDao<PlotDao>()->get(record(i).value(1).toInt());

        QDateTime startDate;
        startDate.setTime_t(record(i).value(4).toUInt());

        QDateTime endDate;
        endDate.setTime_t(record(i).value(5).toUInt());

        CultureCycle *cultureCycle = new CultureCycle(
                    record(i).value(0).toInt(), // id
                    plot, // associated plot
                    record(i).value(2).toString(), // name
                    record(i).value(3).toDouble(), // area
                    startDate, // start date
                    endDate, // end date
                    record(i).value(6).toBool(), // is complete
                    record(i).value(9).toString(), // comment
                    record(i).value(7).toDouble(), // estimated cost
                    record(i).value(8).toDouble() // estimated income
                  );

        cultureCycles.append(cultureCycle);        
    }

    return cultureCycles;
}

CultureCycle* CultureCycleDao::get(int id)
{
    query().exec(QString("SELECT * FROM " + tableName() + " WHERE plotID = %1").arg(id));

    if (query().first())
    {
        Plot* plot = bddService->getDao<PlotDao>()->get(query().value(1).toInt());

        QDateTime startDate;
        startDate.setTime_t(query().value(4).toUInt());

        QDateTime endDate;
        endDate.setTime_t(query().value(5).toUInt());

        return new CultureCycle(
            query().value(0).toInt(), // id
            plot, // associated plot
            query().value(2).toString(), // name
            query().value(3).toDouble(), // area
            startDate, // start date
            endDate, // end date
            query().value(6).toBool(), // is complete
            query().value(9).toString(), // comment
            query().value(7).toDouble(), // estimated cost
            query().value(8).toDouble() // estimated income
          );
    }

    return NULL;
}

void CultureCycleDao::add(CultureCycle cycle)
{

}

void CultureCycleDao::update(CultureCycle cycle)
{

}

void CultureCycleDao::remove(int id)
{
    QString req = QString("DELETE FROM " + tableName() + " WHERE cycleID = %1").arg(id);
    query().exec(req);
}

void CultureCycleDao::removeAll()
{
    query().exec("DELETE FROM " + tableName());
}
