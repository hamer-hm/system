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
    initModel();
    reload();
}

StockWidget::~StockWidget()
{
    delete ui;
}

//外部刷新接口（切库时调用）
void StockWidget::reload()
{
    // //重建模型
    // initModel();

    //加载数据
    m_stockModel->select();
}

//初始化库存表格模型
void StockWidget::initModel()
{
    auto &db = DBManager::instance().getDB();//获取数据库

    m_stockModel = new QSqlRelationalTableModel(this, db);
    m_stockModel->setTable("stock");
    //设置编辑策略
    m_stockModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);

    //将typeName替换为typeName
    int specCol = m_stockModel->record().indexOf("typeId");
    m_stockModel->setRelation(specCol, QSqlRelation("steel_type", "typeId", "typeName"));

    //设置表头
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("stockId"), Qt::Horizontal, "库存ID");
    m_stockModel->setHeaderData(specCol, Qt::Horizontal, "钢材规格");
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("stockNum"), Qt::Horizontal, "库存数量(吨)");
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("costPrice"), Qt::Horizontal, "成本单价");
    m_stockModel->setHeaderData(m_stockModel->record().indexOf("updateTime"), Qt::Horizontal, "更新时间");

    //设置model
    ui->tableView->setModel(m_stockModel);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //隐藏specId列
    ui->tableView->setColumnHidden(m_stockModel->record().indexOf("specId"), true);
    //设置代理
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    //设置拉伸
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
//入库
void StockWidget::on_btnStockIn_clicked()
{
    auto &db=DBManager::instance().getDB();
    StockInDialog dlg(this);
    if(dlg.exec()==StockInDialog::Accepted)
    {
        int specId = dlg.getSpecId();
        int typeId = dlg.getTypeId();
        double stockNum = dlg.getStockNum();
        double costPrice = dlg.getCostPrice();

        if(stockNum <= 0)
        {
            QMessageBox::warning(this,"提示","入库数量必须大于0");
            return;
        }

        if (costPrice <= 0) {
            QMessageBox::warning(this, "提示", "成本单价必须大于0");
            return;
        }
        QSqlQuery query(db);
        // 校验：该specId在steel_spec中存在
        query.prepare("SELECT specId FROM steel_spec WHERE specId = :specId");
        query.bindValue(":specId", specId);
        if(!query.exec() || !query.next())
        {
            QMessageBox::critical(this,"错误","该钢材规格不存在！");
            return;
        }

        db.transaction();
        // 查询当前specId有没有库存记录
        query.prepare("SELECT stockNum FROM stock WHERE specId= :specId");
        query.bindValue(":specId",specId);
        if(!query.exec())
        {
            db.rollback();
            QMessageBox::critical(this,"error","查询库存失败："+query.lastError().text());
            return;
        }

        QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        bool hasStock = query.next();
        bool ok = false;
        if(hasStock)
        {
            // 已有库存：更新
            double oldStockNum=query.value("stockNum").toDouble();
            double newNum = oldStockNum + stockNum;
            query.prepare("UPDATE stock SET stockNum=:stockNum,updateTime=:updateTime WHERE specId=:specId");
            query.bindValue(":specId",specId);
            query.bindValue(":stockNum", newNum);
            query.bindValue(":updateTime", time);
            ok = query.exec();
        }
        else
        {
            // 新增库存：specId、typeId两个字段都赋值！解决NOT NULL报错
            query.prepare("INSERT INTO stock(specId, typeId, stockNum, costPrice, updateTime) VALUES(:specId, :typeId, :stockNum, :costPrice, :updateTime)");
            query.bindValue(":specId", specId);
            query.bindValue(":typeId", typeId);
            query.bindValue(":stockNum", stockNum);
            query.bindValue(":costPrice", costPrice);
            query.bindValue(":updateTime", time);
            ok = query.exec();
        }

        if(ok)
        {
            db.commit();
            QMessageBox::information(this,"提示","入库成功！");
            m_stockModel->select();
        }
        else
        {
            db.rollback();
            QMessageBox::critical(this,"error","入库失败："+query.lastError().text());
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
        return;
    }
    const auto ok=QMessageBox::question(this,"提示","你真的要删除这一行数据吗？",QMessageBox::Yes|QMessageBox::No);//二次确认
    if(ok==QMessageBox::Yes)
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

