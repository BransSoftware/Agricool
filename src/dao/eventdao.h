#ifndef EVENTDAO_H
#define EVENTDAO_H

#include "src/dao/plotdao.h"

class EventDao : public DaoBase<Event>
{
public:
    EventDao(DbService * parent, QSqlDatabase db);
    Event* createFromDb(QSqlRecord record);
    QString exportToDb(Event* model, QHash<QString, QString> &fields);
};

#endif // EVENTDAO_H
