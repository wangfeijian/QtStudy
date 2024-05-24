#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QHBoxLayout>

class QWDlgManual : public QDialog
{
    Q_OBJECT

public:
    QWDlgManual(QWidget *parent = 0);
    ~QWDlgManual();
private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QRadioButton *rBtnBlack;
    QRadioButton *rBtnRed;
    QRadioButton *rBtnBlue;
    QPlainTextEdit *txtEdit;
    QPushButton *btnOK;
    QPushButton *btnCancle;
    QPushButton *btnClose;
    void initUi();
    void initSignalSlots();
private slots:
    void on_chkBoxUnder(bool checked);
    void on_chkBoxItalic(bool checked);
    void on_chkBoxBold(bool checked);
    void setTextFontColor();
};

#endif // QWDLGMANUAL_H
