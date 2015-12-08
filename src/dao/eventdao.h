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
    void postGet(Event* model);
    void postAdd(Event* model);
    void postUpdate(Event* model);
    void postDelete(Event* model);
private:
    Event* createFromDb(QSqlRecord record, CultureCycle* cycle);
};

#endif // EVENTDAO_H
