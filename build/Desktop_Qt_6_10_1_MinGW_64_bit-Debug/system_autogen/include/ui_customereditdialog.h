/********************************************************************************
** Form generated from reading UI file 'customereditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMEREDITDIALOG_H
#define UI_CUSTOMEREDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CustomerEditDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *editCustName;
    QLineEdit *editCustCode;
    QLabel *label_2;
    QLineEdit *editPhone;
    QLineEdit *editAddress;
    QLineEdit *editContact;
    QLabel *label_6;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *editRemark;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CustomerEditDialog)
    {
        if (CustomerEditDialog->objectName().isEmpty())
            CustomerEditDialog->setObjectName("CustomerEditDialog");
        CustomerEditDialog->resize(400, 300);
        gridLayout = new QGridLayout(CustomerEditDialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(CustomerEditDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(CustomerEditDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(CustomerEditDialog);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        editCustName = new QLineEdit(CustomerEditDialog);
        editCustName->setObjectName("editCustName");

        gridLayout->addWidget(editCustName, 1, 1, 1, 1);

        editCustCode = new QLineEdit(CustomerEditDialog);
        editCustCode->setObjectName("editCustCode");

        gridLayout->addWidget(editCustCode, 0, 1, 1, 1);

        label_2 = new QLabel(CustomerEditDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        editPhone = new QLineEdit(CustomerEditDialog);
        editPhone->setObjectName("editPhone");

        gridLayout->addWidget(editPhone, 3, 1, 1, 1);

        editAddress = new QLineEdit(CustomerEditDialog);
        editAddress->setObjectName("editAddress");

        gridLayout->addWidget(editAddress, 4, 1, 1, 1);

        editContact = new QLineEdit(CustomerEditDialog);
        editContact->setObjectName("editContact");

        gridLayout->addWidget(editContact, 2, 1, 1, 1);

        label_6 = new QLabel(CustomerEditDialog);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        label_4 = new QLabel(CustomerEditDialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(CustomerEditDialog);
        btnSave->setObjectName("btnSave");

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(CustomerEditDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 2);

        editRemark = new QLineEdit(CustomerEditDialog);
        editRemark->setObjectName("editRemark");

        gridLayout->addWidget(editRemark, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);


        retranslateUi(CustomerEditDialog);

        QMetaObject::connectSlotsByName(CustomerEditDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomerEditDialog)
    {
        CustomerEditDialog->setWindowTitle(QCoreApplication::translate("CustomerEditDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CustomerEditDialog", "\345\256\242\346\210\267\347\274\226\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("CustomerEditDialog", "\350\201\224\347\263\273\344\272\272", nullptr));
        label_5->setText(QCoreApplication::translate("CustomerEditDialog", "\345\244\207\346\263\250", nullptr));
        label_2->setText(QCoreApplication::translate("CustomerEditDialog", "\345\256\242\346\210\267\345\220\215\347\247\260", nullptr));
        label_6->setText(QCoreApplication::translate("CustomerEditDialog", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        label_4->setText(QCoreApplication::translate("CustomerEditDialog", "\345\234\260\345\235\200", nullptr));
        btnSave->setText(QCoreApplication::translate("CustomerEditDialog", "\344\277\235\345\255\230", nullptr));
        btnCancel->setText(QCoreApplication::translate("CustomerEditDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerEditDialog: public Ui_CustomerEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMEREDITDIALOG_H
