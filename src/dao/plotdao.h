#ifndef PLOTDAO_H
#define PLOTDAO_H

#include "src/dao/daobase.h"
#include "src/core/plot.h"
#include "src/dao/culturecycledao.h"

class PlotDao : public DaoBase<Plot>
{
    Q_OBJECT

public:
    PlotDao(QObject * parent, QSqlDatabase db);
    Plot* fillFromDb(QSqlRecord record);
};

#endif // PLOTDAO_H
