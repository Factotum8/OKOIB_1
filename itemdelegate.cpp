#include "itemdelegate.h"

ItemDelegate::ItemDelegate(QObject *parent):
    QItemDelegate(parent)
{
}

QWidget* ItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit* edit = new QLineEdit (parent);

    switch (index.column()) {
    case 0:
        return edit;
        //edit->setInputMask();
        break;
    case 1:
        edit->setInputMask("1980-2020");
        return edit;
        break;
    case 2:
        edit->setInputMask("1980-2020");
        return edit;
        break;
    case 3:
        edit->setInputMask("1980-2020");
        return edit;
        break;
    case 4:
        edit->setInputMask("0-1");
        return edit;
        break;
    case 5:
        edit->setInputMask("0-1");
        return edit;
        break;
    case 6:
        edit->setInputMask("0-1");
        return edit;
        break;
    case 7:
        edit->setInputMask("0-1");
        return edit;
        break;
    default:
        return edit;
        break;
    }
}
