#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>


class loginDlg : public QDialog
{
    Q_OBJECT
public:
    explicit loginDlg(QWidget *parent = 0);
private:
    QLabel *label0, *label1, *label2, *label3;
    QLineEdit *lineEditUserName, *lineEditPassword, *lineEditDBName, *lineEditHostIP;
    QPushButton *loginBtn, *logoutBtn;

signals:

public:
    QString userid;
    QString password;
    QString dbname;
    QString hostip;
    bool isLogin;

private slots:
    void loginBtnOnClick();
    void logoutBtnOnClick();
};

#endif // LOGINDLG_H
