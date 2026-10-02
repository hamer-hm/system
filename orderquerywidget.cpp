#include "orderquerywidget.h"
#include "ui_orderquerywidget.h"
#include<QStandardItemModel>
#include<QSqlQuery>
#include"dbmanager.h"
#include<QSqlError>
#include<QMessageBox>
#include<QDateTime>
OrderQueryWidget::OrderQueryWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrderQueryWidget)
{
    ui->setupUi(this);
    // loadOrderQueryWidget();
}

OrderQueryWidget::~OrderQueryWidget()
{
    delete ui;
}

void OrderQueryWidget::on_chkDateEnable_clicked(bool checked)
{
    ui->dateStart->setEnabled(checked);
    ui->dateEnd->setEnabled(checked);
}

// 加载客户下拉框
void OrderQueryWidget::loadCustomerCombo()
{
    ui->cbCustName->clear();
    auto &db=DBManager::instance().getDB();
    QSqlQuery query(db);
    ui->cbCustName->addItem("全部客户","");
    //查询客户Id客户名称
    if(!query.exec("SELECT custId,custName FROM customer"))
    {
        return;
    }else
    {
        while(query.next())
        {
            QString custName=query.value("custName").toString();
            int custId=query.value("custId").toInt();
            ui->cbCustName->addItem(custName,custId);
        }
    }
}

// 加载订单状态下拉框
void OrderQueryWidget::loadStatusCombo()
{
    ui->cbOrderStatus->clear();
    QStringList status;
    status<<"全部状态"<<"已开单"<<"已结算"<<"已出库";
    ui->cbOrderStatus->addItems(status);
}


//加载widget信息
void OrderQueryWidget::loadOrderQueryWidget()
{
    QRegularExpression reg("^[0-9]+$");
    ui->editOrderNo->setValidator(new QRegularExpressionValidator(reg,this));
    // 加载客户下拉框
    loadCustomerCombo();
    // 加载订单状态下拉框
    loadStatusCombo();
    //设置默认时间
    QDateTime curTime=QDateTime::currentDateTime();
    //默认开始时间是当天
    ui->dateStart->setDateTime(curTime);
    //默认结束时间是明天
    ui->dateEnd->setDateTime(curTime.QDateTime::addDays(1));

    //设置主表
    if(!m_orderModel)
    {
        m_orderModel=new QStandardItemModel(this);
        //设置表头
        m_orderModel->setHorizontalHeaderLabels({"订单号","客户名称","下单日期","总额","状态"});
        //自动缩放
        ui->tableViewOrder->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //设置不可编辑
        ui->tableViewOrder->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewOrder->setModel(m_orderModel);
    }
    //设置从表
    if(!m_itemModel)
    {
        m_itemModel=new QStandardItemModel(this);
        //设置表头
        m_itemModel->setHorizontalHeaderLabels({"钢材类型","销售数量","销售单价","小计"});
        //自动缩放
        ui->tableViewItem->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //设置不可编辑
        ui->tableViewItem->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewItem->setModel(m_itemModel);
    }
    //绑定点击主表从表显示明细
    connect(ui->tableViewOrder->selectionModel(),&QItemSelectionModel::selectionChanged,this,&OrderQueryWidget::onOrderSelected);
}








void OrderQueryWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    loadOrderQueryWidget();
}

//查询按钮
void OrderQueryWidget::on_btnQuery_clicked()
{
    m_orderModel->removeRows(0,m_orderModel->rowCount());

    // m_itemModel->clear();
    QString sql="SELECT s.orderId,c.custName,s.orderDate,s.totalAmount,s.status FROM "
                  "sale_order s LEFT JOIN customer c ON s.custId=c.custId where 1=1";
    // 用来标记要不要绑定这个参数
    bool hasOrderId=false;
    bool hasCustId=false;
    bool hasDate=false;
    bool hasStatus=false;
    //拼接sql
    //订单号
    int orderId = ui->editOrderNo->text().trimmed().toInt();
    if(orderId > 0)
    {
        sql += " AND s.orderId=:orderId";
        hasOrderId = true;
    }
    //客户名称
    int custId = 0;
    if(ui->cbCustName->currentIndex() >=0)
    {
        custId = ui->cbCustName->currentData().toInt();
    }
    if(custId > 0)
    {
        sql += " AND s.custId = :custId ";
        hasCustId = true;
    }
    //开始结束日期
    QString startDate,endDate;
    if(ui->chkDateEnable->isChecked())
    {
        QDate start = ui->dateStart->date();
        QDate end = ui->dateEnd->date();
        if(start > end)
        {
            QMessageBox::warning(this,"提示","起始日期不能大于结束日期");
            return;
        }
        sql += " AND s.orderDate >= :startDate AND s.orderDate <= :endDate ";
        startDate = start.toString("yyyy-MM-dd");
        endDate = end.toString("yyyy-MM-dd");
        hasDate = true;
    }
    //状态
    QString status = ui->cbOrderStatus->currentText();
    if(status != "全部状态")
    {
        sql += " AND s.status=:status";
        hasStatus = true;
    }

    auto &db=DBManager::instance().getDB();
    QSqlQuery query(db);
    query.prepare(sql);
    //替换数据
    if(hasOrderId)
        query.bindValue(":orderId",orderId);
    if(hasCustId)
        query.bindValue(":custId",custId);
    if(hasDate)
    {
        query.bindValue(":startDate",startDate);
        query.bindValue(":endDate",endDate);
    }
    if(hasStatus)
        query.bindValue(":status",status);


    if(!query.exec())
    {
        QMessageBox::warning(this,"查询失败",query.lastError().text() + "\nSQL:" + sql);
        return;
    }

    loadOrderTable(query);

}

//从表明细
void OrderQueryWidget::onOrderSelected(const QItemSelection &selected, const QItemSelection &deselected)
{
    // qDebug() << "选中触发";
    // 取消选中时直接退出，防止越界
    if(selected.isEmpty()) return;
    //表清空数据
    m_itemModel->removeRows(0,m_itemModel->rowCount());
    //获取当前行
    int curRow=ui->tableViewOrder->currentIndex().row();
    //获取当前行订单号
    int orderId=m_orderModel->item(curRow,0)->text().toInt();
    auto &db=DBManager::instance().getDB();
    QSqlQuery query(db);
    query.prepare("SELECT st.typeName||' '||ss.material||' '||ss.size AS specName,"
                  "so.saleNum,so.salePrice,so.subTotal FROM sale_order_item so "
                  "LEFT JOIN steel_spec ss ON so.specId=ss.specId "
                  "LEFT JOIN steel_type st ON ss.typeId=st.typeId "
                  "WHERE orderId=:orderId ");
    query.bindValue(":orderId",orderId);
    if(!query.exec())
    {
        QMessageBox::warning(this,"查询明细失败",query.lastError().text());
        return;
    }
    //用于标记查没查到数据
    bool hasData = false;
    while(query.next())
    {
        //查到了
        hasData=true;
        QString specName=query.value(0).toString();
        double saleNum=query.value(1).toDouble();
        double salePrice=query.value(2).toDouble();
        double subTotal=query.value(3).toDouble();

        QList<QStandardItem*> row;
        row<<new QStandardItem(specName);
        row<<new QStandardItem(QString::number(saleNum,'f',2));
        row<<new QStandardItem(QString::number(salePrice,'f',2));
        row<<new QStandardItem(QString::number(subTotal,'f',2));

        m_itemModel->appendRow(row);
    }
    // 没有查到任何数据
    if(!hasData)
    {
        QMessageBox::information(this,"查询提示","未查询到订单明细");
    }
}


//加载主表
void OrderQueryWidget::loadOrderTable(QSqlQuery &query)
{
    //用于标记查没查到数据
    bool hasData = false;
    while(query.next())
    {
        //查到了
        hasData=true;
        int orderId = query.value("orderId").toInt();
        QString custName = query.value("custName").toString();
        QString orderDate = query.value("orderDate").toString();
        double total = query.value("totalAmount").toDouble();
        QString status = query.value("status").toString();

        QList<QStandardItem*> row;
        row << new QStandardItem(QString::number(orderId));
        row << new QStandardItem(custName);
        row << new QStandardItem(orderDate);
        row << new QStandardItem(QString::number(total,'f',2));
        row << new QStandardItem(status);
        //追加行
        m_orderModel->appendRow(row);
    }
    // 没有查到任何数据
    if(!hasData)
    {
        QMessageBox::information(this,"查询提示","未查询到符合条件的订单");
    }
}

//重置按钮
void OrderQueryWidget::on_btnReset_clicked()
{
    //重置订单号
    ui->editOrderNo->clear();
    //重置客户名称
    ui->cbCustName->setCurrentIndex(0);
    //重置订单状态
    ui->cbOrderStatus->setCurrentIndex(0);
    //重置默认时间
    QDateTime curTime=QDateTime::currentDateTime();
    //默认开始时间是当天
    ui->dateStart->setDateTime(curTime);
    //默认结束时间是明天
    ui->dateEnd->setDateTime(curTime.QDateTime::addDays(1));
    //重置主表
    m_orderModel->removeRows(0,m_orderModel->rowCount());
    //重置从表
    m_itemModel->removeRows(0,m_itemModel->rowCount());
}

