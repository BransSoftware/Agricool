#ifndef PLOTMODEL
#define PLOTMODEL

#include <QtSql/QtSql>

class PlotModel : public QSqlTableModel
{
    Q_OBJECT
public:
    PlotModel(QObject *parent, QSqlDatabase db);
    bool select();
};

#endif // PLOTMODEL

