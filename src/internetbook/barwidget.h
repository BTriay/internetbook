#ifndef BARWIDGET_H
#define BARWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include "textlabel.h"
#include "pixlabel.h"

#include <QDebug>

class BarWidget : public QWidget {
    Q_OBJECT

private:
    QHBoxLayout* a_hlayout;
    TextLabel* a_lbl_text;
    PixLabel* a_pixlbl_bin;
    PixLabel* a_pixlbl_url;

public:
    BarWidget(const QString& text = QString(), QWidget *parent = Q_NULLPTR);

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
};

#endif // BARWIDGET_H
