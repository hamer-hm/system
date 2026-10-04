#include "customermanagewidget.h"
#include "ui_customermanagewidget.h"
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include "dbmanager.h"
#include "customereditdialog.h"

// 构造函数
CustomerManageWidget::CustomerManageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomerManageWidget)
{
    ui->setupUi(this);

    // 最后一列自动拉伸填满剩余空间
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // 初始化 + 加载数据
    reload();
}


// 外部刷新接口（切库时调用）
void CustomerManageWidget::reload()
{
    // 断开视图和旧模型
    if (ui->tableView->model()) {
        ui->tableView->setModel(nullptr);
    }

    // 销毁旧模型
    delete m_custModel;
    m_custModel=nullptr;

    //重建模型
    initModel();

    // 加载数据
    loadCustomerData();
}

// 初始化表格模型
void CustomerManageWidget::initModel()
{
    m_custModel = new QStandardItemModel(this);
    ui->tableView->setModel(m_custModel);

    QStringList headers{"客户编号", "客户名称", "联系人", "联系电话", "地址", "备注"};
    m_custModel->setHorizontalHeaderLabels(headers);
}

CustomerManageWidget::~CustomerManageWidget()
{
    delete ui;
}

//加载客户数据
void CustomerManageWidget::loadCustomerData()
{
    //清空原有行数据，保留表头
    m_custModel->removeRows(0, m_custModel->rowCount());

    //获取界面输入，去除首尾空格
    QString custName=ui->editCustName->text().trimmed();
    QString phone=ui->editPhone->text().trimmed();

    //获取数据库实例
    auto& db=DBManager::instance().getDB();
    QSqlQuery query(db);

    QString sql=
        "SELECT custId, custName, contact, phone, address, remark "
        "FROM customer "
        "WHERE 1=1"
        ;
    QStringList conds;    // 条件容器
    QVariantList params;  // 预编译参数，防止SQL注入

    //客户名称不为空，增加模糊查询条件
    if(!custName.isEmpty()){
        conds<<"custName LIKE ?";
        params<<"%" + custName + "%";
    }
    //手机号不为空，增加模糊查询条件
    if(!phone.isEmpty()){
        conds<<"phone LIKE ?";
        params<<"%" + phone + "%";
    }
    //拼接AND条件
    if(!conds.isEmpty()){
        sql+=" AND "+conds.join(" AND ");
    }
    //按客户ID升序
    sql+=" ORDER BY custId ASC;";


    query.prepare(sql);
    //绑定所有参数
    for(auto var:params){
        query.addBindValue(var);
    }

    if(!query.exec()){
        QMessageBox::critical(this,"查询失败",query.lastError().text());
        return;
    }

    bool hasData=false;

    while(query.next()){
        hasData = true;
        QList<QStandardItem*> rowItems;
        // 依次取出字段，构建一行数据，顺序和SELECT对应
        rowItems<<new QStandardItem(query.value("custId").toString());
        rowItems<<new QStandardItem(query.value("custName").toString());
        rowItems<<new QStandardItem(query.value("contact").toString());
        rowItems<<new QStandardItem(query.value("phone").toString());
        rowItems<<new QStandardItem(query.value("address").toString());
        rowItems<<new QStandardItem(query.value("remark").toString());

        //设置单元格只读
        for(auto item:rowItems){
            item->setEditable(false);
        }
        //添加一行
        m_custModel->appendRow(rowItems);
    }

    //没有查到任何数据时弹窗提示
    if(!hasData){
        QMessageBox::information(this,"提示","未查询到客户数据");
    }
}

//查询按钮点击：刷新列表
void CustomerManageWidget::on_btnQuery_clicked()
{
    loadCustomerData();
}

//重置按钮：清空所有筛选输入，重新加载全部数据
void CustomerManageWidget::on_btnReset_clicked()
{
    ui->editCustName->clear();
    ui->editPhone->clear();
    loadCustomerData();
}

//新增客户，弹出新增对话框
void CustomerManageWidget::on_btnAdd_clicked()
{
    CustomerEditDialog dlg(this);
    dlg.setIsNew(true); // 设置为新增模式
    // 对话框保存成功，刷新客户列表
    if(dlg.exec()==QDialog::Accepted){
        loadCustomerData();
    }
}

//编辑选中客户
void CustomerManageWidget::on_btnEdit_clicked()
{
    //获取当前选中行索引
    auto idx=ui->tableView->currentIndex();
    //判断是否选中有效行
    if(!idx.isValid()){
        QMessageBox::warning(this,"提示","请先选中一行客户");
        return;
    }
    //获取选中行custId
    QString custId=m_custModel->index(idx.row(),0).data().toString();

    CustomerEditDialog dlg(this);
    dlg.setIsNew(false);        //设置为编辑模式
    dlg.setCustId(custId);      //传入要编辑的客户ID
    if(dlg.exec()==QDialog::Accepted){
        loadCustomerData();
    }
}

//删除选中客户
void CustomerManageWidget::on_btnDelete_clicked()
{
    auto index=ui->tableView->currentIndex();
    if(!index.isValid()){
        QMessageBox::warning(this,"提示","请先选中一行客户");
        return;
    }
    QString custId=m_custModel->index(index.row(),0).data().toString();

    // 二次确认弹窗
    auto ret=QMessageBox::question(this,"确认删除",
                                     QString("确定删除客户: %1？").arg(custId),
                                     QMessageBox::Yes | QMessageBox::No);
    if(ret!=QMessageBox::Yes)
        return;

    //执行删除SQL
    auto& db=DBManager::instance().getDB();
    QSqlQuery query(db);
    query.prepare("DELETE FROM customer WHERE custId = ?");
    query.addBindValue(custId);

    if(!query.exec()){
        QMessageBox::critical(this,"删除失败",query.lastError().text());
    }else{
        QMessageBox::information(this,"成功","客户已删除");
        loadCustomerData();
    }
}

//双击表格行，触发编辑
void CustomerManageWidget::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid()) return;
    on_btnEdit_clicked();
}
