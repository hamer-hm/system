/********************************************************************************
** Form generated from reading UI file 'systemsettingswidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSETTINGSWIDGET_H
#define UI_SYSTEMSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemSettingsWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *editOldPswd;
    QLineEdit *editDBPath;
    QLineEdit *editNewPswd;
    QLineEdit *editConfirmPswd;
    QPushButton *btnSave;
    QPushButton *btnBrowse;
    QLabel *label_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLabel *label_511111;

    void setupUi(QWidget *SystemSettingsWidget)
    {
        if (SystemSettingsWidget->objectName().isEmpty())
            SystemSettingsWidget->setObjectName("SystemSettingsWidget");
        SystemSettingsWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(SystemSettingsWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(SystemSettingsWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(SystemSettingsWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        editOldPswd = new QLineEdit(SystemSettingsWidget);
        editOldPswd->setObjectName("editOldPswd");

        gridLayout->addWidget(editOldPswd, 1, 1, 1, 2);

        editDBPath = new QLineEdit(SystemSettingsWidget);
        editDBPath->setObjectName("editDBPath");

        gridLayout->addWidget(editDBPath, 0, 1, 1, 1);

        editNewPswd = new QLineEdit(SystemSettingsWidget);
        editNewPswd->setObjectName("editNewPswd");

        gridLayout->addWidget(editNewPswd, 2, 1, 1, 2);

        editConfirmPswd = new QLineEdit(SystemSettingsWidget);
        editConfirmPswd->setObjectName("editConfirmPswd");

        gridLayout->addWidget(editConfirmPswd, 3, 1, 1, 2);

        btnSave = new QPushButton(SystemSettingsWidget);
        btnSave->setObjectName("btnSave");

        gridLayout->addWidget(btnSave, 4, 1, 1, 2);

        btnBrowse = new QPushButton(SystemSettingsWidget);
        btnBrowse->setObjectName("btnBrowse");

        gridLayout->addWidget(btnBrowse, 0, 2, 1, 1);

        label_3 = new QLabel(SystemSettingsWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(SystemSettingsWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        label_511111 = new QLabel(SystemSettingsWidget);
        label_511111->setObjectName("label_511111");

        horizontalLayout->addWidget(label_511111);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);

        retranslateUi(SystemSettingsWidget);

        QMetaObject::connectSlotsByName(SystemSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *SystemSettingsWidget)
    {
        SystemSettingsWidget->setWindowTitle(QCoreApplication::translate("SystemSettingsWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("SystemSettingsWidget", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("SystemSettingsWidget", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        btnSave->setText(QCoreApplication::translate("SystemSettingsWidget", "\344\277\235\345\255\230", nullptr));
        btnBrowse->setText(QCoreApplication::translate("SystemSettingsWidget", "\346\265\217\350\247\210", nullptr));
        label_3->setText(QCoreApplication::translate("SystemSettingsWidget", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SystemSettingsWidget", "\346\225\260\346\215\256\345\272\223\350\267\257\345\276\204\357\274\232", nullptr));
        label_511111->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SystemSettingsWidget: public Ui_SystemSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTINGSWIDGET_H
