#include "stockwidget.h"
#include "ui_stockwidget.h"
#include"dbmanager.h"
#include<QSqlRelationalTableModel>
#include<QSqlRecord>
#include<QSqlRelationalDelegate>
#include<QSqlError>
StockWidget::StockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockWidget)
{
    ui->setupUi(this);
}

StockWidget::~StockWidget()
{
    delete ui;
}

void StockWidget::loadStockTable()
{
    auto &db=DBManager::instance().getDB();//获取数据库
    m_stockModel=new QSqlRelationalTableModel(this,db);
    m_stockModel->setTable("stock");
    m_stockModel->setEditStrategy(QSqlRelationalTableModel::OnRowChange);

    int specCol = m_stockModel->record().indexOf("typeId");
    m_stockModel->setRelation(specCol, QSqlRelation("steel_type", "typeId", "typeName"));

    m_stockModel->select();


    m_stockModel->setHeaderData(m_stockModel->record().indexOf("stockId"), Qt::Horizontal, "库存ID");
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("typeName"), Qt::Horizontal, "钢材规格");
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("stockNum"), Qt::Horizontal, "库存数量(吨)");
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("costPrice"), Qt::Horizontal, "成本单价");
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("updateTime"), Qt::Horizontal, "更新时间");

    ui->tableView->setModel(m_stockModel);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));//设置代理

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//设置内容宽度自适应

}


//入库
void StockWidget::on_btnStockIn_clicked()
{

}

