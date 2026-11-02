#include "reportwidget.h"
#include "ui_reportwidget.h"
#include<QStandardItemModel>
#include<QSqlQuery>
#include<QSqlError>
#include"dbmanager.h"
#include<QSqlRecord>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include<QDateTime>

ReportWidget::ReportWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReportWidget)
{
    ui->setupUi(this);

    // 设置默认日期：本月第一天 ~ 今天
    QDate today=QDate::currentDate();
    QDate firstDay=QDate(today.year(), today.month(), 1);
    ui->dateStart->setDate(firstDay);
    ui->dateEnd->setDate(today);

    // 报表类型下拉选项
    ui->cbReportType->addItems({
        "订单汇总报表",
        "钢材销售明细报表",
        "客户消费统计报表"
    });
    initModel();
    reload();
}

ReportWidget::~ReportWidget()
{
    delete ui;
}


//外部刷新接口（切库时调用）
void ReportWidget::reload()
{
    // //断开视图和旧模型
    // if (ui->tableView->model()) {
    //     ui->tableView->setModel(nullptr);
    // }
    // //销毁旧模型
    // delete m_reportModel;
    // m_reportModel = nullptr;
    // //重建模型
    // initModel();
    //清空界面统计
    clearReportUi();
}

//初始化表格模型
void ReportWidget::initModel()
{
    m_reportModel=new QStandardItemModel(this);
    ui->tableView->setModel(m_reportModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

//清空界面统计
void ReportWidget::clearReportUi()
{
    m_reportModel->clear();
    ui->lblOrderCount->setText("0");
    ui->lblTotalMoney->setText("0.00");
    ui->lblTotalWeight->setText("0.00");
}

//生成报表按钮
void ReportWidget::on_btnQueryReport_clicked()
{
    //加载报表
    loadReportData();
}

//加载报表
void ReportWidget::loadReportData()
{
    clearReportUi();
    QString reportType=ui->cbReportType->currentText();
    QDate startDate=ui->dateStart->date();
    QDate endDate=ui->dateEnd->date();

    auto& db = DBManager::instance().getDB();
    QSqlQuery query(db);
    QString sql;

    // 总统计变量
    int totalOrderCount=0;
    double totalMoney=0.0;
    double totalWeight=0.0;

    if(reportType=="订单汇总报表")
    {
        // 设置表头
        m_reportModel->setHorizontalHeaderLabels({"订单号","客户名称","下单日期","订单金额","订单状态"});
        sql=
            "SELECT so.orderId, c.custName, so.orderDate, so.totalAmount, so.status "
            "FROM sale_order so "
            "INNER JOIN customer c ON so.custId = c.custId "
            "WHERE so.orderDate BETWEEN :startDate AND :endDate "
            "ORDER BY so.orderDate DESC";


        query.prepare(sql);
        query.bindValue(":startDate", startDate.toString("yyyy-MM-dd"));
        query.bindValue(":endDate", endDate.toString("yyyy-MM-dd 23:59:59"));
    }
    else if(reportType=="钢材销售明细报表")
    {
        m_reportModel->setHorizontalHeaderLabels({"订单号","客户名称","钢材规格","数量","单价","小计金额"});
        sql="SELECT so.orderId,c.custName,st.typeName||' '||ss.material||' '||ss.size AS specName, soi.saleNum, soi.salePrice, soi.subTotal "
              "FROM sale_order_item soi "
              "LEFT JOIN sale_order so  ON soi.orderId = so.orderId "
              "LEFT JOIN customer   c   ON so.custId   = c.custId "
              "LEFT JOIN steel_spec ss  ON soi.specId  = ss.specId "
              "LEFT JOIN steel_type st  ON ss.typeId   = st.typeId "
              "WHERE so.orderDate >= :startDate "
              "AND so.orderDate <= :endDate "
              "ORDER BY so.orderDate DESC";

        query.prepare(sql);
        query.bindValue(":startDate", startDate.toString("yyyy-MM-dd"));
        query.bindValue(":endDate", endDate.toString("yyyy-MM-dd 23:59:59"));
    }
    else if(reportType=="客户消费统计报表")
    {
        m_reportModel->setHorizontalHeaderLabels({"客户编号","客户名称","订单总数","消费总金额"});
        sql=
            "SELECT c.custId, c.custName, COUNT(so.orderId) AS orderCnt, SUM(so.totalAmount) AS sumAmount "
            "FROM customer c "
            "LEFT JOIN sale_order so ON c.custId = so.custId AND so.orderDate BETWEEN :startDate AND :endDate "
            "GROUP BY c.custId,c.custName "
            "ORDER BY sumAmount DESC";

        query.prepare(sql);
        query.bindValue(":startDate", startDate.toString("yyyy-MM-dd"));
        query.bindValue(":endDate", endDate.toString("yyyy-MM-dd 23:59:59"));
    }

    if(!query.exec())
    {
        // qDebug() << "报错来自：" << this->metaObject()->className();
        // qDebug() << "sql:" << query.lastQuery();
        // qDebug() << "bound values:" << query.boundValues();
        QMessageBox::critical(this,"查询失败", query.lastError().text());
        return;
    }

    int row=0;
    while(query.next())
    {
        int colCount = query.record().count();
        for(int col=0; col<colCount; col++)
        {
            QStandardItem* item = new QStandardItem(query.value(col).toString());
            item->setEditable(false); //报表只读，不能编辑
            m_reportModel->setItem(row, col, item);
        }
        // 汇总统计（根据报表类型累加）
        if(reportType=="订单汇总报表")
        {
            totalOrderCount++;
            totalMoney+=query.value("totalAmount").toDouble();
        }
        else if(reportType=="钢材销售明细报表")
        {
            totalWeight+=query.value("saleNum").toDouble();
            totalMoney+=query.value("subTotal").toDouble();
        }
        else if(reportType=="客户消费统计报表")
        {
            totalOrderCount+=query.value("orderCnt").toInt();
            totalMoney+=query.value("sumAmount").toDouble();
        }
        row++;
    }

    //更新底部统计标签
    ui->lblOrderCount->setText(QString::number(totalOrderCount));
    ui->lblTotalMoney->setText(QString::number(totalMoney,'f',2));
    ui->lblTotalWeight->setText(QString::number(totalWeight,'f',2));

    if(row == 0)
    {
        QMessageBox::information(this,"提示","未查询到报表数据");
    }
}

//导出CSV
void ReportWidget::on_btnExportCsv_clicked()
{
    if(m_reportModel->rowCount()==0) {
        QMessageBox::information(this, "提示", "没有可导出的数据，请先查询报表");
        return;
    }

    QString defaultName=QString("%1_%2_%3.csv")
                              .arg(ui->cbReportType->currentText())
                              .arg(ui->dateStart->date().toString("yyyyMMdd"))
                              .arg(ui->dateEnd->date().toString("yyyyMMdd"));
    QString filePath=QFileDialog::getSaveFileName(
        this,"导出CSV",defaultName,"CSV文件(*.csv)");
    if(filePath.isEmpty())
        return;

    if(exportModelToCsv(filePath))
        QMessageBox::information(this, "成功", "报表导出完成");
    else
        QMessageBox::critical(this, "失败", "文件写入失败");
}

//从tableview中导出csv
bool ReportWidget::exportModelToCsv(const QString &filePath)
{
    if (m_reportModel->rowCount()==0&&m_reportModel->columnCount()==0) {
        return false;   // 没数据就别导出
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
        return false;
    QTextStream out(&file);
    //设置utf8编码
    out.setEncoding(QStringConverter::Utf8);
    out.setGenerateByteOrderMark(true);

    const QString NL="\r\n";

    //辅助函数：CSV 转义，防止用户备注输入双引号"
    auto csvEscape=[](const QString &s) -> QString {
        QString t=s;
        t.replace("\"", "\"\"");
        return QString("\"%1\"").arg(t);
    };

    //写表头
    QStringList headers;
    for(int i=0;i<m_reportModel->columnCount();i++) {
        QStandardItem *h=m_reportModel->horizontalHeaderItem(i);
        //如果有表头就写入文本，没有就写入空字符串
        headers<<csvEscape(h?h->text():QString());
    }
    out<<headers.join(",")<<NL;

    //写数据行
    for(int i=0;i< m_reportModel->rowCount();i++) {
        QStringList line;
        for(int j=0;j<m_reportModel->columnCount();j++)
        {
            QStandardItem *item=m_reportModel->item(i,j);
            //如果有数据就写入文本，没有就写入空字符串
            line<<csvEscape(item?item->text():QString());
        }
        out<<line.join(",")<<NL;
    }
    file.close();
    return true;
}
