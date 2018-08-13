#include "barwidget.h"

BarWidget::BarWidget(const QString& text, Category* parent_category,
                     QWidget *parent): QWidget(parent) {

    a_lbl_name = new TextLabel(text);
    a_parent_category = parent_category;

    if (parent_category != Q_NULLPTR) {
        const QString PIX_FOLDER  = QString("../../icons/");

        a_hlayout = new QHBoxLayout;
        a_hlayout->setContentsMargins(0, 0, 0, 0);
        this->setLayout(a_hlayout);

        a_hlayout->addWidget(a_lbl_name);
        connect(a_lbl_name, SIGNAL(sig_textlbl_clicked()), this, SLOT(slot_textlbl_clicked()));
        connect(a_lbl_name, SIGNAL(sig_textlbl_released()), this, SLOT(slot_textlbl_released()));
        connect(a_lbl_name, SIGNAL(sig_textlbl_move_me(int)), this, SLOT(slot_textlbl_move_me(int)));

        a_hlayout->addStretch(-1);

        a_pixlbl_url = new PixLabel(PIX_FOLDER + "url_black.png");
        a_hlayout->addWidget(a_pixlbl_url);
        connect(a_pixlbl_url, SIGNAL(sig_pixlbl_clicked()), this, SLOT(slot_pixlbl_url_clicked()));
        connect(a_pixlbl_url, SIGNAL(sig_pixlbl_released()), this, SLOT(slot_pixlbl_url_released()));

        a_pixlbl_bin = new PixLabel(PIX_FOLDER + "bin_black.png");
        a_hlayout->addWidget(a_pixlbl_bin);
        connect(a_pixlbl_bin, SIGNAL(sig_pixlbl_clicked()), this, SLOT(slot_pixlbl_bin_clicked()));
        connect(a_pixlbl_bin, SIGNAL(sig_pixlbl_released()), this, SLOT(slot_pixlbl_bin_released()));
    }

    //button.setToolTip("Texte d'aide")
    //button.setCursor(Qt::PointingHandCursor);
}

void BarWidget::insertWidget_toBar(int index, QWidget* w) {
    a_hlayout->insertWidget(index, w);
}



void BarWidget::slot_pixlbl_bin_clicked() {
    emit sig_barwidget_hideme();
qDebug() << "BarWidget::slot_pixlbl_bin_clicked()";
}

void BarWidget::slot_pixlbl_bin_released() {
    emit sig_barwidget_hideme();
qDebug() << "BarWidget::slot_pixlbl_bin_released()";
}

void BarWidget::slot_pixlbl_url_clicked() {
qDebug() << "BarWidget::slot_pixlbl_url_clicked()";
}

void BarWidget::slot_pixlbl_url_released() {
qDebug() << "BarWidget::slot_pixlbl_url_released()";
}

void BarWidget::slot_textlbl_clicked() {
qDebug() << "BarWidget::slot_textlbl_clicked" << a_lbl_name->text();
}

void BarWidget::slot_textlbl_released() {
qDebug() << "BarWidget::slot_textlbl_released" << a_lbl_name->text();
}

void BarWidget::slot_textlbl_move_me(int y) {
qDebug() << "BarWidget::slot_textlbl_move_me" << a_lbl_name->text();
}
