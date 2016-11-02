#ifndef FORMCOSTINDEX_H
#define FORMCOSTINDEX_H

#include <QWidget>

namespace Ui {
class FormCostIndex;
}

class FormCostIndex : public QWidget
{
    Q_OBJECT

public:
    explicit FormCostIndex(QWidget *parent = 0);
    ~FormCostIndex();

private:
    Ui::FormCostIndex *ui;
};

#endif // FORMCOSTINDEX_H
