#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>
#include<QSqlRelationalTableModel>
namespace Ui {
class StockWidget;
}
QT_END_NAMESPACE
class StockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StockWidget(QWidget *parent = nullptr);
    ~StockWidget();

    void loadStockTable(); //加载库存表格

private:
    Ui::StockWidget *ui;
    QSqlRelationalTableModel *m_stockModel=nullptr;
signals:
private slots:
    void on_btnStockIn_clicked();
};

#endif // STOCKWIDGET_H
