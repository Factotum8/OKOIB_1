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
        edit->setInputMask("Nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
        return edit;
        break;
    case 1:
        edit->setValidator(new QIntValidator (1920,2020));
        return edit;
        break;
    case 2:
        edit->setValidator(new QIntValidator (1920,2020));
        return edit;
        break;
    case 3:
        edit->setValidator(new QIntValidator (1920,2020));
        return edit;
        break;
    case 4:
        edit->setInputMask("B");
        return edit;
        break;
    case 5:
        edit->setInputMask("B");
        return edit;
        break;
    case 6:
        edit->setInputMask("B");
        return edit;
        break;
    case 7:
        edit->setInputMask("B");
        return edit;
        break;
    default:
        return edit;
        break;
    }
}
