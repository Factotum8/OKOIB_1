#ifndef TABWIDGETIR_H
#define TABWIDGETIR_H

#include <QWidget>
#include <qtabwidget.h>
#include <QWidgetList>
#include <QLabel>

#include "ui_tabwidgetir.h"
#include "global.h"
#include "formir.h"


namespace Ui {
class TabWidgetIr;
}

class TabWidgetIr : public QWidget
{
    Q_OBJECT

public:
    explicit TabWidgetIr(QWidget *parent = 0);
    ~TabWidgetIr();
    QTabWidget* get_TabWidget ();

private slots:
    void on_ButtonMainExit_clicked();

private:
    Ui::TabWidgetIr *ui;
};

#endif // TABWIDGETIR_H
