#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QScrollArea>
#include "src/ui/plotbanner.h"
#include "src/service/dbService.h"
#include "src/ui/plotwidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DbService *dbService, QWidget *parent = 0);
    ~MainWindow();

    void testAnimation();

private:
    QMenuBar* mBar;

    void initMenus();
    void initToolbar();
    void initPlots();

    QMenu* fileMenu;
    QMenu* optionMenu;
    QMenu* helpMenu;

    QToolBar* toolbar;
    PlotWidget* plotWidget;
    QWidget* farmingCycleWidget;
    QWidget* toolsWidget;
    QWidget* consumbaleWidget;
    QWidget* chartWidget;

    DbService *db;

};

#endif // MAINWINDOW_H
