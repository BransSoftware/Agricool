#ifndef CULTURECYCLEDAO_H
#define CULTURECYCLEDAO_H

#include "src/dao/plotdao.h"

class CultureCycleDao : public QSqlTableModel
{
    Q_OBJECT

public:
    CultureCycleDao(QObject * parent, QSqlDatabase db);
    QList<CultureCycle*> getAll();
    CultureCycle* get(int id);
    void add(CultureCycle cycle);
    void update(CultureCycle cycle);
    void remove(int id);
    void removeAll();

private:

    BddService* bddService;
};

#endif // CULTURECYCLEDAO_H
