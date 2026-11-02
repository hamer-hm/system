#include "specdelegate.h"
#include<QComboBox>
#include<QSqlQuery>
#include"dbmanager.h"

specDelegate::specDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
}


QWidget *specDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *com=new QComboBox(parent);
    //获取数据库
    auto &db=DBManager::instance().getDB();
    QSqlQuery query(db);
    //查询根据typeid查询出specId、price同时将typeName、material、size 拼成specName
    query.exec("SELECT specId, typeName || ' ' || material || ' ' || size AS specName, price "
                  "FROM steel_spec LEFT JOIN steel_type ON steel_spec.typeId = steel_type.typeId");
    //循环添加combobox的item
    while(query.next())
    {
        //specId
        int specId=query.value(0).toInt();
        //specName
        QString specName=query.value(1).toString();
        //price
        double price=query.value(2).toDouble();
        //将specName加入combobox，specId加入userRole
        com->addItem(specName,specId);
        //price加入userRole+1
        com->setItemData(com->count()-1,price,Qt::UserRole+1);

    }
    // //当combobox的index改变时发出信号传出当前的price
    // connect(com,&QComboBox::currentIndexChanged,this,[=](int index){
    //     //price
    //     double mPrice=com->currentData(Qt::UserRole+1).toDouble();
    //     //specId
    //     int specId=com->currentData(Qt::UserRole).toInt();
    //     emit const_cast<specDelegate*>(this)->specSelected(row,mPrice,specId);
    // });


    return static_cast<QWidget*>(com);
}

void specDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    QComboBox *com =static_cast<QComboBox*>(editor);
    //将model的文本写入combobox
    QString text=index.model()->data(index,Qt::DisplayRole).toString();

    com->setCurrentText(text);
}

void specDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *com =static_cast<QComboBox*>(editor);
    //获取combobox当前的文本
    QString text=com->currentText();
    //将combobox当前的文本写入model
    model->setData(index,text,Qt::EditRole);
    //将combobox当前的specId写入model
    model->setData(index, com->currentData(), Qt::UserRole);
    //将combobox当前的price写入model
    double price=com->itemData(com->currentIndex(),Qt::UserRole+1).toDouble();
    model->setData(index, price, Qt::UserRole+1);
}

void specDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
