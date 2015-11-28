#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QScrollArea>
#include <src/bannerwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
