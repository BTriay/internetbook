#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow() {
    a_widget_central_zone = new QWidget;
    setCentralWidget(a_widget_central_zone);

    a_vlayout_central = new QVBoxLayout;
    a_widget_central_zone->setLayout(a_vlayout_central);

    //ADD BARWIDGETS HERE
    a_barwidget_truc = new BarWidget("Truc");
    a_vlayout_central->addWidget(a_barwidget_truc);
    connect(a_barwidget_truc, SIGNAL(sig_barwidget_hideme()),
            this, SLOT(slot_mainw_hidebar()));

    a_link_example = new Link("home", "www.example.com");
    a_vlayout_central->addWidget(a_link_example);
    connect(a_link_example, SIGNAL(sig_barwidget_hideme()),
            this, SLOT(slot_mainw_hidebar()));

    a_barwidget_chose = new BarWidget("Chose");
    a_vlayout_central->addWidget(a_barwidget_chose);
    connect(a_barwidget_chose, SIGNAL(sig_barwidget_hideme()),
            this, SLOT(slot_mainw_hidebar()));
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

void MainWindow::slot_mainw_hidebar() {
    qDebug() << "hide bar from mainwindow";
    qobject_cast<QWidget*>(sender())->hide();
}
