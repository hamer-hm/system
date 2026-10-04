#ifndef ORDERQUERYWIDGET_H
#define ORDERQUERYWIDGET_H

#include <QWidget>
class QStandardItemModel;
class QSqlQuery;
class QItemSelection;
namespace Ui {
class OrderQueryWidget;
}

class OrderQueryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderQueryWidget(QWidget *parent = nullptr);
    ~OrderQueryWidget();

    void reload();   // 外部刷新接口（切库时调用）
private slots:
    void on_chkDateEnable_clicked(bool checked);

    void on_btnQuery_clicked();

    void onOrderSelected(const QItemSelection &selected, const QItemSelection &deselected);

    void on_btnReset_clicked();

private:
    Ui::OrderQueryWidget *ui;

    QStandardItemModel* m_orderModel=nullptr;   // 订单主表模型
    QStandardItemModel* m_itemModel=nullptr;    // 明细模型

    // 加载客户下拉框
    void loadCustomerCombo();
    // 加载订单状态下拉
    void loadStatusCombo();
    //加载主表
    void loadOrderTable(QSqlQuery &query);
    //初始化model
    void initModel();
public:
    //外部接口，供mainwindow调用，加载查询订单窗口
    void loadOrderQueryWidget();


};

#endif // ORDERQUERYWIDGET_H
