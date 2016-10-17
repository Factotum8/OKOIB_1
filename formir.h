#ifndef FORMIR_H
#define FORMIR_H

#include <QWidget>

namespace Ui {
class FormIr;
}

class FormIr : public QWidget
{
    Q_OBJECT

public:
    explicit FormIr(QWidget *parent = 0);
    ~FormIr();

private slots:
    void on_Exit_clicked();

private:
    Ui::FormIr *ui;
};

#endif // FORMIR_H
