#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "src/core/plot.h"
#include "src/service/dbservice.h"
#include "src/ui/plotbanner.h"

class PlotWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlotWidget(DbService *db, QWidget *parent = 0);

private:
    QList<PlotBanner*> banners;
    DbService *db;
    QPushButton* addNewPlotB;

signals:

public slots:
    void update();
    void addNewPlot();

};

#endif // PLOTWIDGET_H
