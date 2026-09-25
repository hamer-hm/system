#include "stockwidget.h"
#include "ui_stockwidget.h"
#include"stockindialog.h"
#include"dbmanager.h"
#include<QSqlRelationalTableModel>
#include<QSqlRecord>
#include<QSqlRelationalDelegate>
#include<QSqlError>
#include<QDialog>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDateTime>
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
    //设置编辑策略
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
    ui->tableView->setColumnHidden(1,true);  //隐藏specId列
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));//设置代理

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置拉伸

}


//入库
void StockWidget::on_btnStockIn_clicked()
{
    auto &db=DBManager::instance().getDB();//获取数据库
    StockInDialog dlg(this);
    if(dlg.exec()==StockInDialog::Accepted)
    {
        int typeId=dlg.getTypeId();        //获取typeId
        double stockNum = dlg.getStockNum();  //获取stockNum;

        if(stockNum <= 0)                   //校验输入数量
        {
            QMessageBox::warning(this,"提示","入库数量必须大于0");
            return;
        }
        QSqlQuery query(db);
        query.prepare("SELECT typeId,stockNum FROM stock WHERE typeId= :typeId");  //根据typeId查询typeId,stockNum
        query.bindValue(":typeId",typeId);
        query.exec();
        if(!query.next())
        {
            QMessageBox::critical(this,"error","不存在此钢材规格！");
        }else
        {
            double oldStockNum=query.value("stockNum").toDouble();                     //获取原来的钢材数量
            QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm::ss");//获取当前时间
            query.prepare("UPDATE stock SET stockNum=:stockNum,updateTime=:updateTime WHERE typeId=:typeId"); //更新数据

            query.bindValue(":typeId",typeId);
            query.bindValue(":stockNum",oldStockNum+stockNum);
            query.bindValue(":updateTime",time);
            query.exec();
            QMessageBox::information(this,"提示","入库成功！");
            m_stockModel->select();
        }
    }
}

//删除记录
void StockWidget::on_btnStockDel_clicked()
{
    QModelIndex curIndex=ui->tableView->currentIndex();               //获取当前索引
    if(!curIndex.isValid())
    {
        QMessageBox::information(this,"提示","请选中一行数据！");
    }
    bool ok=QMessageBox::question(this,"提示","你真的要删除这一行数据吗？");//二次确认
    if(ok)
    {
        if(m_stockModel->removeRow(curIndex.row()))
        {
            QMessageBox::information(this,"提示","删除记录成功！");
            m_stockModel->submitAll();                                //提交全部
            m_stockModel->select();
        }else
        {
            QMessageBox::critical(this,"error","删除记录失败！"+m_stockModel->lastError().text());
            m_stockModel->revertAll();  //回滚
        }
    }
}



void StockWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    // 页面切换显示，加载订单号
    loadStockTable();
}
