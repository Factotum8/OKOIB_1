#ifndef TABWIDGETIR_H
#define TABWIDGETIR_H

#include <QWidget>
#include <qtabwidget.h>



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

private:
    Ui::TabWidgetIr *ui;
};

#endif // TABWIDGETIR_H
