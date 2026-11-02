/********************************************************************************
** Form generated from reading UI file 'saleorderwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALEORDERWIDGET_H
#define UI_SALEORDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_SaleOrderWidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *custName;
    QLabel *label;
    QLineEdit *orderNm;
    QLabel *label_2;
    QComboBox *comStatus;
    QLabel *label_5;
    QLineEdit *editContact;
    QLabel *label_6;
    QLineEdit *editPhone;
    QLabel *label_3;
    QLineEdit *editRemark;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnAdd;
    QPushButton *btnDelete;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *editNumAmount;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLineEdit *editTotalAmount;
    QVBoxLayout *verticalLayout;
    QPushButton *btnOk;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SaleOrderWidget)
    {
        if (SaleOrderWidget->objectName().isEmpty())
            SaleOrderWidget->setObjectName("SaleOrderWidget");
        SaleOrderWidget->resize(616, 392);
        horizontalLayout_5 = new QHBoxLayout(SaleOrderWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(SaleOrderWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 0, 2, 1);

        custName = new QComboBox(groupBox);
        custName->setObjectName("custName");

        gridLayout->addWidget(custName, 0, 1, 2, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 2, 1, 1);

        orderNm = new QLineEdit(groupBox);
        orderNm->setObjectName("orderNm");
        orderNm->setEnabled(false);

        gridLayout->addWidget(orderNm, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 2, 2, 1);

        comStatus = new QComboBox(groupBox);
        comStatus->addItem(QString());
        comStatus->addItem(QString());
        comStatus->addItem(QString());
        comStatus->setObjectName("comStatus");

        gridLayout->addWidget(comStatus, 1, 3, 2, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        editContact = new QLineEdit(groupBox);
        editContact->setObjectName("editContact");
        editContact->setEnabled(false);

        gridLayout->addWidget(editContact, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        editPhone = new QLineEdit(groupBox);
        editPhone->setObjectName("editPhone");
        editPhone->setEnabled(false);

        gridLayout->addWidget(editPhone, 3, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 2, 1, 1);

        editRemark = new QLineEdit(groupBox);
        editRemark->setObjectName("editRemark");

        gridLayout->addWidget(editRemark, 3, 3, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SaleOrderWidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName("tableView");

        horizontalLayout_2->addWidget(tableView);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        btnAdd = new QPushButton(groupBox_2);
        btnAdd->setObjectName("btnAdd");

        verticalLayout_3->addWidget(btnAdd);

        btnDelete = new QPushButton(groupBox_2);
        btnDelete->setObjectName("btnDelete");

        verticalLayout_3->addWidget(btnDelete);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_7 = new QLabel(SaleOrderWidget);
        label_7->setObjectName("label_7");

        horizontalLayout->addWidget(label_7);

        editNumAmount = new QLineEdit(SaleOrderWidget);
        editNumAmount->setObjectName("editNumAmount");
        editNumAmount->setEnabled(false);

        horizontalLayout->addWidget(editNumAmount);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_8 = new QLabel(SaleOrderWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_3->addWidget(label_8);

        editTotalAmount = new QLineEdit(SaleOrderWidget);
        editTotalAmount->setObjectName("editTotalAmount");
        editTotalAmount->setEnabled(false);

        horizontalLayout_3->addWidget(editTotalAmount);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btnOk = new QPushButton(SaleOrderWidget);
        btnOk->setObjectName("btnOk");

        verticalLayout->addWidget(btnOk);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);


        retranslateUi(SaleOrderWidget);

        QMetaObject::connectSlotsByName(SaleOrderWidget);
    } // setupUi

    void retranslateUi(QWidget *SaleOrderWidget)
    {
        SaleOrderWidget->setWindowTitle(QCoreApplication::translate("SaleOrderWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SaleOrderWidget", "\345\215\225\346\215\256\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("SaleOrderWidget", "\345\205\254\345\217\270\345\220\215\347\247\260\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SaleOrderWidget", "\350\256\242\345\215\225\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SaleOrderWidget", "\350\256\242\345\215\225\347\212\266\346\200\201", nullptr));
        comStatus->setItemText(0, QCoreApplication::translate("SaleOrderWidget", "\345\267\262\347\273\223\347\256\227", nullptr));
        comStatus->setItemText(1, QCoreApplication::translate("SaleOrderWidget", "\346\234\252\347\273\223\347\256\227", nullptr));
        comStatus->setItemText(2, QCoreApplication::translate("SaleOrderWidget", "\345\267\262\345\207\272\345\272\223", nullptr));

        label_5->setText(QCoreApplication::translate("SaleOrderWidget", "\350\201\224\347\263\273\344\272\272\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("SaleOrderWidget", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("SaleOrderWidget", "\345\244\207\346\263\250\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SaleOrderWidget", "\351\224\200\345\224\256\346\230\216\347\273\206", nullptr));
        btnAdd->setText(QCoreApplication::translate("SaleOrderWidget", "\346\267\273\345\212\240\344\270\200\350\241\214", nullptr));
        btnDelete->setText(QCoreApplication::translate("SaleOrderWidget", "\345\210\240\351\231\244\344\270\200\350\241\214", nullptr));
        label_7->setText(QCoreApplication::translate("SaleOrderWidget", "\346\200\273\346\225\260\351\207\217\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("SaleOrderWidget", "\346\200\273\351\207\221\351\242\235\357\274\232", nullptr));
        btnOk->setText(QCoreApplication::translate("SaleOrderWidget", "\345\274\200\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaleOrderWidget: public Ui_SaleOrderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALEORDERWIDGET_H
