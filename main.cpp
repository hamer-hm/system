#include "mainwindow.h"
#include"logindialog.h"
#include <QApplication>
#include<QFile>
int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("MyCompany");
    QCoreApplication::setApplicationName("SteelSales");
    QApplication a(argc, argv);
    LoginDialog dlg;

    QFile styleFile(":/style/style.qss");
    if(styleFile.open(QIODevice::ReadOnly))
    {
        QString qss=QString(styleFile.readAll());
        dlg.setStyleSheet(qss);
        a.setStyleSheet(qss);
    }
    dlg.show();
    if(dlg.exec() != QDialog::Accepted){
        return 0; // 用户点取消，直接退出
    }
    MainWindow w;
    w.show();
    return a.exec();
}
