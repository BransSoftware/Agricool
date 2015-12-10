#include "src/dao/culturecycledao.h"

CultureCycleDao::CultureCycleDao(DbService * parent, QSqlDatabase db)
    : DaoBase<CultureCycle>(parent, db)
{
    setTable("CultureCycle");

}

CultureCycle* CultureCycleDao::createFromDb(QSqlRecord record)
{
    return createFromDb(record, NULL);
}

CultureCycle* CultureCycleDao::createFromDb(QSqlRecord record, Plot* plot)
{
    if (plot == NULL)
    {
        plot = dbService->getDao<PlotDao>()->get(record.value(1).toInt(), false);
    }

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

QList<CultureCycle*> CultureCycleDao::getByPlot(Plot* plot)
{
    QList<CultureCycle*> cultureCycles;
    QString req = QString("SELECT * FROM " + tableName() + " WHERE plotID=:id");
    qDebug() << "CultureCycleDao::getByPlotId: " << req;

    QSqlQuery q(database());
    q.prepare(req);
    q.bindValue(":id", plot->getPlotID());
    if (!q.exec())
    {
        qWarning() << q.lastError();
    }

    while (q.next())
    {
        CultureCycle* cycle = createFromDb(q.record(), plot);
        postGet(cycle);
        cultureCycles.append(cycle);
    }

    return cultureCycles;
}

QList<CultureCycle*> CultureCycleDao::getAll()
{
    return getAll(true);
}

QList<CultureCycle*> CultureCycleDao::getAll(bool isRecursive)
{
    QList<CultureCycle*> models = DaoBase::getAll();
    if (isRecursive)
    {
        for (CultureCycle* model : models)
        {
            postGet(model);
        }
    }
    return models;
}

CultureCycle* CultureCycleDao::get(int id)
{
    return get(id, true);
}

CultureCycle* CultureCycleDao::get(int id, bool isRecursive)
{
    CultureCycle* model = DaoBase::get(id);

    if (isRecursive)
    {
        postGet(model);
    }

    return model;
}

void CultureCycleDao::remove(int id)
{
    CultureCycle* cycle = get(id, false);

    postRemove(cycle);
    DaoBase::remove(cycle->getCycleID());
}

void CultureCycleDao::removeAll()
{
    QList<CultureCycle*> cycles = getAll(false);

    for(CultureCycle* cycle : cycles)
    {
        postRemove(cycle);
    }

    DaoBase::removeAll();
}

void CultureCycleDao::postGet(CultureCycle* model)
{
    model->setEvents(dbService->getDao<EventDao>()->getByCultureCycle(model));
    model->setHarvests(dbService->getDao<HarvestDao>()->getByCultureCycle(model));
    model->setOperations(dbService->getDao<OperationDao>()->getByCultureCycle(model));
}

void CultureCycleDao::postRemove(CultureCycle* model)
{
    for (Event* event : model->getEvents())
    {
        dbService->getDao<EventDao>()->remove(event->getEventID());
    }
    for (Harvest* harvest : model->getHarvests())
    {
        dbService->getDao<HarvestDao>()->remove(harvest->getHarvestID());
    }
    for (Operation* operation : model->getOperations())
    {
        dbService->getDao<OperationDao>()->remove(operation->getOperationID());
    }
}
