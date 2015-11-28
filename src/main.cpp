#include "ui/mainwindow.h"
#include "service/bddService.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Init services
    new BddService();

    // Init UI
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
