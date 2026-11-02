/********************************************************************************
** Form generated from reading UI file 'orderquerywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERQUERYWIDGET_H
#define UI_ORDERQUERYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderQueryWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *btnQuery;
    QLineEdit *editOrderNo;
    QDateEdit *dateStart;
    QDateEdit *dateEnd;
    QCheckBox *chkDateEnable;
    QPushButton *btnReset;
    QComboBox *cbOrderStatus;
    QComboBox *cbCustName;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableViewOrder;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableViewItem;
    QLabel *label_6;

    void setupUi(QWidget *OrderQueryWidget)
    {
        if (OrderQueryWidget->objectName().isEmpty())
            OrderQueryWidget->setObjectName("OrderQueryWidget");
        OrderQueryWidget->resize(666, 435);
        verticalLayout = new QVBoxLayout(OrderQueryWidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(OrderQueryWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        label_2->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        label_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        label_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setFont(font);
        label_5->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        label_5->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        btnQuery = new QPushButton(groupBox);
        btnQuery->setObjectName("btnQuery");

        gridLayout->addWidget(btnQuery, 0, 6, 1, 1);

        editOrderNo = new QLineEdit(groupBox);
        editOrderNo->setObjectName("editOrderNo");

        gridLayout->addWidget(editOrderNo, 1, 0, 1, 1);

        dateStart = new QDateEdit(groupBox);
        dateStart->setObjectName("dateStart");
        dateStart->setEnabled(false);
        dateStart->setDateTime(QDateTime(QDate(1999, 12, 31), QTime(8, 0, 1)));

        gridLayout->addWidget(dateStart, 1, 2, 1, 1);

        dateEnd = new QDateEdit(groupBox);
        dateEnd->setObjectName("dateEnd");
        dateEnd->setEnabled(false);
        dateEnd->setDateTime(QDateTime(QDate(1999, 12, 31), QTime(0, 0, 1)));

        gridLayout->addWidget(dateEnd, 1, 3, 1, 1);

        chkDateEnable = new QCheckBox(groupBox);
        chkDateEnable->setObjectName("chkDateEnable");

        gridLayout->addWidget(chkDateEnable, 1, 5, 1, 1);

        btnReset = new QPushButton(groupBox);
        btnReset->setObjectName("btnReset");

        gridLayout->addWidget(btnReset, 1, 6, 1, 1);

        cbOrderStatus = new QComboBox(groupBox);
        cbOrderStatus->setObjectName("cbOrderStatus");

        gridLayout->addWidget(cbOrderStatus, 1, 4, 1, 1);

        cbCustName = new QComboBox(groupBox);
        cbCustName->setObjectName("cbCustName");

        gridLayout->addWidget(cbCustName, 1, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(OrderQueryWidget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName("horizontalLayout");
        tableViewOrder = new QTableView(groupBox_2);
        tableViewOrder->setObjectName("tableViewOrder");

        horizontalLayout->addWidget(tableViewOrder);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(OrderQueryWidget);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tableViewItem = new QTableView(groupBox_3);
        tableViewItem->setObjectName("tableViewItem");

        horizontalLayout_2->addWidget(tableViewItem);


        verticalLayout->addWidget(groupBox_3);

        label_6 = new QLabel(OrderQueryWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);


        retranslateUi(OrderQueryWidget);

        QMetaObject::connectSlotsByName(OrderQueryWidget);
    } // setupUi

    void retranslateUi(QWidget *OrderQueryWidget)
    {
        OrderQueryWidget->setWindowTitle(QCoreApplication::translate("OrderQueryWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OrderQueryWidget", "\350\256\242\345\215\225\347\255\233\351\200\211", nullptr));
        label->setText(QCoreApplication::translate("OrderQueryWidget", "\350\256\242\345\215\225\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("OrderQueryWidget", "\345\256\242\346\210\267\345\220\215\347\247\260(\345\205\254\345\217\270)", nullptr));
        label_3->setText(QCoreApplication::translate("OrderQueryWidget", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        label_4->setText(QCoreApplication::translate("OrderQueryWidget", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("OrderQueryWidget", "\350\256\242\345\215\225\347\212\266\346\200\201", nullptr));
        btnQuery->setText(QCoreApplication::translate("OrderQueryWidget", "\346\237\245\350\257\242", nullptr));
        editOrderNo->setPlaceholderText(QCoreApplication::translate("OrderQueryWidget", "\350\257\267\350\276\223\345\205\245\350\256\242\345\215\225\345\217\267\357\274\232", nullptr));
        chkDateEnable->setText(QCoreApplication::translate("OrderQueryWidget", "\345\220\257\347\224\250\346\227\266\351\227\264\347\255\233\351\200\211", nullptr));
        btnReset->setText(QCoreApplication::translate("OrderQueryWidget", "\351\207\215\347\275\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("OrderQueryWidget", "\346\237\245\350\257\242\350\256\242\345\215\225\344\270\273\350\241\250", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("OrderQueryWidget", "\346\237\245\350\257\242\350\256\242\345\215\225\346\230\216\347\273\206\350\241\250", nullptr));
        label_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OrderQueryWidget: public Ui_OrderQueryWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERQUERYWIDGET_H
