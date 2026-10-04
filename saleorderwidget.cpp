#include "saleorderwidget.h"
#include "ui_saleorderwidget.h"
#include<QSqlQuery>
#include"dbmanager.h"
#include<QSqlError>
#include<QMessageBox>
#include"specdelegate.h"
#include<QStandardItemModel>
#include<QSqlDatabase>
#include"numericdelegate.h"
#include<QDate>
SaleOrderWidget::SaleOrderWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SaleOrderWidget)
{
    ui->setupUi(this);
    initModel();
    reload();
}

SaleOrderWidget::~SaleOrderWidget()
{

    delete ui;
}

//外部刷新接口（切库时调用）
void SaleOrderWidget::reload()
{
    //清空明细（不重建 itemModel，保持 delegate 信号连接有效）
    itemModel->removeRows(0, itemModel->rowCount());
    //加一个空行
    onBtnAddClicked();
    //加载订单号 + 客户下拉框 + delegate
    loadInformation();
}

//初始化表格模型
void SaleOrderWidget::initModel()
{
    itemModel = new QStandardItemModel(this);
    QStringList headers;
    headers << "钢材规格" << "单价" << "数量" << "小计";
    itemModel->setHorizontalHeaderLabels(headers);
    ui->tableView->setModel(itemModel);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 200);

    //绑定按钮
    connect(ui->btnAdd, &QPushButton::clicked, this, &SaleOrderWidget::onBtnAddClicked);
}

//加载信息
void SaleOrderWidget::loadInformation()
{
    //单据信息
    //获取数据库
    auto &db = DBManager::instance().getDB();
    //单据信息
    loadOrder(db);
    //销售明细
    loadSale(db);

}

//单据信息
void SaleOrderWidget::loadOrder(QSqlDatabase &db)
{
    QSqlQuery query(db);

    //查询最大订单号
    if (!query.exec("SELECT MAX(orderId) FROM sale_order")) {
        // qDebug() << "loadInformation 查询失败:" << query.lastError().text();
        //如果没有订单设置订单号为1
        m_orderId = 1;
    } else {
        if(query.next())
        {
            //设置订单号为最大订单号+1
            m_orderId = query.value(0).toInt() + 1;
        }
    }
    //设置订单号
    ui->orderNm->setText(QString::number(m_orderId));

    query.exec("SELECT custId,custName,contact,phone FROM customer");
    ui->custName->clear();
    while(query.next())
    {
        int custId=query.value(0).toInt();
        QString custName=query.value(1).toString();
        ui->custName->addItem(custName,custId);
    }

}

//销售明细
void SaleOrderWidget::loadSale(QSqlDatabase &db)
{
    //加载钢铁规格代理
    loadSpecDelegate();
    //加载单价和数量代理
    loadNumericDelegate();
}

//加载钢材规格代理
void SaleOrderWidget::loadSpecDelegate()
{
    static specDelegate *delegate = nullptr;

    //连接信号当代理中的index改变时自动给出市场单价
    if (!delegate)
    {
        delegate = new specDelegate(this);

        connect(itemModel,&QStandardItemModel::dataChanged,this,[=](const QModelIndex &topLeft,const QModelIndex &bottomRight)
                {
                    int row = topLeft.row();
                    int col = topLeft.column();
                    //setData触发dataChanged不再修改数值
                    if(col == 0)
                    {
                        double price = topLeft.data(Qt::UserRole+1).toDouble();
                        //填充单价
                        itemModel->setData(itemModel->index(row,1), price, Qt::EditRole);
                        //将specId存入model第0列
                        int specId=itemModel->data(itemModel->index(row,0),Qt::UserRole).toInt();
                        itemModel->setData(itemModel->index(row,0), specId, Qt::UserRole);
                        //设置model数量默认为1
                        itemModel->setData(itemModel->index(row,2),QString::number(1));
                        //读取model数量
                        double num=itemModel->item(row,2)->data(Qt::DisplayRole).toDouble();
                        //修改model小计
                        double subTotal=num*price;
                        itemModel->setData(itemModel->index(row,3),QString::number(subTotal,'f',2));
                        //开启单价、数量可编辑
                        itemModel->item(row,1)->setEditable(true);
                        itemModel->item(row,2)->setEditable(true);
                        //加载总数总额
                        loadSum();
                    }
                });

    }
    ui->tableView->setItemDelegateForColumn(0,delegate);
}

//加载单价数量代理
void SaleOrderWidget::loadNumericDelegate()
{
    NumericDelegate *delegate=new NumericDelegate(this);
    //加载单价代理
    ui->tableView->setItemDelegateForColumn(1,delegate);
    //加载数量代理
    ui->tableView->setItemDelegateForColumn(2,delegate);

    connect(delegate,&NumericDelegate::valueChanged,this,[=](const QModelIndex &index,double value){
        //获取当前行行号
        int row = index.row();
        double price = 0.0;
        double number = 0.0;
        if(index.column()==1)
            {
            //获取单价
            price=value;
            //获取数量
            number=itemModel->data(itemModel->index(row,2)).toDouble();

            //修改代理中的值时同时把value写入对应item，防止总额总数读取不到代理实时更新的值而引用旧值
            itemModel->setData(itemModel->index(row,1), value);


        }else
            {
            //获取单价
            price=itemModel->data(itemModel->index(row,1)).toDouble();
            //获取数量
            number=value;

            itemModel->setData(itemModel->index(row,2), value);

        }
        //计算小计
        double subTotal=price*number;
        //保留两位小数
        QString strSub = QString::number(subTotal, 'f', 2);
        //将计算好的小计写入对应位置
        itemModel->setData(itemModel->index(row,3),strSub);
        //同时计算总额总数
        loadSum();
    });

}



//计算总金额总数量
void SaleOrderWidget::loadSum()
{
    int rowCount=itemModel->rowCount();
    double totalAmount=0.00;
    for(int i=0;i<rowCount;i++)
    {
        totalAmount+=itemModel->index(i,3).data(Qt::DisplayRole).toDouble();
    }
    ui->editTotalAmount->setText(QString::number(totalAmount,'f',2)+" 元");

    double numAmount=0.00;
    for(int i=0;i<rowCount;i++)
    {
        numAmount+=itemModel->index(i,2).data(Qt::DisplayRole).toDouble();
    }
    ui->editNumAmount->setText(QString::number(numAmount,'f',2)+" 吨");
}


//加载联系人，联系电话
void SaleOrderWidget::on_custName_currentIndexChanged(int index)
{
    int custId=ui->custName->currentData().toInt();
    auto &db = DBManager::instance().getDB();
    QSqlQuery query(db);
    query.prepare("SELECT contact,phone FROM customer WHERE custId= :custId");
    query.bindValue(":custId",custId);
    if(!query.exec())
        return;
    if(query.next())
    {
        //加载联系人
        ui->editContact->setText(query.value(0).toString());
        //加载电话
        ui->editPhone->setText(query.value(1).toString());
    }
}




//添加一行
void SaleOrderWidget::onBtnAddClicked()
{
    // itemModel 是类成员变量 QStandardItemModel* itemModel;
    QList<QStandardItem*> row;

    // 0钢材规格，1单价，2数量，3小计
    for(int i=0;i<4;i++)
    {
        //新建空item
        QStandardItem* item = new QStandardItem("");
        if(i == 3||i==2||i==1)
        {
            //单价、数量、小计禁止编辑
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
        row.append(item);
    }
    itemModel->appendRow(row);
}


//删除
void SaleOrderWidget::on_btnDelete_clicked()
{

    QModelIndex curIndex=ui->tableView->currentIndex();
    if(!curIndex.isValid())
        return;
    int row=curIndex.row();
    itemModel->removeRow(row);

    //加载总数总额
    loadSum();
}

//开单
void SaleOrderWidget::on_btnOk_clicked()
{
    //获取数据库
    auto &db = DBManager::instance().getDB();
    QSqlQuery queryMian(db);
    //开启事务
    if(!db.transaction())
    {
        QMessageBox::warning(this,"错误","开启事务失败："+db.lastError().text());
        return;
    }
    //订单号
    int orderId=m_orderId;


    //把整个订单的信息填入sale_order表
    //客户id
    int custId=ui->custName->currentData(Qt::UserRole).toInt();
    //下订单的日期
    QString orderDate=QDate::currentDate().toString("yyyy-MM-dd");
    //总额
    double totalAm=0.00;
    int rowCount=itemModel->rowCount();
    for(int i=0;i<rowCount;i++)
    {
        totalAm+=itemModel->index(i,3).data(Qt::DisplayRole).toDouble();
    }
    QString totalAmount=QString::number(totalAm,'f',2);
    //订单状态
    QString status=ui->comStatus->currentText();
    //备注
    QString remark=ui->editRemark->text();
    if(itemModel->rowCount()==0)
    {
        QMessageBox::information(this,"提示","请添加销售明细");
        db.rollback();
        return;
    }
    //如果有item为空就禁止开单
    for(int i=0;i<rowCount;i++)
    {
        if(itemModel->item(i,0)->text().isEmpty()||itemModel->item(i,1)->text().isEmpty()||itemModel->item(i,2)->text().isEmpty()
            ||itemModel->item(i,3)->text().isEmpty())
        {
            QMessageBox::information(this,"提示","有空item，请添加内容");
            db.rollback();
            return;
        }

    }
    //将对应信息插入sale_order表
    queryMian.prepare("INSERT INTO sale_order(orderId,custId,orderDate,totalAmount,status,remark)"
                  "VALUES(:orderId,:custId,:orderDate,:totalAmount,:status,:remark)");
    queryMian.bindValue(":orderId",orderId);
    queryMian.bindValue(":custId",custId);
    queryMian.bindValue(":orderDate",orderDate);
    queryMian.bindValue(":totalAmount",totalAmount);
    queryMian.bindValue(":status",status);
    queryMian.bindValue(":remark",remark);
    if(!queryMian.exec())
    {
        db.rollback();
        QMessageBox::critical(this,"插入订单主表失败",queryMian.lastError().text());
        return;
    }

    QSqlQuery query(db);
    //循环把同一订单的所有钢材规格订单信息填入sale_order_item表
    for(int i=0;i<itemModel->rowCount();i++)
    {
        QStandardItem* specItem = itemModel->item(i,0);

        //specId
        int specId=specItem->data(Qt::UserRole).toInt();

        //销售数量
        double saleNum=itemModel->item(i,2)->data(Qt::DisplayRole).toDouble();
        //钢材规格
        QString specName=itemModel->item(i,0)->data(Qt::DisplayRole).toString();
        //查询钢材规格对应的库存数量
        QSqlQuery upd(db);
        upd.prepare("UPDATE stock SET stockNum = stockNum - :n "
                    "WHERE specId = :id AND stockNum >= :n");
        upd.bindValue(":n", saleNum);
        upd.bindValue(":id", specId);
        if (!upd.exec())
        {
            db.rollback();
            QMessageBox::critical(this, "库存更新失败",
                                  QString("第%1行：%2").arg(i+1).arg(upd.lastError().text()));
            return;
        }
        if (upd.numRowsAffected() == 0)
        {
            db.rollback();
            QMessageBox::warning(this, "库存不足",
                                 QString("第%1行 %2：库存不够（需要 %3）").arg(i+1).arg(specName).arg(saleNum));
            return;
        }
        //销售单价
        double salePrice=itemModel->item(i,1)->data(Qt::DisplayRole).toDouble();
        //小计
        double subTotal=itemModel->item(i,3)->data(Qt::DisplayRole).toDouble();

        //将对应信息插入sale_order_item表
        query.prepare("INSERT INTO sale_order_item(orderId,specId,saleNum,salePrice,subTotal)"
                      "VALUES(:orderId,:specId,:saleNum,:salePrice,:subTotal)");

        query.bindValue(":orderId",orderId);
        query.bindValue(":specId",specId);
        query.bindValue(":saleNum",saleNum);
        query.bindValue(":salePrice",salePrice);
        query.bindValue(":subTotal",subTotal);
        if(!query.exec())
        {
            db.rollback();
            QMessageBox::critical(this,"插入明细失败",QString("第%1行：%2").arg(i+1).arg(query.lastError().text()));
            return;
        }

    }
    //全部成功，提交事务
    if(db.commit())
    {
        QMessageBox::information(this,"成功","订单开单保存完成！");
        //清空model
        itemModel->clear();
        itemModel->setRowCount(0);
        //刷新页面，准备下一张单
        loadInformation();
    }
    else
    {
        db.rollback();
        QMessageBox::critical(this,"提交事务失败",db.lastError().text());
    }



}








