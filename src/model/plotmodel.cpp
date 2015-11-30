#include "plotmodel.h"

PlotModel::PlotModel(QObject *parent, QSqlDatabase db)
    : QSqlTableModel(parent, db)
{
    setTable("Plot");
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

bool PlotModel::select()
{
    bool res = QSqlTableModel::select();

    qDebug() << "reading record : " << record(0).value(1).toString();

    return res;
}
