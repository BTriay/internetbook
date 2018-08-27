#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow() {
    a_widget_central_zone = new MainWindowTree();
    setCentralWidget(a_widget_central_zone);

    a_status_bar = this->statusBar();
    a_status_bar->showMessage("status bar");

    this->resize(300,200);
    this->setWindowTitle("Internet book");
}

//MainWindow::~MainWindow() {}

void MainWindow::slot_mainw_set_statusbar(const QString& text,
                                          int timeout) {
    a_status_bar->showMessage(text, timeout);
}
