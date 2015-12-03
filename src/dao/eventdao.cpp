#include "eventdao.h"

EventDao::EventDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Event>(parent, db)
{
    setTable("Event");
}

Event* EventDao::fillFromDb(QSqlRecord record)
{
    //return new Event(record.value(1));
    return NULL;
}
