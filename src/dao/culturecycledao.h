#ifndef CULTURECYCLEDAO_H
#define CULTURECYCLEDAO_H

#include "src/dao/plotdao.h"

class CultureCycleDao : public DaoBase<CultureCycle>
{
    Q_OBJECT

public:
    CultureCycleDao(DbService * parent, QSqlDatabase db);
    CultureCycle* fillFromDb(QSqlRecord record);
};

#endif // CULTURECYCLEDAO_H
