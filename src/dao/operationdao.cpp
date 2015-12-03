#include "operationdao.h"

OperationDao::OperationDao(DbService * parent, QSqlDatabase db)
    : DaoBase<Operation>(parent, db)
{
    setTable("Operation");
}

Operation* OperationDao::fillFromDb(QSqlRecord record)
{
    //return new Operation(record.value(1));
    return NULL;
}
