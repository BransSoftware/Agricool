#ifndef OPERATIONDAO_H
#define OPERATIONDAO_H

#include "src/dao/plotdao.h"

class OperationDao : public DaoBase<Operation>
{

public:
    OperationDao(DbService * parent, QSqlDatabase db);
    QList<Operation*> getByCultureCycle(CultureCycle* cycle);

protected:
    Operation* createFromDb(QSqlRecord record);
    QString exportToDb(Operation* model, QHash<QString, QString> &fields);
    void postGet(Operation* model);
    void postAdd(Operation* model);
    void postUpdate(Operation* model);
    void postDelete(Operation* model);
private:
    Operation* createFromDb(QSqlRecord record, CultureCycle* cycle);
};

#endif // OPERATIONDAO_H
