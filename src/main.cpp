#include <QApplication>

#include "./internetbook/mainwindow.h"
#include "config/config.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    settings::test();
    //MainWindow w;
    //w.show();
    //w.update();
    return app.exec();
}
