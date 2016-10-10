#ifndef TABLEIR_H
#define TABLEIR_H

#include <QWidget>

#include "ui_tableir.h"
#include "global.h"

#define  COLUMNCOUNT 7

namespace Ui {
class TableIr;
}

class TableIr : public QWidget
{
    Q_OBJECT

public:
    explicit TableIr(QWidget *parent = 0);
    ~TableIr();

private slots:
    void on_save_butt_clicked();

    void on_exit_butt_destroyed();

    void on_exit_butt_clicked();

private:
    Ui::TableIr *ui;
};

#endif // TABLEIR_H
