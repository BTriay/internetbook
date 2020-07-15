#include <memory>

#include <QCoreApplication>
#include <QSettings>

namespace settings
{

const QString organization("BT");
const QString website("triay.net");
const QString software("InternetBook");

std::unique_ptr<QSettings> setup_settings();
QString read(const QString key);
void write(const QString key, const QString value);
void write(const QString key, const int value);

void test();

}
