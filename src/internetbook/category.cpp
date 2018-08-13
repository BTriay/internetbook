#include "category.h"

Category::Category(const QString& name,
                   Category* a_parent_category) : BarWidget(name, a_parent_category) {
    if (a_parent_category != Q_NULLPTR)
        a_level = a_parent_category->level() + 1;
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
}
