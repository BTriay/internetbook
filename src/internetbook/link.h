#ifndef LINK_H
#define LINK_H

#include <QLabel>
#include "barwidget.h"

class Link : public BarWidget {

private:
    //QLabel* a_lbl_url;
    //PixLabel* a_pixlbl_url;
    //QString a_url;

    virtual void arrow_switch() {} //no arrow switch in links

public:
    //Link(QString name, QString url);
    Link();
};

#endif // LINK_H
