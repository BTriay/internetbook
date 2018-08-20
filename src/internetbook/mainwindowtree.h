#ifndef MAINWINDOWTREE_H
#define MAINWINDOWTREE_H

#include <QVBoxLayout>

#include "barwidget.h"
#include "category.h"
#include "link.h"

#include <QDebug>

class MainWindowTree : public QWidget {
    Q_OBJECT

private:
    QVBoxLayout *a_vlayout_central;
    Category* a_top_category;

    Category* insertCategoryInTree(const QString& cat_text, const QString& parent_cat_text = QString());
    void insertCategoryInLayout(Category* new_cat, const QString& parent_cat_text = QString());

public:
    MainWindowTree(QWidget *parent = Q_NULLPTR);

    void insertCategory(const QString& cat_text, const QString& parent_cat_text = QString());
    Category* findCategory(const QString& text); //return weak pointer

signals:
    void sig_mainwtree_status(const QString& text, int timeout = 0);

public slots:
    void slot_mainwtree_hidebar();
    void slot_mainwtree_showbar();

};

#endif // MAINWINDOWTREE_H
