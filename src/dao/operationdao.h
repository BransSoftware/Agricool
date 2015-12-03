#ifndef OPERATIONDAO_H
#define OPERATIONDAO_H

#include "src/dao/plotdao.h"

class OperationDao : public DaoBase<Operation>
{
public:
    OperationDao(DbService * parent, QSqlDatabase db);
    Operation* fillFromDb(QSqlRecord record);
};

#endif // OPERATIONDAO_H
