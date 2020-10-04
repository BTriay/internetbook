#include <QApplication>

#include "config/config.h"
#include "config/logger.h"

#include "entity/Link.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Logger::initFromConfig("logconfig.ini");

    Link l("link name", "link url");
    l.AddKeyword("huge");

    //MainWindow w;
    //w.show();
    //w.update();    
//    return app.exec();
    LOG_INFO("Exiting");
}
