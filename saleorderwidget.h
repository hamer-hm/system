#ifndef SALEORDERWIDGET_H
#define SALEORDERWIDGET_H

#include <QWidget>

class QSqlDatabase;
class QStandardItemModel;
namespace Ui {
class SaleOrderWidget;
}

class SaleOrderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SaleOrderWidget(QWidget *parent = nullptr);
    ~SaleOrderWidget();

    void reload();
private slots:
    void on_custName_currentIndexChanged(int index);

    void onBtnAddClicked();

    void on_btnDelete_clicked();

    void on_btnOk_clicked();

private:
    Ui::SaleOrderWidget *ui;

private:
    int m_orderId;  //订单号
    QString dateTime;//日期
    QString custName;//客户

    QStandardItemModel *itemModel=nullptr;

private:
    void loadInformation();                //自动填入信息
    void loadOrder(QSqlDatabase &db);      //加载订单
    void loadSale(QSqlDatabase &db);       //加载销售明细
    void loadSpecDelegate();               //加载钢材规格代理
    void loadNumericDelegate();            //加载doubleSpinBox代理
    void loadSum();                        //计算总额总数

    void initModel();                      //初始化model

signals:
    void order();
};

#endif // SALEORDERWIDGET_H
