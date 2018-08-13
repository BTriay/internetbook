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
    QHBoxLayout* a_hlayout;
    TextLabel* a_lbl_name;
    PixLabel* a_pixlbl_bin;
    PixLabel* a_pixlbl_url;
    Category* a_parent_category;

public:
    BarWidget(const QString& text = QString(),
              Category* parent_category = Q_NULLPTR,
              QWidget *parent = Q_NULLPTR);
    void insertWidget_toBar(int index, QWidget* w);
    const QString name() const { return a_lbl_name->text(); }

signals:
    void sig_barwidget_hideme();

public slots:
    void slot_pixlbl_bin_clicked();
    void slot_pixlbl_bin_released();

    void slot_pixlbl_url_clicked();
    void slot_pixlbl_url_released();

    void slot_textlbl_clicked();
    void slot_textlbl_released();
    void slot_textlbl_move_me(int y);

protected:
    Category* parentCategory() const { return a_parent_category; }
};

#endif // BARWIDGET_H
