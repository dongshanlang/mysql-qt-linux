#ifndef SCRIPTDLG_H
#define SCRIPTDLG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
class scriptDlg : public QDialog
{
    Q_OBJECT
public:
    explicit scriptDlg(QWidget *parent = 0);
    QString SQL;
    bool isLogin;

signals:

public slots:

private:
    QLabel *lable0;
    QTextEdit *textEditSQL;
    QPushButton *okBtn, *cancelBtn;

private slots:
    void okBtnOnClick();
    void cancelBtnOnClick();

};

#endif // SCRIPTDLG_H
