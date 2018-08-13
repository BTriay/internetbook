#ifndef CATEGORY_H
#define CATEGORY_H

#include <set>

#include "barwidget.h"
#include "link.h"

#include <QDebug>

class Category : public BarWidget {

private:
    short unsigned int a_level;
    std::set<Category*> a_children_category;
    std::set<Link*> a_children_link;
    Category* a_parent_category;

public:
    Category(const QString& name = QString(), Category* a_parent_category = Q_NULLPTR);

    const short unsigned int level() const { return a_level; }
    void setLevel(short unsigned int new_level) { a_level = new_level; }
    Category* findCategory(const QString &text);

    void newChildCategory(Category* child);
};

#endif // CATEGORY_H
