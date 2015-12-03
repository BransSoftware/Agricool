#ifndef OPERATIONDAO_H
#define OPERATIONDAO_H

#include "src/dao/plotdao.h"

class OperationDao : public DaoBase<Operation>
{
public:
    OperationDao(DbService * parent, QSqlDatabase db);
    Operation* createFromDb(QSqlRecord record);
    QString exportToDb(Operation* model, QHash<QString, QString> &fields);
};

#endif // OPERATIONDAO_H
