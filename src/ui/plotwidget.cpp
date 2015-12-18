#include "src/ui/plotwidget.h"
#include "src/dao/plotdao.h"


PlotWidget::PlotWidget(DbService *d, QWidget *parent) :
    QWidget(parent)
{
    this->setStyleSheet("background-color: white;");
    db = d;

    addNewPlotB = new QPushButton(QIcon(":/resources/icons/add.png"), tr("Ajouter une parcelle"), this);
    connect(addNewPlotB, SIGNAL(clicked()), this, SLOT(addNewPlot()));

    QVBoxLayout* lay = new QVBoxLayout(this);
    lay->addWidget(addNewPlotB);
    setLayout(lay);

    update();

}

void PlotWidget::update()
{
    QVBoxLayout* lay = static_cast<QVBoxLayout*>(this->layout());
    lay->removeWidget(addNewPlotB);

    QList<Plot*> pList = db->getDao<PlotDao>()->getAll();

    foreach(Plot* p, pList)
    {

        bool isAlreadyVisible= false;
        foreach (PlotBanner* pb, banners)
        {
            if(pb->getPlot() == p)
                isAlreadyVisible=true;
        }

        if(!isAlreadyVisible)
        {
            banners.append(new PlotBanner(p,this));
            lay->addWidget(banners.last(),0,Qt::AlignTop);
        }
    }
    lay->addSpacing(20);
    lay->addWidget(addNewPlotB,0,Qt::AlignTop);
    lay->addStretch(100);
    setLayout(lay);
}

void PlotWidget::addNewPlot()
{

}
