#ifndef FORMINFORMATIONRESOURCESCOSTS_H
#define FORMINFORMATIONRESOURCESCOSTS_H

#include <QWidget>

#include "glob.h"
#include "struct.h"
#include "ir.h"

extern cost_index* c_index;
extern IR *ir;
extern int count_ir;

namespace Ui {
class FormInformationResourcesCosts;
}

class FormInformationResourcesCosts : public QWidget
{
    Q_OBJECT

public:
    explicit FormInformationResourcesCosts(QWidget *parent = 0);
    ~FormInformationResourcesCosts();

private slots:
    void on_butt_writef_file_clicked();

    void on_exit_clicked();

private:
    Ui::FormInformationResourcesCosts *ui;
};

#endif // FORMINFORMATIONRESOURCESCOSTS_H
