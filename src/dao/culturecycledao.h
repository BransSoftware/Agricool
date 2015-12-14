#ifndef CULTURECYCLEDAO_H
#define CULTURECYCLEDAO_H

#include "src/dao/plotdao.h"

class CultureCycleDao : public DaoBase<CultureCycle>
{
    Q_OBJECT

public:
    CultureCycleDao(DbService * parent, QSqlDatabase db);

    QList<CultureCycle*> getAll(bool isRecursive);
    virtual QList<CultureCycle*> getAll();

    CultureCycle* get(int id, bool isRecursive);
    virtual CultureCycle* get(int id);

    QList<CultureCycle*> getByPlot(Plot* plot);

    virtual void add(CultureCycle* model);
    virtual void update(CultureCycle* model);
    virtual void remove(int id);
    virtual void removeAll();

protected:
    CultureCycle* createFromDb(QSqlRecord record);
    QString exportToDb(CultureCycle* model, QHash<QString, QString> &fields);

private:
    CultureCycle* createFromDb(QSqlRecord record, Plot* plot);
    void postGet(CultureCycle* model);
    void postAdd(CultureCycle* model);
    void postUpdate(CultureCycle* model);
    void postRemove(CultureCycle* model);
};

#endif // CULTURECYCLEDAO_H
