#include "qwdlgmanual.h"

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    initUi();
    initSignalSlots();
    setWindowTitle("Form created mannually");
}

QWDlgManual::~QWDlgManual()
{

}

void QWDlgManual::initUi()
{
    chkBoxBold = new QCheckBox(tr("Bold"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxUnder = new QCheckBox(tr("Underline"));
    QHBoxLayout *hLay1 = new QHBoxLayout;
    hLay1->addWidget(chkBoxBold);
    hLay1->addWidget(chkBoxItalic);
    hLay1->addWidget(chkBoxUnder);

    rBtnBlack = new QRadioButton(tr("Black"));

    rBtnBlue = new QRadioButton(tr("Blue"));
    QPalette pBlue = rBtnBlue->palette();
    pBlue.setColor(QPalette::Text,Qt::blue);
    rBtnBlue->setPalette(pBlue);

    rBtnRed = new QRadioButton(tr("Red"));
    QPalette pRed = rBtnRed->palette();
    pRed.setColor(QPalette::Text,Qt::red);
    rBtnRed->setPalette(pRed);

    QHBoxLayout *hLay2 = new QHBoxLayout;
    hLay2->addWidget(rBtnBlack);
    hLay2->addWidget(rBtnBlue);
    hLay2->addWidget(rBtnRed);

    btnOK = new QPushButton(tr("确  定"));
    btnCancle = new QPushButton(tr("取  消"));
    btnClose = new QPushButton(tr("退  出"));
    QHBoxLayout *hLay3 = new QHBoxLayout;
    hLay3->addWidget(btnOK);
    hLay3->addWidget(btnCancle);
    hLay3->addWidget(btnClose);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello, World\n\nIt is my demo");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);
    QHBoxLayout *txtLay = new QHBoxLayout;
    txtLay->addWidget(txtEdit);

    QVBoxLayout *vLay = new QVBoxLayout;
    vLay->addLayout(hLay1);
    vLay->addLayout(hLay2);
    vLay->addLayout(txtLay);
    vLay->addLayout(hLay3);
    setLayout(vLay);
}

void QWDlgManual::initSignalSlots()
{
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));

    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxBold(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxUnder(bool)));

    connect(btnOK, SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancle, SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()),this,SLOT(close()));
}

void QWDlgManual::on_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::setTextFontColor()
{
    QPalette plet=txtEdit->palette();
    if(rBtnBlue->isChecked())
        plet.setColor(QPalette::Text, Qt::blue);
    else if(rBtnRed->isChecked())
        plet.setColor(QPalette::Text, Qt::red);
    else if(rBtnBlack->isChecked())
        plet.setColor(QPalette::Text, Qt::black);
    else
        plet.setColor(QPalette::Text, Qt::black);

    txtEdit->setPalette(plet);
}
