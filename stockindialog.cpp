#include "stockindialog.h"
#include "ui_stockindialog.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include "dbmanager.h"
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

void StockInDialog::loadSteelSpecCombo()
{
    ui->comboBox->clear();
    auto &db = DBManager::instance().getDB();
    QSqlQuery query(db);

    // 左连接steel_type拿到typeName
    query.prepare(R"(
        SELECT s.specId, s.typeId, s.material, s.size, t.typeName
        FROM steel_spec s
        LEFT JOIN steel_type t ON s.typeId = t.typeId
        ORDER BY t.typeName, s.material, s.size
    )");

    if (!query.exec())
    {
        qDebug() << "查询失败:" << query.lastError().text();
        return;
    }

    while (query.next())
    {
        int specId = query.value("specId").toInt();
        int typeId = query.value("typeId").toInt();
        QString typeName = query.value("typeName").toString();
        QString material = query.value("material").toString();
        QString size = query.value("size").toString();

        // 兜底：类型为空显示未知钢材
        if(typeName.isEmpty())
            typeName = "未知钢材";

        // 拼接：螺纹钢 HRB400 Φ12
        QString showText = QString("%1 %2 %3").arg(typeName).arg(material).arg(size);

        QVariantMap map;
        map["specId"] = specId;
        map["typeId"] = typeId;
        ui->comboBox->addItem(showText, map);
    }
}

int StockInDialog::getSpecId()
{
    QVariantMap map = ui->comboBox->currentData().toMap();
    return map["specId"].toInt();
}

int StockInDialog::getTypeId()
{
    QVariantMap map = ui->comboBox->currentData().toMap();
    return map["typeId"].toInt();
}

double StockInDialog::getStockNum()
{
    bool ok = false;
    double num = ui->lineEdit->text().toDouble(&ok);
    if(!ok) return 0;
    return num;
}

double StockInDialog::getCostPrice()
{
    bool ok = false;
    double price = ui->editCost->text().toDouble(&ok);
    if(!ok) return 0;
    return price;
}

// 确认按钮校验
void StockInDialog::on_btnOk_clicked()
{
    bool okNum, okPrice;
    double num = ui->lineEdit->text().toDouble(&okNum);
    double price = ui->editCost->text().toDouble(&okPrice);

    if(ui->comboBox->currentIndex() < 0)
    {
        QMessageBox::warning(this,"提示","没有可选钢材规格！");
        return;
    }
    if(ui->lineEdit->text().isEmpty()||!okNum || num <= 0)
    {
        QMessageBox::warning(this,"提示","入库数量必须是大于0的数字！");
        return;
    }
    if(ui->editCost->text().isEmpty()||!okPrice || price <= 0)
    {
        QMessageBox::warning(this,"提示","成本单价不能为空且必须大于0！");
        return;
    }
    accept();
}


