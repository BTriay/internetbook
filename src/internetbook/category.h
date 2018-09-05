#ifndef CATEGORY_H
#define CATEGORY_H

#include <set>
#include <QStackedWidget>

#include "barwidget.h"

class Link;

const int a_space_size = 8;

class Category : public BarWidget {
    Q_OBJECT

private:
    short unsigned int a_level;
    int a_id;
    std::set<Category*> a_children_category;
    std::set<Link*> a_children_link;
    Category* a_parent_category;

    QStackedWidget* a_stackw_arrows;
    bool a_downarrow;
    PixLabel* a_pixlbl_right_arrow;
    PixLabel* a_pixlbl_down_arrow;

    void connectNewChild(BarWidget* child);

public:
    Category(const QString& name = QString(), int id = 0, Category* a_parent_category = Q_NULLPTR);
    virtual ~Category();

    short unsigned int level() const { return a_level; }
    int childSpace() const { return a_level * a_space_size; }
    int id() const { return a_id; }
    void setLevel(short unsigned int new_level) { a_level = new_level; }
    Category* findCategory(int parent_category_id);

    void newChildCategory(Category* child);
    void newChildLink(Link* child);

signals:
    void sig_category_hide();
    void sig_category_show();

public slots:
    void slot_category_arrow_switch();

    void slot_category_hide_children();
    void slot_category_show_children();
};

#endif // CATEGORY_H
