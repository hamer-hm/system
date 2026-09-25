#include "stockindialog.h"
#include "ui_stockindialog.h"
#include<QSqlQuery>
StockInDialog::StockInDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StockInDialog)
{
    ui->setupUi(this);
    setWindowTitle("填写入库信息");
    loadSteelSpecCombo();
}

StockInDialog::~StockInDialog()
{
    delete ui;
}

//加载钢材规格下拉框，显示名称，存specId
void StockInDialog::loadSteelSpecCombo()
{
    QSqlQuery query("SELECT typeId, typeName FROM steel_type");
    while(query.next())
    {
        int typeId = query.value("typeId").toInt();
        QString name = query.value("typeName").toString();
        ui->comboBox->addItem(name, typeId);
    }
}

//获取typeId
int StockInDialog::getTypeId()
{
    int typeId=ui->comboBox->currentData().toInt();
    return typeId;
}

//获取StockNum
double StockInDialog::getStockNum()
{
    double stockNum=ui->lineEdit->text().toInt();
    return stockNum;
}

