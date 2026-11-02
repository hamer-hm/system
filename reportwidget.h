#ifndef REPORTWIDGET_H
#define REPORTWIDGET_H

#include <QWidget>
class QStandardItemModel;
class QSqlQuery;

namespace Ui {
class ReportWidget;
}

class ReportWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ReportWidget(QWidget *parent = nullptr);
    ~ReportWidget();

    //外部刷新接口（切库时调用）
    void reload();
private slots:
    void on_btnQueryReport_clicked();
    void on_btnExportCsv_clicked();

private:
    Ui::ReportWidget *ui;
    QStandardItemModel* m_reportModel=nullptr;
    //初始化model
    void initModel();
    // 加载报表数据
    void loadReportData();
    // 清空表格和统计标签
    void clearReportUi();
    // 导出模型到CSV
    bool exportModelToCsv(const QString& filePath);
};

#endif // REPORTWIDGET_H
