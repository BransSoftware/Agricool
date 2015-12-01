#include "service/bddService.h"
#include "ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Init service
    BddService bddService;

    // Init UI
    MainWindow w(&bddService);
    w.show();

    return a.exec();
}
