#include "mainwindowtree.h"

MainWindowTree::MainWindowTree(QWidget *parent) : QWidget(parent) {

    a_vlayout_central = new QVBoxLayout;
    this->setLayout(a_vlayout_central);

    a_top_category = new Category;

    //ADD BARWIDGETS HERE

    insertCategory("programming", 1);
    insertCategory("c++", 2, 1);
    insertCategory("diy", 3);
    insertCategory("videos", 4, 2);
    insertCategory("compilation", 5, 2);
    insertCategory("stuff", 6, 2);
    insertCategory("visits", 7);
    insertCategory("linux", 8);
    insertCategory("python", 9, 1);
    insertCategory("electronics", 10, 3);
    insertCategory("commands", 11, 8);
    insertCategory("tips", 12, 8);
    insertCategory("install", 13, 8);

    //ADD BARWIDGETS HERE - END

    a_vlayout_central->insertStretch(-1);

}

void MainWindowTree::slot_mainwtree_hidebar() {
    qobject_cast<QWidget*>(sender())->hide();
}

void MainWindowTree::slot_mainwtree_showbar() {
    qobject_cast<QWidget*>(sender())->show();
}

Category* MainWindowTree::findCategory(int parent_category_id) {
    return a_top_category->findCategory(parent_category_id);
}

void MainWindowTree::insertCategory(const QString& cat_text, int category_id, int parent_category_id) {
    //use smart ptr
    Category* new_cat = insertCategoryInTree(cat_text, category_id, parent_category_id);
    insertCategoryInLayout(new_cat, parent_category_id);
}

Category* MainWindowTree::insertCategoryInTree(const QString& cat_text, int category_id, int parent_category_id) {
    Category* parent;
    if (parent_category_id != 0)
        parent = findCategory(parent_category_id);
    else
        parent = a_top_category;
    Category* new_cat = new Category(cat_text, category_id, parent);
    parent->newChildCategory(new_cat);
    return new_cat;
}

void MainWindowTree::insertCategoryInLayout(Category* new_cat, int parent_category_id) {
    if (parent_category_id == 0)
            a_vlayout_central->addWidget(new_cat);
    else {
        for (auto i = 0; i < a_vlayout_central->count(); i++) {
            BarWidget* cat = qobject_cast<BarWidget*>(a_vlayout_central->itemAt(i)->widget());
            if (cat->id() == parent_category_id) {
                 a_vlayout_central->insertWidget(++i, new_cat);
                 connect(new_cat, SIGNAL(sig_barwidget_hideme()),
                         this, SLOT(slot_mainwtree_hidebar()));
                 connect(new_cat, SIGNAL(sig_barwidget_showme()),
                         this, SLOT(slot_mainwtree_showbar()));
                 break;
            } else {
            }
        }
        //return an error here?
    }
}
