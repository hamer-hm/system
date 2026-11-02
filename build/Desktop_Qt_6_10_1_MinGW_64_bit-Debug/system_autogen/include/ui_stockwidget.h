/********************************************************************************
** Form generated from reading UI file 'stockwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWIDGET_H
#define UI_STOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *btnStockIn;
    QPushButton *btnStockDel;
    QPushButton *btnStockExport;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *StockWidget)
    {
        if (StockWidget->objectName().isEmpty())
            StockWidget->setObjectName("StockWidget");
        StockWidget->resize(400, 300);
        StockWidget->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(StockWidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(StockWidget);
        tableView->setObjectName("tableView");
        tableView->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btnStockIn = new QPushButton(StockWidget);
        btnStockIn->setObjectName("btnStockIn");

        verticalLayout->addWidget(btnStockIn);

        btnStockDel = new QPushButton(StockWidget);
        btnStockDel->setObjectName("btnStockDel");

        verticalLayout->addWidget(btnStockDel);

        btnStockExport = new QPushButton(StockWidget);
        btnStockExport->setObjectName("btnStockExport");

        verticalLayout->addWidget(btnStockExport);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(StockWidget);

        QMetaObject::connectSlotsByName(StockWidget);
    } // setupUi

    void retranslateUi(QWidget *StockWidget)
    {
        StockWidget->setWindowTitle(QCoreApplication::translate("StockWidget", "Form", nullptr));
        btnStockIn->setText(QCoreApplication::translate("StockWidget", "\345\205\245\345\272\223", nullptr));
        btnStockDel->setText(QCoreApplication::translate("StockWidget", "\345\210\240\351\231\244", nullptr));
        btnStockExport->setText(QCoreApplication::translate("StockWidget", "\345\257\274\345\207\272CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StockWidget: public Ui_StockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWIDGET_H
