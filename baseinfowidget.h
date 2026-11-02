#ifndef BASEINFOWIDGET_H
#define BASEINFOWIDGET_H

#include <QWidget>

class QSqlRelationalTableModel;
class QItemSelectionModel;
class QComboBox;
class QSpinBox;
class QLineEdit;
class QDialog;
class QGroupBox;
namespace Ui {
class BaseInfoWidget;
}

class BaseInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseInfoWidget(QWidget *parent = nullptr);
    ~BaseInfoWidget();

    // 刷新数据表（切库时调用）
    void reloadTable();

private slots:
    void on_btnAdd_clicked();
    void on_btnDel_clicked();
    void on_btnExport_clicked();
    void onFormBtnOkClicked();
    void onFormBtnCancelClicked();

private:
    void openSpecTable();
    QGroupBox *creatFormGroup();

    Ui::BaseInfoWidget *ui;
    QSqlRelationalTableModel *specModel = nullptr;
    QItemSelectionModel *selModel = nullptr;

    // 新增dialog相关
    QDialog *dlg = nullptr;
    QComboBox *m_cboTypeName = nullptr;
    QSpinBox *m_spinPrice = nullptr;
    QLineEdit *m_editSpecId = nullptr;
    QLineEdit *m_editMaterial = nullptr;
    QLineEdit *m_editSize = nullptr;
    QLineEdit *m_editUnit = nullptr;
    QLineEdit *m_editRemark = nullptr;
};

#endif // BASEINFOWIDGET_H
