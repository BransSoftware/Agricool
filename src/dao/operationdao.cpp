#include "operationdao.h"

OperationDao::OperationDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Operation>(parent, db)
{
    setTable("Operation");
}

Operation* OperationDao::fillFromDb(QSqlRecord record)
{
    /*CultureCycle* cultureCycle = dbService->getDao<CultureCycleDao>()->get(record.value(1).toInt());
    
    QDateTime date;
    date.setTime_t(record.value(3).toUInt());
    
    return new Operation(record.value(0).toInt(), //id
        cultureCycle, // culture cycle
        record.value(2).toString(), // name
        date, // date
        record.value(4).toInt(), // duration
        record.value(5).toInt(), // employee work hour
        static_cast<OperationType>(record.value(6).toInt()), // quantity unit
        record.value(7).toString() // comment
    );*/
    return NULL;
}
