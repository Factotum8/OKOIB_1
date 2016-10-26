#include "itemdelegatefloat.h"

ItemDelegateFloat::ItemDelegateFloat(QObject *parent):
    QItemDelegate(parent)
{
}

QWidget* ItemDelegateFloat::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit* edit = new QLineEdit (parent);

//        edit->setValidator(new QDoubleValidator(0.0,999.0,3));
        edit->setValidator(new QIntValidator());

        return edit;

}

void ItemDelegateFloat::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    QString value =index.model()->data(index, Qt::EditRole).toString();
        QLineEdit *line = static_cast<QLineEdit*>(editor);
        line->setText(value);
}


void ItemDelegateFloat::setModelData(QWidget *editor,
                                QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
    QString value = line->text();
    model->setData(index, value);
}
