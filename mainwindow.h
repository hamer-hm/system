#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlineedit.h>
class QSqlRelationalTableModel;
class QGroupBox;
class QSpinBox;
class QComboBox;
class QItemSelectionModel;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();           //基础资料新增一行

    void on_btnDel_clicked();

    void on_btnExport_clicked();


private:
    Ui::MainWindow *ui;


private:
    QSqlRelationalTableModel *specModel;//显示基础资料的tabmodel
    QItemSelectionModel *selModel;
    void openSpecTable();               //打开基础资料表
    QGroupBox *creatFormGroup();         //基础资料模块基本信息groupbox
    void onFormBtnOkClicked();          //基础资料新增一行dialog确定按钮槽函数
    void onFormBtnCancelClicked();      //基础资料新增一行dialog取消按钮槽函数

    void openStockTable();              //打开销售表

    QDialog *dlg;
    QLineEdit *m_editSpecId;
    QLineEdit *m_editMaterial;
    QLineEdit *m_editSize;
    QLineEdit *m_editUnit;
    QLineEdit *m_editRemark;
    QSpinBox *m_spinPrice;
    QComboBox *m_cboTypeName;

};
#endif // MAINWINDOW_H
