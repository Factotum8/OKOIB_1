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
        edit->setPlaceholderText("1920-2020");
        edit->setValidator(new QIntValidator (1920,2020,parent));
        return edit;
        break;
    case 2:
        edit->setPlaceholderText("1920-2020");
        edit->setValidator(new QIntValidator (1920,2020,parent));
        return edit;
        break;
    case 3:
        edit->setPlaceholderText("1920-2020");
        edit->setValidator(new QIntValidator (1920,2020,parent));
        return edit;
        break;
    case 4:
        edit->setPlaceholderText("0 или 1");
        edit->setInputMask("B");
        return edit;
        break;
    case 5:
        edit->setPlaceholderText("0 или 1");
        edit->setInputMask("B");
        return edit;
        break;
    case 6:
        edit->setPlaceholderText("0 или 1");
        edit->setInputMask("B");
        return edit;
        break;
    case 7:
        edit->setPlaceholderText("0 или 1");
        edit->setInputMask("B");
        return edit;
        break;
    default:
        return edit;
        break;
    }
}

void ItemDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    QString value =index.model()->data(index, Qt::EditRole).toString();
        QLineEdit *line = static_cast<QLineEdit*>(editor);
        line->setText(value);
}


void ItemDelegate::setModelData(QWidget *editor,
                                QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);
    QString value = line->text();
    model->setData(index, value);
}
