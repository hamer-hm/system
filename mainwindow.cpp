#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QButtonGroup>
#include"dbmanager.h"
#include<QSqlRelationalTableModel>
#include<QSqlRecord>
#include<QSqlRelationalDelegate>
#include<QSettings>
#include<QDialog>
#include<QGroupBox>
#include<QLabel>
#include<QComboBox>
#include<QSpinBox>
#include<QLineEdit>
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
#include<QItemSelectionModel>
#include<QFileDialog>
#include<QFile>
#include"stockwidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置tableView行为/模式
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //toolbutton按钮组
    QButtonGroup *btnGroup=new QButtonGroup(this);

    btnGroup->addButton(ui->btn_BaseInfo,0);
    btnGroup->addButton(ui->btn_Stockton,1);
    btnGroup->addButton(ui->btn_SaleCreate,2);
    btnGroup->addButton(ui->btn_OrderQuery,3);
    btnGroup->addButton(ui->btn_Customer,4);
    btnGroup->addButton(ui->btn_Report,5);
    btnGroup->addButton(ui->btn_Setting,6);
    //切换stackedWidget页面
    connect(btnGroup,&QButtonGroup::idClicked,ui->stackedWidget,&QStackedWidget::setCurrentIndex);

    QString iniFile = QCoreApplication::applicationDirPath() + "/config.ini";//设置ini文件路径
    QSettings setting(iniFile,QSettings::IniFormat);//新建ini文件
    QString path=setting.value("dbPath","D:/system/system/steel_sales.db").toString();//从ini文件中读取数据库路径
    bool res=DBManager::instance().openDB(path);//打开数据库
    if(res)
    {
    //基础资料
    openSpecTable();

    //库存管理
    openStockTable();
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

//初始化数据表
void MainWindow::openSpecTable()
{

        auto& DB = DBManager::instance().getDB();
        specModel = new QSqlRelationalTableModel(this, DB);
        selModel=new QItemSelectionModel(specModel,this);

        specModel->setTable("steel_spec");
        specModel->setEditStrategy(QSqlRelationalTableModel::OnRowChange);
        int typeIdCol = specModel->record().indexOf("typeId");
        specModel->setRelation(typeIdCol, QSqlRelation("steel_type", "typeId", "typeName"));
        specModel->select();

        QSqlRecord rec = specModel->record();
        specModel->setHeaderData(rec.indexOf("specId"), Qt::Horizontal, "规格编号");
        specModel->setHeaderData(rec.indexOf("typeName"), Qt::Horizontal, "钢材类型");
        specModel->setHeaderData(rec.indexOf("material"), Qt::Horizontal, "材质");
        specModel->setHeaderData(rec.indexOf("size"), Qt::Horizontal, "尺寸");
        specModel->setHeaderData(rec.indexOf("unit"), Qt::Horizontal, "单位");
        specModel->setHeaderData(rec.indexOf("price"), Qt::Horizontal, "参考单价");
        specModel->setHeaderData(rec.indexOf("remark"), Qt::Horizontal, "备注");

        ui->tableView->setModel(specModel);
        ui->tableView->setSelectionModel(selModel);
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

}

//基础资料模块基本信息groupbox
QGroupBox* MainWindow::creatFormGroup()
{
    //左侧lab
    QGroupBox *groupBox=new QGroupBox("基本信息");
    QVBoxLayout *rightLayout=new QVBoxLayout();
    QVBoxLayout *lbLayout=new QVBoxLayout();
    QLabel *lbSpecId=new QLabel("规格编号：");
    QLabel *lbTypeName=new QLabel("钢材类型：");
    QLabel *lbMaterial=new QLabel("材质：");
    QLabel *lbSize=new QLabel("尺寸：");
    QLabel *lbUnit=new QLabel("单位：");
    QLabel *lbPrice=new QLabel("参考单价：");
    QLabel *lbRemark=new QLabel("备注：");

    //右侧
    m_cboTypeName=new QComboBox();
    // 钢材类型下拉框
    m_cboTypeName->addItems({
        "螺纹钢",
        "圆钢",
        "盘螺",
        "高线",
        "热轧板卷",
        "冷轧板卷",
        "中厚板",
        "H型钢",
        "工字钢",
        "槽钢",
        "角钢",
        "方管",
        "圆管",
        "无缝管",
        "镀锌管",
        "不锈钢管",
        "钢轨",
        "钢带",
        "焊管",
        "扁钢"
    });
    //单价spinbox
    m_spinPrice=new QSpinBox();
    m_spinPrice->setSingleStep(1);
    m_spinPrice->setRange(0,50000);

     m_editSpecId=new QLineEdit();
     m_editMaterial=new QLineEdit();
     m_editSize=new QLineEdit();
     m_editUnit=new QLineEdit();
     m_editRemark=new QLineEdit();
    rightLayout->addWidget(m_editSpecId);
    rightLayout->addWidget(m_cboTypeName);
    rightLayout->addWidget(m_editMaterial);
    rightLayout->addWidget(m_editSize);
    rightLayout->addWidget(m_editUnit);
    rightLayout->addWidget(m_spinPrice);
    rightLayout->addWidget(m_editRemark);

    lbLayout->addWidget(lbSpecId);
    lbLayout->addWidget(lbTypeName);
    lbLayout->addWidget(lbMaterial);
    lbLayout->addWidget(lbSize);
    lbLayout->addWidget(lbUnit);
    lbLayout->addWidget(lbPrice);
    lbLayout->addWidget(lbRemark);

    QHBoxLayout *mainLayout=new QHBoxLayout(groupBox);//容纳左右侧布局的layout
    mainLayout->addLayout(lbLayout);
    mainLayout->addLayout(rightLayout);
    return groupBox;
}

//基础资料新增一行dialog确定按钮槽函数
void MainWindow::onFormBtnOkClicked()
{
    QString specId = m_editSpecId->text().trimmed();
    QString typeName = m_cboTypeName->currentText();
    QString material = m_editMaterial->text().trimmed();
    QString size = m_editSize->text().trimmed();
    QString unit = m_editUnit->text().trimmed();
    int price = m_spinPrice->value();
    QString remark = m_editRemark->text().trimmed();

    //基础校验
    if(specId.isEmpty())
    {
        QMessageBox::warning(this,"提示","规格编号不能为空！");
        m_editSpecId->setFocus();
        return;
    }
    if(material.isEmpty())
    {
        QMessageBox::warning(this,"提示","材质不能为空！");
        m_editMaterial->setFocus();
        return;
    }

    //查询typeId：根据钢材类型名称，从steel_type拿到typeId
    QSqlQuery query;
    query.prepare("SELECT typeId FROM steel_type WHERE typeName = :typeName");
    query.bindValue(":typeName", typeName);
    if(!query.exec())
    {
        QMessageBox::critical(this,"数据库错误",query.lastError().text());
        return;
    }
    if(!query.next())
    {
        QMessageBox::warning(this,"错误","找不到该钢材类型！");
        return;
    }
    int typeId = query.value("typeId").toInt();

    //插入记录到steel_spec表
    QSqlQuery insertQuery;
    insertQuery.prepare(
        "INSERT INTO steel_spec(specId, typeId, material, size, unit, price, remark)"
        "VALUES(:specId, :typeId, :material, :size, :unit, :price, :remark)"
    );
    insertQuery.bindValue(":specId", specId);
    insertQuery.bindValue(":typeId", typeId);
    insertQuery.bindValue(":material", material);
    insertQuery.bindValue(":size", size);
    insertQuery.bindValue(":unit", unit);
    insertQuery.bindValue(":price", price);
    insertQuery.bindValue(":remark", remark);

    if(insertQuery.exec())
    {
        QMessageBox::information(this,"成功","钢材资料添加成功！");
        dlg->accept(); //关闭对话框，返回QDialog::Accepted
    }
    else
    {
        QMessageBox::critical(this,"添加失败",insertQuery.lastError().text());
    }
}


//基础资料新增一行dialog取消按钮槽函数
void MainWindow::onFormBtnCancelClicked()
{
    dlg->reject();
}


//打开销售表
void MainWindow::openStockTable()
{
    ui->page_Stock->loadStockTable();
}


void MainWindow::on_btnAdd_clicked()
{
    dlg=new QDialog(this);
    dlg->setWindowTitle("添加钢材资料");
    dlg->setMinimumSize(400,300);

    //按钮部分
    QPushButton *btnOk=new QPushButton("确定");
    QPushButton *btnCancel=new QPushButton("取消");
    connect(btnOk,&QPushButton::clicked,this,&MainWindow::onFormBtnOkClicked);
    connect(btnCancel,&QPushButton::clicked,this,&MainWindow::onFormBtnCancelClicked);
    btnOk->setMaximumWidth(80);
    btnCancel->setMaximumWidth(80);
    QHBoxLayout *btnLayout=new QHBoxLayout();
    btnLayout->addStretch();
    btnLayout->addWidget(btnOk);
    btnLayout->addWidget(btnCancel);
    btnLayout->addStretch();

    QGroupBox *groupBox=creatFormGroup();
    QVBoxLayout *mainLayout=new QVBoxLayout(dlg);
    mainLayout->addWidget(groupBox);
    mainLayout->addLayout(btnLayout);
    dlg->setLayout(mainLayout);
    if(dlg->exec() == QDialog::Accepted)
    {
        // 新增成功，刷新主界面钢材表格
        if(!specModel) return;
        specModel->select();
    }

}

//基础资料删除一行
void MainWindow::on_btnDel_clicked()
{
    QModelIndex curIndex=selModel->currentIndex();
    if(!curIndex.isValid())
    {
        QMessageBox::warning(this,"提示","请先选中一行！");
        return;
    }
    //二次确认
    auto ret = QMessageBox::question(this,"确认","确定删除这条记录？");
    if(ret == QMessageBox::No)
        return;
    if(specModel->removeRow(curIndex.row()))
    {
        bool ok=QMessageBox::information(this,"提示","删除行成功！");
        if(ok)
        specModel->select();//刷新
    }else
    {
        QMessageBox::critical(this,"删除失败",specModel->lastError().text());
        specModel->revertAll(); //回滚
    }
}

//导出excel
void MainWindow::on_btnExport_clicked()
{
    if(!specModel)
    {
        QMessageBox::warning(this,"提示","没有表格数据！");
        return;
    }

    //选择保存路径
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "导出钢材资料",
                                                    "钢材资料.csv",
                                                    "CSV文件(*.csv)");
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败！");
        return;
    }
    QTextStream out(&file);
    out.setGenerateByteOrderMark(true); //UTF-8，解决Excel中文乱码

    //写入表头
    out << "规格编号,钢材类型,材质,尺寸,单位,参考单价,备注\n";

    //循环读取每一行
    int rowCount = specModel->rowCount();
    for(int r=0; r<rowCount; r++)
    {
        QSqlRecord rec = specModel->record(r);
        QString specId = rec.value("specId").toString()+",";
        QString typeName = rec.value("typeName").toString()+",";
        QString material = rec.value("material").toString()+",";
        QString size = rec.value("size").toString()+",";
        QString unit = rec.value("unit").toString()+",";
        QString price = rec.value("price").toString()+",";
        QString remark = rec.value("remark").toString()+",\n";

        out<<specId<<typeName<<material<<size<<unit<<price<<remark;

    }
    file.close();
    QMessageBox::information(this,"成功","导出完成！\n文件："+fileName);
}





