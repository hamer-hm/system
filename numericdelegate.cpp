#include "numericdelegate.h"
#include<QDoubleSpinBox>
NumericDelegate::NumericDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}


QWidget *NumericDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QDoubleSpinBox *dbSpinBox=new QDoubleSpinBox(parent);
    dbSpinBox->setRange(1,50000);
    dbSpinBox->setSingleStep(1);
    connect(dbSpinBox,&QDoubleSpinBox::valueChanged,this,[=](double value){
        emit const_cast<NumericDelegate*>(this)->valueChanged(index,value);
    });
    return static_cast<QWidget*>(dbSpinBox);
}

void NumericDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDoubleSpinBox *dbSpinBox=static_cast<QDoubleSpinBox*>(editor);
    double value=index.model()->data(index,Qt::DisplayRole).toDouble();
    dbSpinBox->setValue(value);
}

void NumericDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDoubleSpinBox *dbSpinBox=static_cast<QDoubleSpinBox*>(editor);
    double value=dbSpinBox->value();
    model->setData(index,value);
}

void NumericDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
