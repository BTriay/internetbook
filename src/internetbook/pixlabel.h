#ifndef PIXLABEL_H
#define PIXLABEL_H

#include <QLabel>
#include <QMouseEvent>

class PixLabel: public QLabel {
    Q_OBJECT

private:
    //QPixmap a_pic;

public:
    PixLabel(const QString& pic_path, QWidget* parent = Q_NULLPTR);

signals:
    void sig_pixlbl_clicked();
    void sig_pixlbl_released();

public slots:

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // PIXLABEL_H
