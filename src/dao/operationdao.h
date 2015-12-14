#ifndef OPERATIONDAO_H
#define OPERATIONDAO_H

#include "src/dao/plotdao.h"

class OperationDao : public DaoBase<Operation>
{

public:
    OperationDao(DbService * parent, QSqlDatabase db);

    QList<Operation*> getAll(bool isRecursive);
    virtual QList<Operation*> getAll();

    Operation* get(int id, bool isRecursive);
    virtual Operation* get(int id);

    QList<Operation*> getByCultureCycle(CultureCycle* cycle);

    virtual void add(Operation* model);
    virtual void update(Operation* model);
    virtual void remove(int id);
    virtual void removeAll();

protected:
    Operation* createFromDb(QSqlRecord record);
    QString exportToDb(Operation* model, QHash<QString, QString> &fields);
    void postGet(Operation* model);
    void postAdd(Operation* model);
    void postUpdate(Operation* model);
    void postRemove(Operation* model);
private:
    Operation* createFromDb(QSqlRecord record, CultureCycle* cycle);
};

#endif // OPERATIONDAO_H
