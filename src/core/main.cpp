#include "src/service/dbService.h"
#include "src/ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resources);
    QApplication a(argc, argv);

    // Init service
    DbService dbservice;

    // Init UI
    MainWindow w(&dbservice);
    w.show();
    //w.testAnimation();

    return a.exec();
}
