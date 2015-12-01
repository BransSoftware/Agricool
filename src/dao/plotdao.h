#ifndef PLOTDAO_H
#define PLOTDAO_H

#include <QtSql/QtSql>
#include "src/service/bddService.h"
#include "src/core/plot.h"
#include "src/dao/culturecycledao.h"

class PlotDao : public QSqlTableModel
{
    Q_OBJECT

public:
    PlotDao(QObject * parent, QSqlDatabase db);
    QList<Plot*> getAll();
    Plot* get(int id);
    void add(Plot plot);
    void update(Plot plot);
    void remove(int id);
    void removeAll();
};

#endif // PLOTDAO_H
