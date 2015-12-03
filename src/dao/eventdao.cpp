#include "eventdao.h"

EventDao::EventDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Event>(parent, db)
{
    setTable("Event");
}

Event* EventDao::fillFromDb(QSqlRecord record)
{
    /*CultureCycle* cultureCycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    
    return new Event(record.value(0).toInt(), // id
        cultureCycle, // culture cycle
        record.value(2).toInt(), // financial income
        record.value(3).toInt(), // financial cost
        record.value(4).toInt(), // area gain
        record.value(5).toInt(), // area lost
        record.value(6).toString(), // description
    );*/
    
    return NULL;
}
