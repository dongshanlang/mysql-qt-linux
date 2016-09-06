#ifndef INSERT_MSCDLG_H
#define INSERT_MSCDLG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>

class insert_mscDlg : public QDialog
{
    Q_OBJECT
public:
    explicit insert_mscDlg(QWidget *parent = 0);

signals:
private:
    QLabel *mscIDLabel, *mscpclable, *mscNameLabel, *districtNameLabel, *createDataLabel, *descriptionLabel;
    QLineEdit * mscid, *mscpc, *mscName, *districtName, *description;
    QPushButton *okBtn, *cancelBtn;
    QDateEdit *createDate;
public:
    QString SQL;
    bool isok;

public slots:
    void okBtnOnClick();
    void cancelBtnOnClick();

};

#endif // INSERT_MSCDLG_H
