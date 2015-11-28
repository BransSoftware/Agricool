#include "ui/mainwindow.h"
#include "service/bddService.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Init services
    new BddService();

    // Init UI
    MainWindow w;
    w.show();

    return a.exec();
}
