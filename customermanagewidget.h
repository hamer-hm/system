#ifndef CUSTOMERMANAGEWIDGET_H
#define CUSTOMERMANAGEWIDGET_H

#include <QWidget>
// 前置声明，减少头文件依赖
class QStandardItemModel;
namespace Ui {
class CustomerManageWidget;
}

// 客户管理主界面类
class CustomerManageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomerManageWidget(QWidget *parent = nullptr);
    ~CustomerManageWidget();
    //外部刷新接口（切库时调用）
    void reload();
private slots:
    // 查询按钮点击槽函数
    void on_btnQuery_clicked();
    // 重置按钮点击槽函数
    void on_btnReset_clicked();
    // 新增客户按钮
    void on_btnAdd_clicked();
    // 编辑客户按钮
    void on_btnEdit_clicked();
    // 删除客户按钮
    void on_btnDelete_clicked();
    // 表格双击行，打开编辑
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::CustomerManageWidget *ui;
    // 客户列表模型
    QStandardItemModel* m_custModel = nullptr;
    // 加载客户数据，根据筛选条件查询并刷新表格
    void loadCustomerData();
    //加载数据
    //重建模型
    void initModel();
};

#endif // CUSTOMERMANAGEWIDGET_H
