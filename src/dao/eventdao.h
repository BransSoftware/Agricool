#ifndef EVENTDAO_H
#define EVENTDAO_H

#include "src/dao/plotdao.h"

class EventDao : public DaoBase<Event>
{
public:
    EventDao(DbService * parent, QSqlDatabase db);
    Event* fillFromDb(QSqlRecord record);
};

#endif // EVENTDAO_H
