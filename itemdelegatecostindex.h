#ifndef ITEMDELEGATECOSTINDEX_H
#define ITEMDELEGATECOSTINDEX_H

#include <QItemDelegate>
#include <QLineEdit>

class itemDelegateCostIndex : public QItemDelegate
{
    Q_OBJECT
public:
    explicit itemDelegateCostIndex(QObject *parent=0);

protected:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
};

#endif // ITEMDELEGATECOSTINDEX_H
