#include "systemsettingswidget.h"
#include "ui_systemsettingswidget.h"

SystemSettingsWidget::SystemSettingsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SystemSettingsWidget)
{
    ui->setupUi(this);
}

SystemSettingsWidget::~SystemSettingsWidget()
{
    delete ui;
}
