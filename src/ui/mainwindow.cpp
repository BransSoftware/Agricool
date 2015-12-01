#include "src/ui/mainwindow.h"

MainWindow::MainWindow(BddService* bddService, QWidget *parent)
    : QMainWindow(parent)
{
    // Get plot from database
    QList<Plot*> allPlots = bddService->getDao<PlotDao>()->getAll();
    for(Plot* plot : allPlots)
    {
        qDebug() << plot->getPlotName();
    }

    QList<CultureCycle*> allCultureCycles = bddService->getDao<CultureCycleDao>()->getAll();
    for(CultureCycle* cultureCycle : allCultureCycles)
    {
        qDebug() << cultureCycle->getCycleName();
    }

    //checkUser();
    //initDB();
    initMenus();
    initToolbar();
    initPlots();
    //initTools();
    //initConsumables();
    //loadDB();
    //loadPreferences();
}

void MainWindow::initMenus(){

    mBar = this->menuBar();
    fileMenu = mBar->addMenu(tr("&File"));
    fileMenu->addAction(tr("&Quit"));
    optionMenu = mBar->addMenu(tr("&Options"));
    optionMenu->addAction(tr("P&references"));
    helpMenu = mBar->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About"));

}

void MainWindow::initToolbar(){

    toolbar = this->addToolBar(tr("MainToolBar"));
    toolbar->addAction(QIcon(":/resources/icons/plot.png"), tr("&Plots"));
    toolbar->addAction(QIcon(":/resources/icons/tractor.png"), tr("&Tools"));
    toolbar->addAction(QIcon(":/resources/icons/bag.png"), tr("&Consumables"));
    toolbar->addAction(QIcon(":/resources/icons/barchart.png"), tr("C&harts"));
    toolbar->setMovable(false);
    toolbar->setIconSize(QSize(96,96));

}

void MainWindow::initPlots(){

    plotWidget = new QWidget(this);
    plotWidget->setStyleSheet("background-color: white;");
    QVBoxLayout* lay = new QVBoxLayout(plotWidget);

    for(int i =0; i<10;i++)
        lay->addWidget(new BannerWidget(plotWidget),0,Qt::AlignTop);


    plotWidget->setLayout(lay);
    this->setCentralWidget(plotWidget);
    plotWidget->show();

}

MainWindow::~MainWindow()
{

}
