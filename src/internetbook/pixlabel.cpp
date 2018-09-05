#include "pixlabel.h"

PixLabel::PixLabel(const QString& alias,
                   int pix_size,
                   QWidget* parent):
    QLabel(parent) {
    a_pic = QPixmap(":" + alias);
    this->setPixmap(a_pic.scaledToHeight(pix_size));
}

void PixLabel::changePicSize(int new_size) {
    a_pic.scaledToHeight(new_size);
}

void PixLabel::mousePressEvent(QMouseEvent* ) {
    emit sig_pixlbl_clicked();
}

void PixLabel::mouseReleaseEvent(QMouseEvent* ) {
    emit sig_pixlbl_released();
}
