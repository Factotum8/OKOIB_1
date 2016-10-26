#ifndef ITEMDELEGATEFLOAT_H
#define ITEMDELEGATEFLOAT_H

#include <QItemDelegate>
#include <QLineEdit>

#include "global.h"

class ItemDelegateFloat: public QItemDelegate
{
    Q_OBJECT
public:
    explicit ItemDelegateFloat(QObject *parent=0);

protected:

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
};

#endif // ITEMDELEGATEFLOAT_H
