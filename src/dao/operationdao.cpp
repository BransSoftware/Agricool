#include "operationdao.h"

OperationDao::OperationDao(QObject * parent, QSqlDatabase db)
    : DaoBase<Operation>(parent, db)
{
    setTable("Operation");
}

Operation* OperationDao::fillFromDb(QSqlRecord record)
{
    //return new Operation(record.value(1));
    return NULL;
}
