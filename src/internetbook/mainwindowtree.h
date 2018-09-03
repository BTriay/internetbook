#ifndef MAINWINDOWTREE_H
#define MAINWINDOWTREE_H

#include <QVBoxLayout>

#include "barwidget.h"
#include "category.h"
#include "link.h"

class MainWindowTree : public QWidget {
    Q_OBJECT

private:
    QVBoxLayout *a_vlayout_central;
    Category* a_top_category;

    Category* insertCategoryInTree(const QString& cat_text, int category_id, int parent_category_id = 0);
    Link* insertLinkInTree(const QString& link_text, QString url, int parent_category_id = 0);
    void insertCatLinkInLayout(BarWidget* new_bar, int parent_category_id = 0);

public:
    MainWindowTree(QWidget *parent = Q_NULLPTR);

    void insertCategory(const QString& cat_text, int category_id, int parent_category_id = 0);
    void insertLink(const QString& link_text, QString url, int parent_category_id = 0);
    Category* findCategory(int parent_category_id); //return weak pointer

signals:
    void sig_mainwtree_status(const QString& text, int timeout = 0);

public slots:
    void slot_mainwtree_hidebar();
    void slot_mainwtree_showbar();

};

#endif // MAINWINDOWTREE_H
