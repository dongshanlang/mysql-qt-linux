#include "logindlg.h"
#include <QGridLayout>
#include <QPalette>
#include <QMessageBox>

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent)
{

    isLogin = false;//意味着islogin在对话框初始化的时候值为false；

    this->setWindowTitle(tr("登陆"));//this可以省略
    label0 = new QLabel;
    label0->setText(tr("用户名"));

    label1 = new QLabel;
    label1->setText(tr("密码"));

    label2 = new QLabel;
    label2->setText(tr("数据库名称"));

    label3 = new QLabel;
    label3->setText(tr("服务器IP"));

    lineEditUserName = new QLineEdit;
    lineEditDBName = new QLineEdit;
    lineEditPassword = new QLineEdit;
    lineEditPassword->setEchoMode(QLineEdit::Password);//设置密码框
    lineEditHostIP = new QLineEdit;

    loginBtn = new QPushButton;
    loginBtn->setText(tr("登陆"));
    logoutBtn = new QPushButton;
    logoutBtn->setText(tr("取消"));
    //loginBtn->setText();
    QGridLayout *layout1 = new QGridLayout(this);//重点提示：构造函数需要写this
    layout1->addWidget(label0, 0, 0);
    layout1->addWidget(lineEditUserName, 0, 1);
    layout1->addWidget(label1, 1, 0);
    layout1->addWidget(lineEditPassword, 1, 1);
    layout1->addWidget(label2, 2, 0);
    layout1->addWidget(lineEditDBName, 2, 1);
    layout1->addWidget(label3, 3, 0);
    layout1->addWidget(lineEditHostIP, 3, 1);
    layout1->addWidget(loginBtn, 4, 0);
    layout1->addWidget(logoutBtn, 4, 1);
    layout1->setColumnStretch(0, 1);//设置0列宽度
    layout1->setColumnStretch(1, 1);//设置1列宽度
    layout1->setMargin(15);//设置边距
    layout1->setSpacing(10);//设置layout中的控件和控件的间距
    layout1->setSizeConstraint(QLayout::SetFixedSize);//防止修改对话框大小,设置为最合适大小，对话框大小不能改变
    //给登陆界面设置背景图片
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap("2.jpg")));
    this->setPalette(palette);


    connect(loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnOnClick()));
    connect(logoutBtn,SIGNAL(clicked()), this, SLOT(logoutBtnOnClick()));


}

void loginDlg::loginBtnOnClick()
{
    this->userid = lineEditUserName->text();
    this->password = lineEditPassword->text();
    this->dbname = lineEditDBName->text();
    this->hostip = lineEditHostIP->text();
    isLogin = true;//  只有用户点击了确定按钮，islogin的值才是true，否则一律为假
    close();
}

void loginDlg::logoutBtnOnClick()
{
    close();
   // QMessageBox::information(this,"hello", "logout", "YES", "NO");
}
