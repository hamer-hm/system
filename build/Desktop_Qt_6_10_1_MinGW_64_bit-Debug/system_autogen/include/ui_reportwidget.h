/********************************************************************************
** Form generated from reading UI file 'reportwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWIDGET_H
#define UI_REPORTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnQueryReport;
    QDateEdit *dateStart;
    QDateEdit *dateEnd;
    QComboBox *cbReportType;
    QPushButton *btnExportCsv;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lblOrderCount;
    QLabel *lblTotalMoney;
    QLabel *lblTotalWeight;

    void setupUi(QWidget *ReportWidget)
    {
        if (ReportWidget->objectName().isEmpty())
            ReportWidget->setObjectName("ReportWidget");
        ReportWidget->resize(589, 398);
        verticalLayout = new QVBoxLayout(ReportWidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(ReportWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        btnQueryReport = new QPushButton(groupBox);
        btnQueryReport->setObjectName("btnQueryReport");

        gridLayout->addWidget(btnQueryReport, 0, 3, 1, 1);

        dateStart = new QDateEdit(groupBox);
        dateStart->setObjectName("dateStart");

        gridLayout->addWidget(dateStart, 1, 0, 1, 1);

        dateEnd = new QDateEdit(groupBox);
        dateEnd->setObjectName("dateEnd");

        gridLayout->addWidget(dateEnd, 1, 1, 1, 1);

        cbReportType = new QComboBox(groupBox);
        cbReportType->setObjectName("cbReportType");

        gridLayout->addWidget(cbReportType, 1, 2, 1, 1);

        btnExportCsv = new QPushButton(groupBox);
        btnExportCsv->setObjectName("btnExportCsv");

        gridLayout->addWidget(btnExportCsv, 1, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ReportWidget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName("horizontalLayout");
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName("tableView");

        horizontalLayout->addWidget(tableView);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(ReportWidget);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 0, 2, 1, 1);

        lblOrderCount = new QLabel(groupBox_3);
        lblOrderCount->setObjectName("lblOrderCount");

        gridLayout_2->addWidget(lblOrderCount, 1, 0, 1, 1);

        lblTotalMoney = new QLabel(groupBox_3);
        lblTotalMoney->setObjectName("lblTotalMoney");

        gridLayout_2->addWidget(lblTotalMoney, 1, 1, 1, 1);

        lblTotalWeight = new QLabel(groupBox_3);
        lblTotalWeight->setObjectName("lblTotalWeight");

        gridLayout_2->addWidget(lblTotalWeight, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_3);


        retranslateUi(ReportWidget);

        QMetaObject::connectSlotsByName(ReportWidget);
    } // setupUi

    void retranslateUi(QWidget *ReportWidget)
    {
        ReportWidget->setWindowTitle(QCoreApplication::translate("ReportWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ReportWidget", "\347\255\233\351\200\211\345\214\272\345\237\237", nullptr));
        label->setText(QCoreApplication::translate("ReportWidget", "\350\265\267\345\247\213\346\227\245\346\234\237", nullptr));
        label_2->setText(QCoreApplication::translate("ReportWidget", "\347\273\223\346\235\237\346\227\245\346\234\237", nullptr));
        label_3->setText(QCoreApplication::translate("ReportWidget", "\346\212\245\350\241\250\347\261\273\345\236\213", nullptr));
        btnQueryReport->setText(QCoreApplication::translate("ReportWidget", "\347\224\237\346\210\220\346\212\245\350\241\250", nullptr));
        btnExportCsv->setText(QCoreApplication::translate("ReportWidget", "\345\257\274\345\207\272 CSV \346\226\207\344\273\266", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ReportWidget", "\346\212\245\350\241\250\351\242\204\350\247\210\345\214\272", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ReportWidget", "\346\261\207\346\200\273\347\273\237\350\256\241", nullptr));
        label_4->setText(QCoreApplication::translate("ReportWidget", "\350\256\242\345\215\225\346\200\273\346\225\260", nullptr));
        label_5->setText(QCoreApplication::translate("ReportWidget", "\346\200\273\351\207\221\351\242\235", nullptr));
        label_6->setText(QCoreApplication::translate("ReportWidget", "\346\200\273\345\220\250\346\225\260", nullptr));
        lblOrderCount->setText(QCoreApplication::translate("ReportWidget", "0", nullptr));
        lblTotalMoney->setText(QCoreApplication::translate("ReportWidget", "0.00", nullptr));
        lblTotalWeight->setText(QCoreApplication::translate("ReportWidget", "0.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportWidget: public Ui_ReportWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTWIDGET_H
