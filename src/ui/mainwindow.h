#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QScrollArea>
#include "src/ui/bannerwidget.h"
#include "src/service/dbService.h"

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
    QWidget* plotWidget;
    QWidget* farmingCycleWidget;
    QWidget* toolsWidget;
    QWidget* consumbaleWidget;
    QWidget* chartWidget;

};

#endif // MAINWINDOW_H
