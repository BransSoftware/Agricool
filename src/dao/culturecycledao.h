#ifndef CULTURECYCLEDAO_H
#define CULTURECYCLEDAO_H

#include "src/dao/plotdao.h"

class CultureCycleDao : public DaoBase<CultureCycle>
{
    Q_OBJECT

public:
    CultureCycleDao(DbService * parent, QSqlDatabase db);
    QList<CultureCycle*> getByPlot(Plot* plot);

protected:
    CultureCycle* createFromDb(QSqlRecord record);
    QString exportToDb(CultureCycle* model, QHash<QString, QString> &fields);
    void postGet(CultureCycle* model);
    void postAdd(CultureCycle* model);
    void postUpdate(CultureCycle* model);
    void postDelete(CultureCycle* model);
private:
    CultureCycle* createFromDb(QSqlRecord record, Plot* plot);
};

#endif // CULTURECYCLEDAO_H
