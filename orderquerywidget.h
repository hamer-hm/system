#ifndef ORDERQUERYWIDGET_H
#define ORDERQUERYWIDGET_H

#include <QWidget>

namespace Ui {
class OrderQueryWidget;
}

class OrderQueryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OrderQueryWidget(QWidget *parent = nullptr);
    ~OrderQueryWidget();

private:
    Ui::OrderQueryWidget *ui;
};

#endif // ORDERQUERYWIDGET_H
