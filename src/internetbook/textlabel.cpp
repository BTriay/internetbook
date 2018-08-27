#include "textlabel.h"

TextLabel::TextLabel(const QString& text, QWidget* parent) :
    QLabel(text, parent) {
}

void TextLabel::mouseMoveEvent(QMouseEvent* ev) {
    emit sig_textlbl_move_me((qobject_cast<QWidget*>(this))->mapToParent(ev->pos()).y());
}

void TextLabel::mousePressEvent(QMouseEvent*) {
    emit sig_textlbl_clicked();
}

void TextLabel::mouseReleaseEvent(QMouseEvent* ) {
    emit sig_textlbl_released();
}
