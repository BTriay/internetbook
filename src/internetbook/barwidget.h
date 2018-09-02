#ifndef BARWIDGET_H
#define BARWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include "textlabel.h"
#include "pixlabel.h"

class Category;

class BarWidget : public QWidget {
    Q_OBJECT

private:
    TextLabel* a_lbl_name;
    PixLabel* a_pixlbl_bin;
    Category* a_parent_category;

    //virtual void arrow_switch() = 0;

public:
    BarWidget(const QString& text = QString(),
              Category* parent_category = Q_NULLPTR,
              QWidget *parent = Q_NULLPTR);

    const QString name() const { return a_lbl_name->text(); }
    Category* parentCategory() const { return a_parent_category; }

    virtual int id() const { return -1; }

signals:
    void sig_barwidget_hideme();
    void sig_barwidget_showme();

public slots:
    void slot_barwidget_pixlbl_bin_clicked();
    void slot_barwidget_pixlbl_bin_released();

    void slot_barwidget_pixlbl_url_clicked();
    void slot_barwidget_pixlbl_url_released();

    void slot_barwidget_textlbl_clicked();
    void slot_barwidget_textlbl_released();
    void slot_barwidget_textlbl_move_me(int y);

    //void slot_barwidget_arrow_switch();

    void slot_barwidget_hide();
    void slot_barwidget_show();

protected:
    QHBoxLayout* a_hlayout;
    const QString PIX_FOLDER  = QString("../../icons/");
};

#endif // BARWIDGET_H
