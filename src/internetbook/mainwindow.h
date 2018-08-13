#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStatusBar>

#include "mainwindowtree.h"

#include <QDebug>

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    MainWindowTree *a_widget_central_zone;
    QStatusBar* a_status_bar;

public:
    MainWindow();
    //~MainWindow();

public slots:
    void slot_mainw_set_statusbar(const QString& text, int timeout = 0);
};

#endif // MAINWINDOW_H
