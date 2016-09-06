#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(700,500);//改变主窗口大小，一般是在main函数当中修改的.
    w.show();

    return a.exec();
}
