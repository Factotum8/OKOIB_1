#ifndef TABLEIR_H
#define TABLEIR_H

//#include <QWidget>
#include <QtWidgets>
#include <QLabel>
#include <QTableWidget>
#include <QStandardItemModel>
//#include <QStringListModel>
#include <QItemSelectionModel>
#include <QDebug>

#include "ui_tableir.h"
#include "global.h"
#include "errorform.h"
#include "tabwidgetir.h"
#include "itemdelegate.h"

#define  COLUMNCOUNT 8

//extern TabWidgetIr *twi;

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

    void on_exit_butt_clicked();

private:
    Ui::TableIr *ui;
    void    set_boolval (int i,int j ,int str);
    QDate   set_dateval (int str);
    bool    isnull      (int i,int j);
    bool    dataisnull  (int i, int j);
};

#endif // TABLEIR_H
