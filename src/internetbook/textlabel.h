#ifndef TEXTLABEL_H
#define TEXTLABEL_H

#include <QLabel>
#include <QMouseEvent>

#include <QDebug>

class TextLabel : public QLabel {
    Q_OBJECT

private:

public:
    TextLabel(const QString& text, QWidget* parent = Q_NULLPTR);

signals:
    void sig_textlbl_clicked();
    void sig_textlbl_move_me(int y);
    void sig_textlbl_released();

public slots:


protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // TEXTLABEL_H
