#ifndef CULTURECYCLEDAO_H
#define CULTURECYCLEDAO_H

#include "src/dao/plotdao.h"

class CultureCycleDao : public DaoBase<CultureCycle>
{
    Q_OBJECT

public:
    CultureCycleDao(DbService * parent, QSqlDatabase db);
    CultureCycle* createFromDb(QSqlRecord record);
    QString exportToDb(CultureCycle* model, QHash<QString, QString> &fields);
};

#endif // CULTURECYCLEDAO_H
