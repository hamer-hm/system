#include "customereditdialog.h"
#include "ui_customereditdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include "dbmanager.h"

CustomerEditDialog::CustomerEditDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerEditDialog)
{
    ui->setupUi(this);
}

CustomerEditDialog::~CustomerEditDialog()
{
    delete ui;
}


void CustomerEditDialog::setIsNew(bool isNew)
{
    m_isNew = isNew;
    if(m_isNew){
        this->setWindowTitle("新增客户");
        ui->editCustCode->setEnabled(true); // 新增可输入客户ID
        // 清空所有输入框
        ui->editCustCode->clear();
        ui->editCustName->clear();
        ui->editContact->clear();
        ui->editPhone->clear();
        ui->editAddress->clear();
        ui->editRemark->clear();
    }else{
        this->setWindowTitle("编辑客户");
        ui->editCustCode->setEnabled(false); // 编辑时客户ID不可修改
    }
}

//设置客户ID，加载客户信息到表单
void CustomerEditDialog::setCustId(const QString &id)
{
    m_custId = id;
    loadCustomerInfo();
}

//根据客户ID查询数据库，填充表单控件
void CustomerEditDialog::loadCustomerInfo()
{
    auto& db = DBManager::instance().getDB();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM customer WHERE custId = ?");
    query.addBindValue(m_custId);
    //查询成功读取数据赋值到UI
    if(query.exec() && query.next()){
        ui->editCustCode->setText(query.value("custId").toString());
        ui->editCustName->setText(query.value("custName").toString());
        ui->editContact->setText(query.value("contact").toString());
        ui->editPhone->setText(query.value("phone").toString());
        ui->editAddress->setText(query.value("address").toString());
        ui->editRemark->setText(query.value("remark").toString());
    }
}

//保存按钮：新增/编辑
void CustomerEditDialog::on_btnSave_clicked()
{
    // 获取表单输入
    QString custId=ui->editCustCode->text().trimmed();
    QString custName=ui->editCustName->text().trimmed();
    QString contact=ui->editContact->text().trimmed();
    QString phone=ui->editPhone->text().trimmed();
    QString address=ui->editAddress->text().trimmed();
    QString remark=ui->editRemark->text().trimmed();

    //表单校验
    if(custId.isEmpty()){
        QMessageBox::warning(this,"校验","客户编号不能为空");
        return;
    }
    if(custName.isEmpty()){
        QMessageBox::warning(this,"校验","客户名称不能为空");
        return;
    }

    auto& db = DBManager::instance().getDB();
    QSqlQuery query(db);
    if(m_isNew)
    {
        //新增：INSERT语句
        query.prepare(
            "INSERT INTO customer(custId,custName,contact,phone,address,remark)"
            " VALUES(:custId,:custName,:contact,:phone,:address,:remark)"
        );
        query.bindValue(":custId",custId);
        query.bindValue(":custName",custName);
        query.bindValue(":contact",contact);
        query.bindValue(":phone",phone);
        query.bindValue(":address",address);
        query.bindValue(":remark",remark);
    }
    else
    {
        //编辑：UPDATE语句
        query.prepare(
    "UPDATE customer "
    "SET custName=:custName,contact=:contact,phone=:phone,address=:address,remark=:remark "
    "WHERE custId=:custId"
);
        query.bindValue(":custName", custName);
        query.bindValue(":contact", contact);
        query.bindValue(":phone", phone);
        query.bindValue(":address", address);
        query.bindValue(":remark", remark);
        query.bindValue(":custId", custId);
    }

    //SQL执行失败提示
    if(!query.exec()){
        QMessageBox::critical(this,"保存失败",query.lastError().text());
        return;
    }
    QMessageBox::information(this,"成功","保存完成");
    accept(); //关闭对话框，返回Accepted
}

//取消按钮，关闭弹窗
void CustomerEditDialog::on_btnCancel_clicked()
{
    reject();
}
