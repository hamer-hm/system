#include "mainwindow.h"

#include <QApplication>
#include<QFile>
int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("MyCompany");
    QCoreApplication::setApplicationName("SteelSales");
    QApplication a(argc, argv);
    MainWindow w;
    QFile styleFile(":/style/style.qss");
    if(styleFile.open(QIODevice::ReadOnly))
    {
        QString qss=QString(styleFile.readAll());
         a.setStyleSheet(qss);
    }
    w.show();
    return a.exec();
}
