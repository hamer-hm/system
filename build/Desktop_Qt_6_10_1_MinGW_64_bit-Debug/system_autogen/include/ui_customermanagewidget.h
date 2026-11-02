/********************************************************************************
** Form generated from reading UI file 'customermanagewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERMANAGEWIDGET_H
#define UI_CUSTOMERMANAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerManageWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *editCustName;
    QLineEdit *editPhone;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QPushButton *btnQuery;
    QPushButton *btnReset;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CustomerManageWidget)
    {
        if (CustomerManageWidget->objectName().isEmpty())
            CustomerManageWidget->setObjectName("CustomerManageWidget");
        CustomerManageWidget->resize(647, 407);
        verticalLayout_3 = new QVBoxLayout(CustomerManageWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(CustomerManageWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        editCustName = new QLineEdit(groupBox);
        editCustName->setObjectName("editCustName");

        gridLayout->addWidget(editCustName, 1, 0, 1, 1);

        editPhone = new QLineEdit(groupBox);
        editPhone->setObjectName("editPhone");

        gridLayout->addWidget(editPhone, 1, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_4 = new QLabel(CustomerManageWidget);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        btnQuery = new QPushButton(CustomerManageWidget);
        btnQuery->setObjectName("btnQuery");

        verticalLayout_2->addWidget(btnQuery);

        btnReset = new QPushButton(CustomerManageWidget);
        btnReset->setObjectName("btnReset");

        verticalLayout_2->addWidget(btnReset);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        groupBox_2 = new QGroupBox(CustomerManageWidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName("tableView");

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(CustomerManageWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        btnAdd = new QPushButton(CustomerManageWidget);
        btnAdd->setObjectName("btnAdd");

        verticalLayout->addWidget(btnAdd);

        btnEdit = new QPushButton(CustomerManageWidget);
        btnEdit->setObjectName("btnEdit");

        verticalLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(CustomerManageWidget);
        btnDelete->setObjectName("btnDelete");

        verticalLayout->addWidget(btnDelete);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(1, 1);

        retranslateUi(CustomerManageWidget);

        QMetaObject::connectSlotsByName(CustomerManageWidget);
    } // setupUi

    void retranslateUi(QWidget *CustomerManageWidget)
    {
        CustomerManageWidget->setWindowTitle(QCoreApplication::translate("CustomerManageWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CustomerManageWidget", "\345\256\242\346\210\267\347\255\233\351\200\211", nullptr));
        label->setText(QCoreApplication::translate("CustomerManageWidget", "\345\256\242\346\210\267\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerManageWidget", "\345\256\242\346\210\267\347\224\265\350\257\235", nullptr));
        label_4->setText(QString());
        btnQuery->setText(QCoreApplication::translate("CustomerManageWidget", "\346\237\245\350\257\242", nullptr));
        btnReset->setText(QCoreApplication::translate("CustomerManageWidget", "\351\207\215\347\275\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CustomerManageWidget", "\345\256\242\346\210\267\345\210\227\350\241\250", nullptr));
        label_3->setText(QString());
        btnAdd->setText(QCoreApplication::translate("CustomerManageWidget", "\346\226\260\345\242\236\345\256\242\346\210\267", nullptr));
        btnEdit->setText(QCoreApplication::translate("CustomerManageWidget", "\347\274\226\350\276\221\345\256\242\346\210\267", nullptr));
        btnDelete->setText(QCoreApplication::translate("CustomerManageWidget", "\345\210\240\351\231\244\345\256\242\346\210\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerManageWidget: public Ui_CustomerManageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERMANAGEWIDGET_H
