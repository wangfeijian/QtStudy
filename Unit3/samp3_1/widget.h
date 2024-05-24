#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qperson.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPerson *boy;
    QPerson *girl;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_ageChanged(int value);
    void on_spin_valueChanged(int arg1);
    void on_btnBoy_clicked();

    void on_btnGirl_clicked();

    void on_btnInfo_clicked();

    void on_btnClear_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
