#ifndef PIXLABEL_H
#define PIXLABEL_H

#include <QLabel>
#include <QMouseEvent>

class PixLabel: public QLabel {
    Q_OBJECT

private:
    QPixmap a_pic;

public:
    PixLabel(const QString& alias, int pix_size = 14, QWidget* parent = Q_NULLPTR);
    void changePicSize(int new_size);

signals:
    void sig_pixlbl_clicked();
    void sig_pixlbl_released();

public slots:

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // PIXLABEL_H
