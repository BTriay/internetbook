#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

#include "barwidget.h"

#include <QDebug>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QWidget *a_widget_central_zone;
    QVBoxLayout *a_vlayout_central;
    QLabel* a_lbl_info;
    QLabel* a_lbl_separator;

public:
    MainWindow();
    //~MainWindow();

public slots:
    //void slot_mainw_hidebar();
};

#endif // MAINWINDOW_H
