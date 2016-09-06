#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenuBar>//创建菜单栏
#include <QMenu>//用于创建菜单

#include<QAction>//菜单下边的选项

#include<QCloseEvent>
#include <QMdiArea>
#include "mymysql.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event);

private:
    mymysql db;
    void showview();
    void showsub();
    void createMenus();
    void createAction();
    QMdiArea *mdiArea;


    QMenu *adminMenu;//管理菜单
    QMenu *dataMenu;//数据菜单
    QMenu *windowMenu;
    QMenu *helpMenu;


    QAction *loginAction;
    QAction *logoutAction;
    QAction *exitAction;
//管理菜单下的行为
    QAction *scriptAction;
    QAction *insertmscAction;
    QAction *selectmscAction;
//窗口下的行为
    QAction *cascadeAction;
    QAction *tileAction;
    //帮助菜单下的行为
    QAction *helpAction;
    QAction *aboutAction;

private slots:
    void on_login();
    void on_logout();
    void on_exit();
    void on_script();
    void script_msg(const char *SQL);
    void on_cascadeSubWindow();
    void on_tileSubWindow();
    void on_help();
    void on_about();
    void on_insertmsc();
    void on_selectmsg();
};

#endif // MAINWINDOW_H
