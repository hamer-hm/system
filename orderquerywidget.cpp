#include "orderquerywidget.h"
#include "ui_orderquerywidget.h"

OrderQueryWidget::OrderQueryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderQueryWidget)
{
    ui->setupUi(this);
}

OrderQueryWidget::~OrderQueryWidget()
{
    delete ui;
}
