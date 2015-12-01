#ifndef CULTURECYCLEDAO_H
#define CULTURECYCLEDAO_H

#include <QtSql/QtSql>
#include "src/core/culturecycle.h"

class CultureCycleDao : public QSqlTableModel
{
public:
    CultureCycleDao(QObject * parent, QSqlDatabase db);
    QList<CultureCycle*> getAll();
};

#endif // CULTURECYCLEDAO_H
