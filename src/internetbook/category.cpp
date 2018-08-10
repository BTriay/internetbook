#include "category.h"

Category::Category(QString name) {
    a_layoutMain = new QVBoxLayout();
    a_lblName = new QLabel(name);//, a_layoutMain);
    a_layoutMain->addWidget(a_lblName);

    //this->setLayout(a_layoutMain);
}

Category::~Category() {
    delete a_lblName;
    delete a_layoutMain;
}
