#include "mainwindow.h"
#include <QMessageBox>
#include <QIcon>
#include<QMdiSubWindow>
#include "logindlg.h"
#include <QStandardItemModel>
#include <QTableView>
#include "scriptdlg.h"
#include "insert_mscdlg.h"
#include "select_msgdlg.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("CMDA无线基站管理系统"));


    /*
QMdiArea控件只能在QMainWindow当中使用，是用来实现多文档界面的必备控件，调用的QMdiArea的AddSubWindow将一个widget变为子窗口.
mdiArea->activeSubWindow()方法永远返回当前活动的子窗口
     */
    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);
    mdiArea->setBackground(Qt::NoBrush);
    mdiArea->setStyleSheet("background-image: url(1.jpg);");//背景设置为1.jpg子窗口大小可调整，“”中的内容与CSS格式一致。
    //mdiArea->setStyleSheet("border-image: url(1.jpg);");


    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);//滚动条:当子窗口的范围超过父窗口的显示范围时，父窗口自动添加横向滚动条。
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    //下两行等同于setWindowIcon(QIcon("mian.jpg"))
    QIcon icon("main.png");//设置光标
    setWindowIcon(icon);



    createAction();//先创建按钮，在创建菜单
    createMenus();
}

MainWindow::~MainWindow()
{

}
//closeEvent函数是在一个widget退出之前被自动调用的函数,参数event的accept方法代表接受退出，ignore方法代表不接受退出
//系统自动调用该事件
void MainWindow::closeEvent(QCloseEvent *event)
{

    QMessageBox::StandardButton button = QMessageBox::question(this, "提示", "是否退出程序",QMessageBox::Yes|QMessageBox::No);
    if(button == QMessageBox::Yes)//如果用户点击yes
    {
        event->accept();//接受退出
    }
    else
    {
        event->ignore();//不接受退出
    }
}

void MainWindow::showview()
{
    QStandardItemModel *model = new QStandardItemModel(5, 3);//建立一个5行3列的model

    //设置model的列名称
    model->setHeaderData(0, Qt::Horizontal, "姓名");
    model->setHeaderData(1, Qt::Horizontal, "性别");
    model->setHeaderData(2, Qt::Horizontal, "年龄");
    //设置model的每一个单元格的内容
//    model->setData(model->index(0,0,QModelIndex()),"Mike");
//    model->setData(model->index(0,1,QModelIndex()),"man");
//    model->setData(model->index(0,2,QModelIndex()),20);

//    model->setData(model->index(1,0,QModelIndex()),"John");
//    model->setData(model->index(1,1,QModelIndex()),"man");
//    model->setData(model->index(1,2,QModelIndex()),22);

//    model->setData(model->index(2,0,QModelIndex()),"Lucy");
//    model->setData(model->index(2,1,QModelIndex()),"woman");
//    model->setData(model->index(2,2,QModelIndex()),19);

//    model->setData(model->index(3,0,QModelIndex()),"Lily");
//    model->setData(model->index(3,1,QModelIndex()),"woman");
//    model->setData(model->index(3,2,QModelIndex()),23);

//    model->setData(model->index(4,0,QModelIndex()),"Anni");
//    model->setData(model->index(4,1,QModelIndex()),"woman");
//    model->setData(model->index(4,2,QModelIndex()),13);


    QTableView *view1 = new QTableView;
    view1->setAttribute(Qt::WA_DeleteOnClose);//view在close的时候会delete model
    mdiArea->addSubWindow(view1);
    view1->setStyleSheet("border-image:url(3.jpg);");

    //view继承自widget，如果没有model，view不会显示任何数据
    view1->setModel(model);
    view1->show();
    mdiArea->activeSubWindow()->resize(width() - 100, height() - 100);
}

void MainWindow::showsub()
{
    QWidget *w1 = new QWidget;
    w1->setAttribute(Qt::WA_DeleteOnClose);//代表关闭这个widget的时候自动将这个widget delete（释放）；
    //QMdiArea控件只能在QMainWindow当中使用，是用来实现多文档界面的必备控件，调用的QMdiArea的AddSubWindow将一个widget变为子窗口.


    mdiArea->addSubWindow(w1);
    w1->setWindowTitle(tr("ehe"));
    w1->setStyleSheet("border-image:url(3.jpg);");
    //mdiArea->activeSubWindow()；//永远返回当前活动的子窗口

    w1->show();
    mdiArea->activeSubWindow()->resize(width() - 100, height() - 100);
}


void MainWindow::createMenus()
{
    adminMenu = this->menuBar()->addMenu(tr("管理"));//调用QMainWindows类的MenuBar函数就会返回一个menubar的实例，对QT来讲，menubar只允许有一个。this可以省略
    adminMenu->addAction(loginAction);
    adminMenu->addAction(logoutAction);
    adminMenu->addSeparator();
    adminMenu->addAction(exitAction);

    dataMenu = menuBar()->addMenu(tr("数据"));
    dataMenu->addAction(insertmscAction);
    dataMenu->addAction(selectmscAction);
    dataMenu->addSeparator();
    dataMenu->addAction(scriptAction);

    windowMenu = menuBar()->addMenu(tr("窗口"));
    windowMenu->addAction(cascadeAction);
    windowMenu->addAction(tileAction);


    helpMenu = menuBar()->addMenu(tr("帮助"));
    helpMenu->addAction(helpAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAction);

}
void MainWindow::createAction()
{
    loginAction = new QAction(tr("登陆"), this);
    loginAction->setShortcut(tr("Ctrl+u"));
    connect(loginAction, SIGNAL(triggered()), this, SLOT(on_login()));

    logoutAction = new QAction(tr("注销"),this);
    logoutAction->setShortcut(tr("Ctrl+b"));
    connect(logoutAction, SIGNAL(triggered()), this, SLOT(on_logout()));

    exitAction = new QAction(tr("退出"), this);
    exitAction->setShortcut(tr("ctrl+w"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(on_exit()));

    scriptAction = new QAction(tr("执行脚本"), this);
    scriptAction->setShortcut(tr("ctrl+p"));
    scriptAction->setEnabled(false);//设置执行脚本不可用
    connect(scriptAction, SIGNAL(triggered()), this, SLOT(on_script()));

    cascadeAction = new QAction(tr("层叠"), this);
    cascadeAction->setShortcut(tr("ctrl+q"));
    connect(cascadeAction, SIGNAL(triggered()), this, SLOT(on_cascadeSubWindow()));

    tileAction = new QAction(tr("并列"), this);
    tileAction->setShortcut(tr("ctrl+r"));
    connect(tileAction, SIGNAL(triggered()), this, SLOT(on_tileSubWindow()));

    helpAction = new QAction(tr("帮助"), this);
    helpAction->setShortcut(tr("ctrl+s"));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(on_help()));

    aboutAction = new QAction(tr("关于"), this);
    aboutAction->setShortcut(tr("ctrl+t"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(on_about()));

    insertmscAction = new QAction(tr("添加msc"), this);
    insertmscAction->setShortcut(tr("ctrl+l"));
    insertmscAction->setEnabled(false);
    connect(insertmscAction, SIGNAL(triggered()), this, SLOT(on_insertmsc()));

    selectmscAction = new QAction(tr("查询"), this);
    selectmscAction->setShortcut(tr("ctrl+o"));
    selectmscAction->setEnabled(false);
    connect(selectmscAction, SIGNAL(triggered()), this, SLOT(on_selectmsg()));


}
void MainWindow::on_login()
{
    loginDlg dlg;//实例化对话框
    dlg.exec();//调用exec调用一个模式对话框，模式对话框：打开对话框的时候，主窗口是不能接受其他输入输出的。非模式对话框打开的时候，主窗体可以输出输入，运行到这里会阻塞
    //dlg.show();//调用非模式框，这是在函数里边，调用挖暗沉后会释放，想用模式对话框可loginDlg *dlg = new loginDlg;


    //如何在这里知道用户名，密码，ip等用户输入信息。
 if(dlg.isLogin)
 {
     //mymysql db;
     int res = db.sql_connect(dlg.hostip.toStdString().data(),
                    dlg.userid.toStdString().data(),
                    dlg.password.toStdString().data(),
                    dlg.dbname.toStdString().data());
     if(res == -1)
     {
         QMessageBox::information(this, "登陆失败", db.get_error());

     }else
     {
         QMessageBox::information(this, "登陆成功","您已登录成功");
         scriptAction->setEnabled(true);
         insertmscAction->setEnabled(true);
         selectmscAction->setEnabled(true);
     }

     /*
     if((dlg.userid == "abc")&& (dlg.password == "123456"))
     {
         QMessageBox::information(this,"用户名", "登陆成功");
     }
     else
         QMessageBox::information(this,"用户名", "登陆ｓｈｉｂａｉ");
         */
 }
}

void MainWindow::on_logout()
{
    QMessageBox::StandardButton button = QMessageBox::question(this, "提示", "是否注销",QMessageBox::Yes|QMessageBox::No);
    if(button == QMessageBox::Yes)//如果用户点击yes
    {
        db.sql_disconnect();//接受退出
        scriptAction->setEnabled(false);
    }

   // QMessageBox::information(this,"hello", "logout", "YES", "NO");
}

void MainWindow::on_exit()
{
    //QMessageBox::information(this,"hello", "logout", "YES", "NO");

    this->close();//this可以省略调用mainwindow的函数
}

void MainWindow::on_script()
{
    scriptDlg dlg;
    dlg.exec();

    if(dlg.isLogin)//如果用户点击了执行按钮才执行下面的代码
    {
       script_msg(dlg.SQL.toStdString().data());
    }


//    if(db.sql_exec("delete from table1 where name = 'John'") == -1)
//    {
//        QMessageBox::information(this, "", db.get_error());
//    }else
//    {
//        QMessageBox::information(this, "", "exec success");
//    }
    //添加子窗口
   //showsub();
    //showview();
   // QMessageBox::information(this,"hello", "logout", "YES", "NO");

}

void MainWindow::script_msg(const char *SQL)
{
    int res = 0;
    if((strncmp(SQL, "SELECT", 6) == 0) ||(strncmp(SQL, "select", 6) == 0))
    {
        QStandardItemModel *model = NULL;

        res = db.sql_open(SQL, &model);

        QTableView *view1 = new QTableView;
        view1->setAttribute(Qt::WA_DeleteOnClose);//view在close的时候会delete model
        mdiArea->addSubWindow(view1);
        view1->setStyleSheet("border-image:url(3.jpg);");

        //view继承自widget，如果没有model，view不会显示任何数据
        view1->setModel(model);
        view1->show();
        mdiArea->activeSubWindow()->resize(width() - 100, height() - 100);
    }
    else
    {
        res = db.sql_exec(SQL);
    }
    if (res = -1)
    {
        QMessageBox::information(this, tr("执行失败"), db.get_error());
    }else
    {
        QMessageBox::information(this, tr("提示"), tr("执行成功"));
    }


}


void MainWindow::on_cascadeSubWindow()
{
    mdiArea->cascadeSubWindows();
}

void MainWindow::on_tileSubWindow()
{
    mdiArea->tileSubWindows();
}

void MainWindow::on_help()
{
    QMessageBox::information(this,"hello", "help", "YES", "NO");
}

void MainWindow::on_about()
{
    QMessageBox::information(this,"hello", "about", "YES", "NO");
}

void MainWindow::on_insertmsc()
{
    insert_mscDlg dlg;
    dlg.exec();

    if(dlg.isok)//如果用户点击了执行按钮才执行下面的代码
    {
       script_msg(dlg.SQL.toStdString().data());
    }

}

void MainWindow::on_selectmsg()
{
    Select_msgDlg dlg;
    dlg.exec();

    if(dlg.isok)//如果用户点击了执行按钮才执行下面的代码
    {
       script_msg(dlg.SQL.toStdString().data());
    }

}
