#include "config.h"

std::unique_ptr<QSettings> settings::setup_settings(){

    QCoreApplication::setOrganizationDomain(settings::organization);
    QCoreApplication::setOrganizationName(settings::website);
    QCoreApplication::setApplicationName(settings::software);

    return std::make_unique<QSettings>();
}

void settings::write(const QString key, const QString value){
    auto settings = setup_settings();
    settings->setValue(key, value);
}

void settings::write(const QString key, const int value){
    auto settings = setup_settings();
    settings->setValue(key, value);
}
