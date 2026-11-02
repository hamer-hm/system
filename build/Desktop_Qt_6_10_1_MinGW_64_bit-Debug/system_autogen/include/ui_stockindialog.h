/********************************************************************************
** Form generated from reading UI file 'stockindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKINDIALOG_H
#define UI_STOCKINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StockInDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *editCost;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *StockInDialog)
    {
        if (StockInDialog->objectName().isEmpty())
            StockInDialog->setObjectName("StockInDialog");
        StockInDialog->resize(177, 195);
        verticalLayout = new QVBoxLayout(StockInDialog);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(StockInDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(StockInDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(StockInDialog);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        comboBox = new QComboBox(StockInDialog);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_3 = new QLabel(StockInDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        editCost = new QLineEdit(StockInDialog);
        editCost->setObjectName("editCost");

        gridLayout->addWidget(editCost, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnOk = new QPushButton(StockInDialog);
        btnOk->setObjectName("btnOk");

        horizontalLayout->addWidget(btnOk);

        btnCancel = new QPushButton(StockInDialog);
        btnCancel->setObjectName("btnCancel");

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(StockInDialog);
        QObject::connect(btnOk, &QPushButton::clicked, StockInDialog, qOverload<>(&QDialog::accept));
        QObject::connect(btnCancel, &QPushButton::clicked, StockInDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StockInDialog);
    } // setupUi

    void retranslateUi(QDialog *StockInDialog)
    {
        StockInDialog->setWindowTitle(QCoreApplication::translate("StockInDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("StockInDialog", "\351\222\242\346\235\220\350\247\204\346\240\274", nullptr));
        label_2->setText(QCoreApplication::translate("StockInDialog", "\345\205\245\345\272\223\346\225\260\351\207\217", nullptr));
        label_3->setText(QCoreApplication::translate("StockInDialog", "\346\210\220\346\234\254\345\215\225\344\273\267", nullptr));
        btnOk->setText(QCoreApplication::translate("StockInDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("StockInDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StockInDialog: public Ui_StockInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKINDIALOG_H
