#include "eventdao.h"

EventDao::EventDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Event>(parent, db)
{
    setTable("Event");
}

Event* EventDao::createFromDb(QSqlRecord record)
{
    return createFromDb(record, NULL);
}

Event* EventDao::createFromDb(QSqlRecord record, CultureCycle* cycle)
{
    if (cycle == NULL)
    {
        cycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    }

    return new Event(record.value(0).toInt(), // id
        cycle, // culture cycle
        record.value(2).toInt(), // financial income
        record.value(3).toInt(), // financial cost
        record.value(4).toInt(), // area gain
        record.value(5).toInt(), // area lost
        record.value(6).toString() // description
    );
}

QString EventDao::exportToDb(Event* model, QHash<QString, QString> &fields)
{
    fields["eventID"] = QString::number(model->getEventID());
    fields["cycleID"] = QString::number(model->getCycle()->getCycleID());
    fields["financialIncome"] = QString::number(model->getFinancialIncome());
    fields["financialCost"] = QString::number(model->getFinancialCost());
    fields["actualAreaGained"] = QString::number(model->getActualAreaGained());
    fields["actualAreaLost"] = QString::number(model->getActualAreaLos());
    if (!model->getEventDescription().isEmpty())
    {
        fields["eventDescription"] = "'" + model->getEventDescription() + "'";
    }

    return "eventID";
}

QList<Event*> EventDao::getByCultureCycle(CultureCycle* cycle)
{
    QList<Event*> events;
    QString req = QString("SELECT * FROM " + tableName() + " WHERE cycleID=:id");
    qDebug() << "EventDao::getByCultureCycle: " << req;

    QSqlQuery q(database());
    q.prepare(req);
    q.bindValue(":id", cycle->getCycleID());
    if (!q.exec())
    {
        qWarning() << q.lastError();
    }

    while (q.next())
    {
        Event* event = createFromDb(q.record(), cycle);
        events.append(event);
    }

    return events;
}
