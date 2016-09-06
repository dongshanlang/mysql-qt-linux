#ifndef SELECT_MSGDLG_H
#define SELECT_MSGDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Select_msgDlg : public QDialog
{
    Q_OBJECT
public:
    explicit Select_msgDlg(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *macidlabel;
    QLineEdit *mscid;

    QPushButton *okBtn;
    QPushButton *cancelBtn;

private slots:
    void okBtnOnClick();
    void cancelBtnOnClick();
public:
    QString SQL;
    bool isok;
};

#endif // SELECT_MSGDLG_H
