/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <baseinfowidget.h>
#include <customermanagewidget.h>
#include <orderquerywidget.h>
#include <reportwidget.h>
#include <saleorderwidget.h>
#include <systemsettingswidget.h>
#include "stockwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    BaseInfoWidget *page_BaseInfo;
    QHBoxLayout *horizontalLayout_3;
    StockWidget *page_Stock;
    SaleOrderWidget *page_SaleCreate;
    OrderQueryWidget *page_OrderQuery;
    CustomerManageWidget *page_Customer;
    ReportWidget *page_Report;
    SystemSettingsWidget *page_Setting;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QToolButton *btn_BaseInfo;
    QToolButton *btn_Stockton;
    QToolButton *btn_SaleCreate;
    QToolButton *btn_OrderQuery;
    QToolButton *btn_Customer;
    QToolButton *btn_Report;
    QToolButton *btn_Setting;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(976, 396);
        MainWindow->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/mainwindow\345\233\276\346\240\207.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(900, 0));
        page_BaseInfo = new BaseInfoWidget();
        page_BaseInfo->setObjectName("page_BaseInfo");
        horizontalLayout_3 = new QHBoxLayout(page_BaseInfo);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        stackedWidget->addWidget(page_BaseInfo);
        page_Stock = new StockWidget();
        page_Stock->setObjectName("page_Stock");
        stackedWidget->addWidget(page_Stock);
        page_SaleCreate = new SaleOrderWidget();
        page_SaleCreate->setObjectName("page_SaleCreate");
        stackedWidget->addWidget(page_SaleCreate);
        page_OrderQuery = new OrderQueryWidget();
        page_OrderQuery->setObjectName("page_OrderQuery");
        stackedWidget->addWidget(page_OrderQuery);
        page_Customer = new CustomerManageWidget();
        page_Customer->setObjectName("page_Customer");
        stackedWidget->addWidget(page_Customer);
        page_Report = new ReportWidget();
        page_Report->setObjectName("page_Report");
        stackedWidget->addWidget(page_Report);
        page_Setting = new SystemSettingsWidget();
        page_Setting->setObjectName("page_Setting");
        stackedWidget->addWidget(page_Setting);

        gridLayout->addWidget(stackedWidget, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(60, 0));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 2, 0, 2);
        btn_BaseInfo = new QToolButton(widget);
        btn_BaseInfo->setObjectName("btn_BaseInfo");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/\345\210\227\350\241\250\346\241\243\346\241\210.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_BaseInfo->setIcon(icon1);
        btn_BaseInfo->setIconSize(QSize(24, 24));
        btn_BaseInfo->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(btn_BaseInfo);

        btn_Stockton = new QToolButton(widget);
        btn_Stockton->setObjectName("btn_Stockton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/\344\273\223\345\272\223_\345\272\223\345\255\230.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Stockton->setIcon(icon2);
        btn_Stockton->setIconSize(QSize(24, 24));
        btn_Stockton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(btn_Stockton);

        btn_SaleCreate = new QToolButton(widget);
        btn_SaleCreate->setObjectName("btn_SaleCreate");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/\346\226\260\345\273\272\345\215\225\346\215\256.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_SaleCreate->setIcon(icon3);
        btn_SaleCreate->setIconSize(QSize(24, 24));
        btn_SaleCreate->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(btn_SaleCreate);

        btn_OrderQuery = new QToolButton(widget);
        btn_OrderQuery->setObjectName("btn_OrderQuery");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/\345\215\225\346\215\256\350\257\246\346\203\205.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_OrderQuery->setIcon(icon4);
        btn_OrderQuery->setIconSize(QSize(24, 24));
        btn_OrderQuery->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(btn_OrderQuery);

        btn_Customer = new QToolButton(widget);
        btn_Customer->setObjectName("btn_Customer");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/\345\256\242\346\210\267.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Customer->setIcon(icon5);
        btn_Customer->setIconSize(QSize(24, 24));
        btn_Customer->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(btn_Customer);

        btn_Report = new QToolButton(widget);
        btn_Report->setObjectName("btn_Report");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/\346\212\245\350\241\250\347\273\237\350\256\241.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Report->setIcon(icon6);
        btn_Report->setIconSize(QSize(24, 24));
        btn_Report->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(btn_Report);

        btn_Setting = new QToolButton(widget);
        btn_Setting->setObjectName("btn_Setting");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/\350\256\276\347\275\256.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_Setting->setIcon(icon7);
        btn_Setting->setIconSize(QSize(24, 24));
        btn_Setting->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        verticalLayout->addWidget(btn_Setting);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\222\242\351\223\201\351\224\200\345\224\256\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btn_BaseInfo->setText(QCoreApplication::translate("MainWindow", "\345\237\272\347\241\200\350\265\204\346\226\231", nullptr));
        btn_Stockton->setText(QCoreApplication::translate("MainWindow", "\345\272\223\345\255\230\347\256\241\347\220\206", nullptr));
        btn_SaleCreate->setText(QCoreApplication::translate("MainWindow", "\351\224\200\345\224\256\345\274\200\345\215\225", nullptr));
        btn_OrderQuery->setText(QCoreApplication::translate("MainWindow", "\350\256\242\345\215\225\346\237\245\350\257\242", nullptr));
        btn_Customer->setText(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\256\241\347\220\206", nullptr));
        btn_Report->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\212\245\350\241\250", nullptr));
        btn_Setting->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
