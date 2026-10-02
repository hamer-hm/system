#ifndef CUSTOMEREDITDIALOG_H
#define CUSTOMEREDITDIALOG_H

#include <QDialog>
namespace Ui {
class CustomerEditDialog;
}

// 新增/编辑客户共用弹窗
class CustomerEditDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CustomerEditDialog(QWidget *parent = nullptr);
    ~CustomerEditDialog();
    // 设置是否为新增模式
    void setIsNew(bool isNew);
    // 设置待编辑客户ID，编辑模式使用
    void setCustId(const QString& id);

private slots:
    // 保存按钮
    void on_btnSave_clicked();
    // 取消按钮
    void on_btnCancel_clicked();

private:
    Ui::CustomerEditDialog *ui;
    bool m_isNew = true;         // true新增 false编辑
    QString m_custId;            // 当前编辑客户主键 custId
    // 根据custId查询数据，填充表单
    void loadCustomerInfo();
};

#endif // CUSTOMEREDITDIALOG_H
