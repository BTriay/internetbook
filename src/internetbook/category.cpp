#include "category.h"

Category::Category(const QString& name,
                   Category* a_parent_category) : BarWidget(name, a_parent_category) {
    if (a_parent_category != Q_NULLPTR) {
        a_level = a_parent_category->level() + 1;

        a_pixlbl_down_arrow = new PixLabel(PIX_FOLDER + "down_arrow.png", 10);
        connect(a_pixlbl_down_arrow, SIGNAL(sig_pixlbl_clicked()), this, SLOT(slot_arrow_switch()));
        a_pixlbl_right_arrow = new PixLabel(PIX_FOLDER + "right_arrow.png", 10);
        connect(a_pixlbl_right_arrow, SIGNAL(sig_pixlbl_clicked()), this, SLOT(slot_arrow_switch()));

        a_stackw_arrows = new QStackedWidget;
        a_stackw_arrows->resize(this->height(), this->height());
        a_stackw_arrows->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        a_stackw_arrows->addWidget(a_pixlbl_down_arrow);
        a_stackw_arrows->addWidget(a_pixlbl_right_arrow);
        a_downarrow = true;

        a_hlayout->insertWidget(0, a_stackw_arrows);
        a_hlayout->insertSpacing(0, a_space_size * (a_level - 1));
    }
    else
        a_level = 0; //top-level category only
}

Category* Category::findCategory(const QString &text) {

    for (auto it = a_children_category.begin(); it != a_children_category.end(); it ++) {
        if ((*it)->name() != text) {
            Category* res = (*it)->findCategory(text);
            if (res != (*it))
                return res;
        }
        else
            return *it;
    }
    return this;

}

void Category::newChildCategory(Category* child) {
    a_children_category.insert(child);
    connect(this, SIGNAL(sig_category_hide()), child, SLOT(slot_barwidget_hide()));
    connect(this, SIGNAL(sig_category_hide()), child, SLOT(slot_category_hide_children()));
    connect(this, SIGNAL(sig_category_show()), child, SLOT(slot_barwidget_show()));
    connect(this, SIGNAL(sig_category_show()), child, SLOT(slot_category_show_children()));
}

void Category::arrow_switch() {
    if (!a_children_category.empty() | !a_children_link.empty()) {
        a_stackw_arrows->setCurrentIndex(a_downarrow);
        if (a_downarrow)
            //currently down_arrow, children are visible
            emit sig_category_hide();
        else
            //currently right_arrow, children are not visible
            emit sig_category_show();
        a_downarrow = 1 - a_downarrow;
    }
}

void Category::slot_category_hide_children() {
    emit sig_category_hide();
}

void Category::slot_category_show_children() {
    emit sig_category_show();
}
