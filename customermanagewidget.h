#ifndef CUSTOMERMANAGEWIDGET_H
#define CUSTOMERMANAGEWIDGET_H

#include <QWidget>

namespace Ui {
class CustomerManageWidget;
}

class CustomerManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerManageWidget(QWidget *parent = nullptr);
    ~CustomerManageWidget();

private:
    Ui::CustomerManageWidget *ui;
};

#endif // CUSTOMERMANAGEWIDGET_H
