#ifndef LINK_H
#define LINK_H

#include <QLabel>

#include "barwidget.h"
/*
class Category;
int Category::childSpace();
*/
class Link : public BarWidget {
    Q_OBJECT

private:
    QLabel* a_lbl_url;
    //PixLabel* a_pixlbl_url;

public:
    Link(QString name, QString url, Category* parent_category);
    virtual ~Link();

/*
signals:
    void sig_link_hide();
    void sig_link_show();
*/
public slots:
    void dummy() {}
/*
    void slot_link_hide();
    void slot_link_show();
*/
};

#endif // LINK_H
