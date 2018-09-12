#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow() {
    a_widget_central_zone = new MainWindowTree();
    setCentralWidget(a_widget_central_zone);

    createMenus();
    createToolbar();
    slot_mainw_updateToolbar();

    a_status_bar = this->statusBar();
    a_status_bar->showMessage("status bar");

    connect(a_act_exit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

    QString db_name;
    Db db(db_name);

    //this->resize(300,200);
    this->setWindowTitle("Internet book");
}

//MainWindow::~MainWindow() {}

void MainWindow::createMenus() {
    a_menu_file = menuBar()->addMenu("&File");
        a_act_new_book = new QAction("New &book", this);
        a_act_new_category = new QAction("New cate&gory", this);
        a_act_new_link = new QAction("New lin&k", this);
        a_act_open = new QAction("&Open");
        a_act_exit = new QAction("E&xit", this);
        a_act_save = new QAction("&Save", this);
        a_act_save_as = new QAction("Save &as...", this);

        a_act_new_category->setShortcut(QKeySequence("Ctrl+G"));
        a_act_new_link->setShortcut(QKeySequence("Ctrl+K"));
        a_act_save->setShortcut(QKeySequence("Ctrl+S"));
        a_act_save_as->setShortcut(QKeySequence("Ctrl+Shift+S"));

        a_act_new_book->setIcon(QIcon(":add"));
        a_act_new_category->setIcon(QIcon(":add"));
        a_act_new_link->setIcon(QIcon(":add"));
        a_act_open->setIcon(QIcon(":open"));
        a_act_save->setIcon(QIcon(":save"));
        a_act_save_as->setIcon(QIcon(":save_as"));
        a_act_exit->setIcon(QIcon(":close"));

        a_menu_file->addAction(a_act_new_book);
        a_menu_file->addAction(a_act_new_category);
        a_menu_file->addAction(a_act_new_link);
        a_menu_file->addSeparator();
        a_menu_file->addAction(a_act_open);
        a_menu_file->addSeparator();
        a_menu_file->addAction(a_act_save);
        a_menu_file->addAction(a_act_save_as);
        a_menu_file->addSeparator();
        a_menu_file->addAction(a_act_exit);

    a_menu_edit = menuBar()->addMenu(("&Edit"));
        a_act_undo = new QAction("&Undo");
        a_act_redo = new QAction("&Redo");
        a_act_find = new QAction("&Find");

        a_act_undo->setShortcut(QKeySequence("Ctrl+Z"));
        a_act_redo->setShortcut(QKeySequence("Ctrl+Y"));
        a_act_find->setShortcut(QKeySequence("Ctrl+F"));

        a_act_undo->setIcon(QIcon(":undo"));
        a_act_redo->setIcon(QIcon(":redo"));
        a_act_find->setIcon(QIcon(":find"));

        a_menu_edit->addAction(a_act_undo);
        a_menu_edit->addAction(a_act_redo);
        a_menu_edit->addSeparator();
        a_menu_edit->addAction(a_act_find);

    a_menu_toolBar = menuBar()->addMenu("&Toolbar");
        a_act_toolbar_open = new QAction("&Open");
        a_act_toolbar_save = new QAction("&Save");
        a_act_toolbar_save_as = new QAction("Save &as");
        a_act_toolbar_new_book = new QAction("New &book");
        a_act_toolbar_new_category = new QAction("New cate&gory");
        a_act_toolbar_new_link = new QAction("New lin&k");
        a_act_toolbar_undo = new QAction("&Undo");
        a_act_toolbar_redo = new QAction("&Redo");
        a_act_toolbar_find = new QAction("&Find");
        a_act_toolbar_exit = new QAction("E&xit");

        a_act_toolbar_open->setCheckable(true);         a_act_toolbar_open->setChecked(true);
        a_act_toolbar_save->setCheckable(true);         a_act_toolbar_save->setChecked(true);
        a_act_toolbar_save_as->setCheckable(true);      a_act_toolbar_save_as->setChecked(true);
        a_act_toolbar_new_book->setCheckable(true);     a_act_toolbar_new_book->setChecked(true);
        a_act_toolbar_new_category->setCheckable(true); a_act_toolbar_new_category->setChecked(true);
        a_act_toolbar_new_link->setCheckable(true);     a_act_toolbar_new_link->setChecked(true);
        a_act_toolbar_undo->setCheckable(true);         a_act_toolbar_undo->setChecked(true);
        a_act_toolbar_redo->setCheckable(true);         a_act_toolbar_redo->setChecked(true);
        a_act_toolbar_find->setCheckable(true);         a_act_toolbar_find->setChecked(true);
        a_act_toolbar_exit->setCheckable(true);         a_act_toolbar_exit->setChecked(true);

        a_menu_toolBar->addAction(a_act_toolbar_open);
        a_menu_toolBar->addAction(a_act_toolbar_save);
        a_menu_toolBar->addAction(a_act_toolbar_save_as);
        a_menu_toolBar->addAction(a_act_toolbar_undo);
        a_menu_toolBar->addAction(a_act_toolbar_redo);
        a_menu_toolBar->addAction(a_act_toolbar_new_book);
        a_menu_toolBar->addAction(a_act_toolbar_new_category);
        a_menu_toolBar->addAction(a_act_toolbar_new_link);
        a_menu_toolBar->addAction(a_act_toolbar_find);
        a_menu_toolBar->addAction(a_act_toolbar_exit);

        connect(a_act_toolbar_open, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_save, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_save_as, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_new_book, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_new_category, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_new_link, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_undo, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_redo, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_find, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));
        connect(a_act_toolbar_exit, SIGNAL(changed()), this, SLOT(slot_mainw_updateToolbar()));

    a_menu_about= menuBar()->addMenu(("&About"));
        a_act_about = new QAction("&About");
        a_menu_about->addAction(a_act_about);

}

void MainWindow::createToolbar() {
    a_toolbar = addToolBar("all");

    a_toolbar->addAction(a_act_open);
    a_toolbar->addAction(a_act_save);
    a_toolbar->addAction(a_act_save_as);
    a_toolbar->addSeparator();
    a_toolbar->addAction(a_act_undo);
    a_toolbar->addAction(a_act_redo);
    a_toolbar->addSeparator();
    a_toolbar->addAction(a_act_new_book);
    a_toolbar->addAction(a_act_new_category);
    a_toolbar->addAction(a_act_new_link);
    a_toolbar->addSeparator();
    a_toolbar->addAction(a_act_find);
    a_toolbar->addSeparator();
    a_toolbar->addAction(a_act_exit);
}

void MainWindow::slot_mainw_set_statusbar(const QString& text,
                                          int timeout) {
    a_status_bar->showMessage(text, timeout);
}

void MainWindow::slot_mainw_updateToolbar() {

    a_act_open->setVisible(a_act_toolbar_open->isChecked());
    a_act_save->setVisible(a_act_toolbar_save->isChecked());
    a_act_save_as->setVisible(a_act_toolbar_save_as->isChecked());
    a_act_undo->setVisible(a_act_toolbar_undo->isChecked());
    a_act_redo->setVisible(a_act_toolbar_redo->isChecked());
    a_act_new_book->setVisible(a_act_toolbar_new_book->isChecked());
    a_act_new_category->setVisible(a_act_toolbar_new_category->isChecked());
    a_act_new_link->setVisible(a_act_toolbar_new_link->isChecked());
    a_act_find->setVisible(a_act_toolbar_find->isChecked());
    a_act_exit->setVisible(a_act_toolbar_exit->isChecked());

}
