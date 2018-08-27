#include "mainwindowtree.h"

MainWindowTree::MainWindowTree(QWidget *parent) : QWidget(parent) {

    a_vlayout_central = new QVBoxLayout;
    this->setLayout(a_vlayout_central);

    a_top_category = new Category;

    //ADD BARWIDGETS HERE

    insertCategory("programming");
    insertCategory("c++", "programming");
    insertCategory("diy");
    insertCategory("videos", "c++");
    insertCategory("compilation", "c++");
    insertCategory("stuff", "c++");
    insertCategory("visits");
    insertCategory("linux");
    insertCategory("python", "programming");
    insertCategory("electronics", "diy");
    insertCategory("commands", "linux");
    insertCategory("tips", "linux");
    insertCategory("install", "linux");

    //ADD BARWIDGETS HERE - END

    a_vlayout_central->insertStretch(-1);

}

void MainWindowTree::slot_mainwtree_hidebar() {
    qobject_cast<QWidget*>(sender())->hide();
}

void MainWindowTree::slot_mainwtree_showbar() {
    qobject_cast<QWidget*>(sender())->show();
}

Category* MainWindowTree::findCategory(const QString& text) {
    return a_top_category->findCategory(text);
}

void MainWindowTree::insertCategory(const QString& cat_text, const QString& parent_cat_text) {
    Category* new_cat = insertCategoryInTree(cat_text, parent_cat_text);
    insertCategoryInLayout(new_cat, parent_cat_text);
}

Category* MainWindowTree::insertCategoryInTree(const QString& cat_text, const QString& parent_cat_text) {
    Category* parent;
    if (parent_cat_text != "")
        parent = findCategory(parent_cat_text);
    else
        parent = a_top_category;
    Category* new_cat = new Category(cat_text, parent);
    parent->newChildCategory(new_cat);
    return new_cat;
}

void MainWindowTree::insertCategoryInLayout(Category* new_cat, const QString& parent_cat_text) {
    if (parent_cat_text == "")
            a_vlayout_central->addWidget(new_cat);
    else {
        for (auto i = 0; i < a_vlayout_central->count(); i++) {
            BarWidget* bar = qobject_cast<BarWidget*>(a_vlayout_central->itemAt(i)->widget());
             if (bar->name() == parent_cat_text) {
                 a_vlayout_central->insertWidget(++i, new_cat);
                 connect(new_cat, SIGNAL(sig_barwidget_hideme()),
                         this, SLOT(slot_mainwtree_hidebar()));
                 connect(new_cat, SIGNAL(sig_barwidget_showme()),
                         this, SLOT(slot_mainwtree_showbar()));
                 break;
            }
        }
    }
}
