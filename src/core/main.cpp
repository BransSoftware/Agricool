#include "src/service/bddService.h"
#include "src/ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resources);
    QApplication a(argc, argv);

    // Init service
    BddService bddService;

    // Init UI
    MainWindow w(&bddService);
    w.show();
    //w.testAnimation();

    return a.exec();
}
