#include <QApplication>

//#include "./internetbook/mainwindow.h"
#include "config/config.h"
#include "config/logger.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Logger::initFromConfig("logconfig.ini");

    LOG_INFO("info logger test");

    //MainWindow w;
    //w.show();
    //w.update();
    return app.exec();
}
