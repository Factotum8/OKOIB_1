#ifndef TABLEIR_H
#define TABLEIR_H

#include <QWidget>

namespace Ui {
class TableIr;
}

class TableIr : public QWidget
{
    Q_OBJECT

public:
    explicit TableIr(QWidget *parent = 0);
    ~TableIr();

private:
    Ui::TableIr *ui;
};

#endif // TABLEIR_H
