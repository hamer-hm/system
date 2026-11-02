#ifndef STOCKINDIALOG_H
#define STOCKINDIALOG_H

#include <QDialog>
#include <QVariantMap>
namespace Ui {
class StockInDialog;
}

class StockInDialog : public QDialog
{
    Q_OBJECT
public:
    explicit StockInDialog(QWidget *parent = nullptr);
    ~StockInDialog();
    int getSpecId();
    int getTypeId();
    double getStockNum();
    double getCostPrice();
private slots:
    void on_btnOk_clicked();
private:
    void loadSteelSpecCombo();
    Ui::StockInDialog *ui;
};
#endif // STOCKINDIALOG_H
