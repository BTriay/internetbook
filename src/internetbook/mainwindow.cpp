#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow() {
    a_widget_central_zone = new QWidget;
    this->setCentralWidget(a_widget_central_zone);

    a_vlayout_central = new QVBoxLayout;
    a_widget_central_zone->setLayout(a_vlayout_central);

    //ADD BARWIDGETS HERE
    a_vlayout_central->addWidget(new BarWidget("Truc"));
    a_vlayout_central->addWidget(new BarWidget("Chose"));
    //ADD BARWIDGETS HERE - END

    a_vlayout_central->insertStretch(-1);

    a_lbl_separator = new QLabel;
    a_lbl_separator->setFrameStyle(QFrame::HLine);
    a_lbl_separator->setLineWidth(0.1);
    a_lbl_separator->setMaximumHeight(3);
    a_vlayout_central->addWidget(a_lbl_separator);

    a_lbl_info = new QLabel("<i>info<i/>");
    a_vlayout_central->addWidget(a_lbl_info);

    this->resize(300,200);
    this->setWindowTitle("Internet book");
}

//MainWindow::~MainWindow() {}
/*
void MainWindow::slot_mainw_hidebar() {
    qDebug() << "hide bar from mainwindow";
}
*/
