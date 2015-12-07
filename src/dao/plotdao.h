#ifndef PLOTDAO_H
#define PLOTDAO_H

#include "src/dao/daobase.h"
#include "src/core/plot.h"
#include "src/dao/culturecycledao.h"
#include "src/dao/eventdao.h"
#include "src/dao/harvestdao.h"
#include "src/dao/operationdao.h"
#include "src/dao/productdao.h"
#include "src/dao/productusagedao.h"
#include "src/dao/tooldao.h"
#include "src/dao/toolusagedao.h"

class PlotDao : public DaoBase<Plot>
{
    Q_OBJECT

public:
    PlotDao(DbService * parent, QSqlDatabase db);
    Plot* createFromDb(QSqlRecord record);
    QString exportToDb(Plot* model, QHash<QString, QString> &fields);
};

#endif // PLOTDAO_H
