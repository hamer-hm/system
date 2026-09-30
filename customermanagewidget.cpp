#include "customermanagewidget.h"
#include "ui_customermanagewidget.h"

CustomerManageWidget::CustomerManageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerManageWidget)
{
    ui->setupUi(this);
}

CustomerManageWidget::~CustomerManageWidget()
{
    delete ui;
}
