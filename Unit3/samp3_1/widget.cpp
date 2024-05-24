#include "widget.h"
#include "ui_widget.h"
#include <QMetaClassInfo>
#include <QMetaProperty>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    boy = new QPerson("王小明");
    boy->setProperty("score",95);
    boy->setProperty("age",10);
    boy->setProperty("sex","Boy");
    connect(boy, &QPerson::ageChanged,this,&Widget::on_ageChanged);

    girl = new QPerson("张小丽");
    girl->setProperty("score",81);
    girl->setProperty("age",20);
    girl->setProperty("sex","Girl");
    connect(girl,&QPerson::ageChanged,this,&Widget::on_ageChanged);

    ui->spinBoy->setProperty("isBoy",true);
    ui->spinGirl->setProperty("isBoy",false);

    connect(ui->spinGirl,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoy,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ageChanged(int value)
{
    Q_UNUSED(value);
    QPerson *aPerson = qobject_cast<QPerson *>(sender());
    QString hisName=aPerson->property("name").toString();
    QString hisSex=aPerson->property("sex").toString();
    int hisAge=aPerson->age();
    // int hisAge=aPerson->property("age").toInt();
    ui->plainTextEdit->appendPlainText(hisName+","+hisSex+QString::asprintf(",年龄=%d",hisAge));
}

void Widget::on_spin_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    QSpinBox *spinBox=qobject_cast<QSpinBox *>(sender());
    if(spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}

void Widget::on_btnBoy_clicked()
{
    boy->incAge();
}

void Widget::on_btnGirl_clicked()
{
    girl->incAge();
}

void Widget::on_btnInfo_clicked()
{
    const QMetaObject *meta=boy->metaObject();
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("==元对象信息==\n");
    ui->plainTextEdit->appendPlainText(QString("类名称：%1\n").arg(meta->className()));
    ui->plainTextEdit->appendPlainText("property");
    for(int i=meta->propertyOffset();i<meta->propertyCount();i++)
    {
        QMetaProperty prop=meta->property(i);
        const char * propName=prop.name();
        QString propValue=boy->property(propName).toString();
        ui->plainTextEdit->appendPlainText(QString("属性名称=%1，属性值=%2").arg(propName).arg(propValue));
    }

    ui->plainTextEdit->appendPlainText("");
    ui->plainTextEdit->appendPlainText("classInfo");
    for(int i=meta->classInfoOffset();i<meta->classInfoCount();i++)
    {
        QMetaClassInfo classInfo=meta->classInfo(i);
        ui->plainTextEdit->appendPlainText(QString("Name=%1; Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}

void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}
