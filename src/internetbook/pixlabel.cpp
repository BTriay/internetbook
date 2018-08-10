#include "pixlabel.h"

PixLabel::PixLabel(const QString& pic_path, QWidget* parent):
    QLabel(parent) {
    this->setPixmap(QPixmap(pic_path).scaledToHeight(16));
}

void PixLabel::mousePressEvent(QMouseEvent *ev) {
    emit sig_pixlbl_clicked();
}

void PixLabel::mouseReleaseEvent(QMouseEvent *ev) {
    emit sig_pixlbl_released();
}
