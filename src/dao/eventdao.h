#ifndef EVENTDAO_H
#define EVENTDAO_H

#include "src/dao/plotdao.h"

class EventDao : public DaoBase<Event>
{
public:
    EventDao(DbService * parent, QSqlDatabase db);

    QList<Event*> getByCultureCycle(CultureCycle* cycle);

protected:
    Event* createFromDb(QSqlRecord record);
    QString exportToDb(Event* model, QHash<QString, QString> &fields);

private:
    Event* createFromDb(QSqlRecord record, CultureCycle* cycle);
};

#endif // EVENTDAO_H
