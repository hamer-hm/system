#ifndef STOCKINDIALOG_H
#define STOCKINDIALOG_H

#include <QDialog>

namespace Ui {
class StockInDialog;
}

class StockInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StockInDialog(QWidget *parent = nullptr);
    ~StockInDialog();

private:
    Ui::StockInDialog *ui;
    void loadSteelSpecCombo();//加载comboBox item

public:
    int getTypeId();          //获取typeId
    double getStockNum();        //获取StockNum
};

#endif // STOCKINDIALOG_H
