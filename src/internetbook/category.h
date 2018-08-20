#ifndef CATEGORY_H
#define CATEGORY_H

#include <set>
#include <QStackedWidget>

#include "barwidget.h"
#include "link.h"

#include <QDebug>

const int a_space_size = 8;

class Category : public BarWidget {
    Q_OBJECT

private:
    short unsigned int a_level;
    std::set<Category*> a_children_category;
    std::set<Link*> a_children_link;
    Category* a_parent_category;

    QStackedWidget* a_stackw_arrows;
    bool a_downarrow;
    PixLabel* a_pixlbl_right_arrow;
    PixLabel* a_pixlbl_down_arrow;

    void arrow_switch();

public:
    Category(const QString& name = QString(), Category* a_parent_category = Q_NULLPTR);

    const short unsigned int level() const { return a_level; }
    void setLevel(short unsigned int new_level) { a_level = new_level; }
    Category* findCategory(const QString &text);

    void newChildCategory(Category* child);

signals:
    void sig_category_hide();
    void sig_category_show();

public slots:
    void slot_category_hide_children();
    void slot_category_show_children();
};

#endif // CATEGORY_H
