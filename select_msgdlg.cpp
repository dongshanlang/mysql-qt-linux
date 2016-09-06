#include "select_msgdlg.h"
#include <QGridLayout>
Select_msgDlg::Select_msgDlg(QWidget *parent) :
    QDialog(parent)
{
    macidlabel = new QLabel;
    macidlabel->setText("请输入查询id");
    mscid = new QLineEdit ;

    okBtn = new QPushButton;
    okBtn->setText("查询");
    cancelBtn = new QPushButton;
    cancelBtn->setText("取消");

    connect(okBtn, SIGNAL(clicked()), this, SLOT(okBtnOnClick()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(cancelBtnOnClick()));

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(macidlabel, 0, 0);
    layout->addWidget(mscid, 0, 1);
    layout->addWidget(okBtn, 1, 0);
    layout->addWidget(cancelBtn, 1, 1);
}

#define SELECTMSC1 "select mscid, mscpc MSC点码, mscname MSC名称, distictname 区域名称, DATE_FORMAT(createdate ,'%Y-%m-%d') 创建时间, description 描述 from mscs"
#define SELECTMSC2 "select mscid, mscpc MSC点码, mscname MSC名称, distictname 区域名称, DATE_FORMAT(createdate ,'%Y-%m-%d') 创建时间, description 描述 from mscs where mscid = %1"


void Select_msgDlg::okBtnOnClick()
{
    isok = true;
    if(mscid->text().trimmed().isEmpty())
    {
        SQL = SELECTMSC1;
    }else
    {
        SQL = QString(SELECTMSC2).arg(mscid->text());
    }
    close();
}

void Select_msgDlg::cancelBtnOnClick()
{

}
