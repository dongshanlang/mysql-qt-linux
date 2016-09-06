#include "insert_mscdlg.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMessageBox>
insert_mscDlg::insert_mscDlg(QWidget *parent) :
    QDialog(parent)
{
    mscIDLabel = new QLabel;
    mscIDLabel->setText("请输入mscid");
    mscpclable= new QLabel;
    mscpclable->setText("请输入msc点码");
    mscNameLabel= new QLabel;
    mscNameLabel->setText("请输入msc名称");
    districtNameLabel= new QLabel;
    districtNameLabel->setText("请输入区域");
    createDataLabel= new QLabel;
    createDataLabel->setText("强选择建立时间");
    descriptionLabel= new QLabel;
    descriptionLabel->setText("请输入建立描述");
    mscid = new QLineEdit;
    mscpc= new QLineEdit;
    mscName= new QLineEdit;
    districtName= new QLineEdit;
    description= new QLineEdit;


    okBtn = new QPushButton;
    okBtn->setText("添加");
    cancelBtn = new QPushButton;
    cancelBtn->setText("取消");
    createDate = new QDateEdit;
    createDate->setDisplayFormat("yyyy-M-d");//设置空间显示的时间格式
    createDate->setDate(QDate::currentDate());//显示时间为当前时间
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(mscIDLabel, 0, 0);
    layout->addWidget(mscid,0, 1);
    layout->addWidget(mscpclable, 1, 0);
    layout->addWidget(mscpc, 1, 1);
    layout->addWidget(mscNameLabel, 2, 0);
    layout->addWidget(mscName, 2, 1);
    layout->addWidget(districtNameLabel, 3, 0);
    layout->addWidget(districtName, 3, 1);
    layout->addWidget(createDataLabel, 4, 0);
    layout->addWidget(createDate, 4, 1);
    layout->addWidget(descriptionLabel, 5, 0);
    layout->addWidget(description, 5, 1);
    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(okBtn);
    layout2->addWidget(cancelBtn);
    layout->addLayout(layout2, 6, 1);

    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 3);

    layout->setMargin(15);
    layout->setSpacing(10);

    connect(okBtn, SIGNAL(clicked()), this, SLOT(okBtnOnClick()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(cancelBtnOnClick()));

    isok = false;
    setWindowIcon(QIcon("main.png"));
    setWindowTitle(tr("添加msc"));
    mscid->setFocus();
}


#define INSERTMSC "insert into mscs (mscid, mscpc, mscname, distictname, createdate, description) values ('%1','%2', '%3', '%4', str_to_date('%5', '%Y-%m-%d %H:%i:%s'),'%6')"
void insert_mscDlg::okBtnOnClick()
{

   SQL = QString(INSERTMSC).arg(mscid->text()).arg(mscpc->text()).arg(mscName->text()).arg(districtName->text()).arg(createDate->text()).arg(description->text());
   QMessageBox::information(this, " ", SQL);
   isok = true;
    close();
}

void insert_mscDlg::cancelBtnOnClick()
{
    close();
}
