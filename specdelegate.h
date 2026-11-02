#ifndef SPECDELEGATE_H
#define SPECDELEGATE_H

#include <QObject>
#include<QStyledItemDelegate>
class specDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit specDelegate(QObject *parent = nullptr);

signals:
    void specSelected(int row, /*int specId, */double price,int specId);
    // QAbstractItemDelegate interface
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // SPECDELEGATE_H
