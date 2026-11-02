/********************************************************************************
** Form generated from reading UI file 'baseinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEINFOWIDGET_H
#define UI_BASEINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseInfoWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAdd;
    QPushButton *btnDel;
    QPushButton *btnExport;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *BaseInfoWidget)
    {
        if (BaseInfoWidget->objectName().isEmpty())
            BaseInfoWidget->setObjectName("BaseInfoWidget");
        BaseInfoWidget->resize(542, 300);
        horizontalLayout = new QHBoxLayout(BaseInfoWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(BaseInfoWidget);
        tableView->setObjectName("tableView");

        horizontalLayout->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btnAdd = new QPushButton(BaseInfoWidget);
        btnAdd->setObjectName("btnAdd");

        verticalLayout->addWidget(btnAdd);

        btnDel = new QPushButton(BaseInfoWidget);
        btnDel->setObjectName("btnDel");

        verticalLayout->addWidget(btnDel);

        btnExport = new QPushButton(BaseInfoWidget);
        btnExport->setObjectName("btnExport");

        verticalLayout->addWidget(btnExport);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(BaseInfoWidget);

        QMetaObject::connectSlotsByName(BaseInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *BaseInfoWidget)
    {
        BaseInfoWidget->setWindowTitle(QCoreApplication::translate("BaseInfoWidget", "Form", nullptr));
        btnAdd->setText(QCoreApplication::translate("BaseInfoWidget", "\346\267\273\345\212\240\344\270\200\350\241\214", nullptr));
        btnDel->setText(QCoreApplication::translate("BaseInfoWidget", "\345\210\240\351\231\244\344\270\200\350\241\214", nullptr));
        btnExport->setText(QCoreApplication::translate("BaseInfoWidget", "\345\257\274\345\207\272csv", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BaseInfoWidget: public Ui_BaseInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEINFOWIDGET_H
