#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>


#include "mainwindowtree.h"
#include "db.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    MainWindowTree *a_widget_central_zone;
    QStatusBar* a_status_bar;

    QMenu* a_menu_file;
    QMenu* a_menu_edit;
    QMenu* a_menu_toolBar;
    QMenu* a_menu_about;
    QToolBar* a_toolbar;

    QAction* a_act_exit;
    QAction* a_act_open;
    QAction* a_act_save;
    QAction* a_act_save_as;
    QAction* a_act_find;
    QAction* a_act_new_category;
    QAction* a_act_new_link;
    QAction* a_act_new_book;
    QAction* a_act_undo;
    QAction* a_act_redo;
    QAction* a_act_about;

    QAction* a_act_toolbar_open;
    QAction* a_act_toolbar_save;
    QAction* a_act_toolbar_save_as;
    QAction* a_act_toolbar_new_category;
    QAction* a_act_toolbar_new_link;
    QAction* a_act_toolbar_new_book;
    QAction* a_act_toolbar_undo;
    QAction* a_act_toolbar_redo;
    QAction* a_act_toolbar_find;
    QAction* a_act_toolbar_exit;


    void createMenus();
    void createToolbar();

public:
    MainWindow();
    //~MainWindow();

public slots:
    void slot_mainw_set_statusbar(const QString& text, int timeout = 0);
    void slot_mainw_updateToolbar();
};

#endif // MAINWINDOW_H

