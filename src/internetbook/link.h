#ifndef LINK_H
#define LINK_H

#include <QLabel>

#include "barwidget.h"

class Link : public BarWidget {
    Q_OBJECT

private:
    QLabel* a_lbl_url;
    //PixLabel* a_pixlbl_url;

public:
    Link(QString name, QString url, Category* parent_category);
    virtual ~Link();

public slots:

};

#endif // LINK_H
