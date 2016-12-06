#include "itemdelegatecostindex.h"

itemDelegateCostIndex::itemDelegateCostIndex(QObject *parent):
    QItemDelegate(parent)
{
}


QWidget* itemDelegateCostIndex::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit* edit = new QLineEdit (parent);

    edit->setValidator(new QDoubleValidator(0.0,999.0,3,parent));

    return edit;
}

void itemDelegateCostIndex::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    QString value =index.model()->data(index, Qt::EditRole).toString();
        QLineEdit *line = static_cast<QLineEdit*>(editor);
        line->setText(value);
}


void itemDelegateCostIndex::setModelData(QWidget *editor,
                                QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
    QString value = line->text();
    model->setData(index, value);
}
