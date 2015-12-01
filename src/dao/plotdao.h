#ifndef PLOTDAO_H
#define PLOTDAO_H

#include <QtSql/QtSql>
#include "src/core/plot.h"
#include "src/dao/culturecycledao.h"

class PlotDao : public QSqlTableModel
{
    Q_OBJECT

public:
    PlotDao(QObject * parent, QSqlDatabase db);
    QList<Plot*> getAll();
};

#endif // PLOTDAO_H
