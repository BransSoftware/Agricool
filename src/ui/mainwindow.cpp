#include "src/ui/mainwindow.h"
#include "src/dao/plotdao.h"

MainWindow::MainWindow(DbService *dbService, QWidget *parent)
    : QMainWindow(parent)
{
    db = dbService;

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

void MainWindow::testAnimation(){
    qDebug() <<"animation started";
    QPoint orig = this->pos();
    QPropertyAnimation *anim = new QPropertyAnimation(this, "pos");
    anim->setStartValue(orig);
    anim->setEndValue(orig);
    anim->setDuration(4000);
    anim->setKeyValueAt(0.25, QPoint(orig.x()+200, orig.y()));
    anim->setKeyValueAt(0.5,  QPoint(orig.x()+200, orig.y()+200));
    anim->setKeyValueAt(0.75,  QPoint(orig.x(), orig.y()+200));
    anim->setLoopCount(5);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
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

    plotWidget = new PlotWidget(db, this);
    this->setCentralWidget(plotWidget);
    plotWidget->show();

}

MainWindow::~MainWindow()
{

}
