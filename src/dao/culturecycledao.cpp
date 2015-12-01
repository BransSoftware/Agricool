#include "src/dao/culturecycledao.h"

CultureCycleDao::CultureCycleDao(QObject * parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setTable("CultureCycle");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

QList<CultureCycle*> CultureCycleDao::getAll()
{
    QList<CultureCycle*> cultureCycles;
    QSqlTableModel::select();

    for(int i=0; i < rowCount(); i++)
    {
        /*int id, Plot* p, QString name = QString (tr("Unknown Cycle")),
         *  double area = 0, QDateTime startD = QDateTime::currentDateTime(),
         * QDateTime endD = QDateTime(), \
            bool complete = false, QString com = QString(tr("")),
            int estimatedC = 0, int estimatedI = 0*/

        CultureCycle *cultureCycle = new CultureCycle(
                    record(i).value(0).toInt(), // id
                    NULL, // <-- Attention, le Plot *p sert aussi de parent au CultureCycle. Si tu mets NULL, tu dois détruire l'objet toi-même
                    record(i).value(1).toString() // name
                  );

        cultureCycles.append(cultureCycle);
    }

    return cultureCycles;
}
