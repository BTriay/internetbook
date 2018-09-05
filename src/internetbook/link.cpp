#include "link.h"
#include "category.h"

Link::Link(QString name, QString url, Category *parent_category) :
    BarWidget(name, parent_category) {

    a_lbl_url = new TextLabel(url);
    a_hlayout->insertWidget(2, a_lbl_url);
    a_hlayout->insertSpacing(0, parent_category->childSpace());
}

Link::~Link() {

}
