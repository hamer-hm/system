#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>
#include<QSqlRelationalTableModel>
namespace Ui {
class StockWidget;
}

class StockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StockWidget(QWidget *parent = nullptr);
    ~StockWidget();

    void reload();  //外部刷新接口（切库时调用）

private:
    Ui::StockWidget *ui;
    QSqlRelationalTableModel *m_stockModel=nullptr;
    //初始化model
    void initModel();
signals:
private slots:
    void on_btnStockIn_clicked();
    void on_btnStockDel_clicked();

// protected:
//     void showEvent(QShowEvent *event) override;
};

#endif // STOCKWIDGET_H
