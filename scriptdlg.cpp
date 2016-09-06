#include "scriptdlg.h"
#include <QGridLayout>
#include <QHBoxLayout>

scriptDlg::scriptDlg(QWidget *parent) :
    QDialog(parent)
{
    isLogin = false;
    lable0 = new QLabel(tr("请输入SQL"));
    textEditSQL = new QTextEdit;
    okBtn = new QPushButton;
    okBtn->setText(tr("执行"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));

    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(lable0, 0, 0);
    layout1->addWidget(textEditSQL, 0, 1);
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(okBtn);
    layout2->addWidget(cancelBtn);
    layout1->addLayout(layout2, 1, 1);


    connect(okBtn, SIGNAL(clicked()), this, SLOT(okBtnOnClick()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(cancelBtnOnClick()));

}

void scriptDlg::okBtnOnClick()
{
    SQL = textEditSQL->toPlainText();//textEdit没有text函数，得到textEdit当中的用户输入的函数是toPlainText；
    isLogin = true;
    close();
}

void scriptDlg::cancelBtnOnClick()
{
    close();
}
