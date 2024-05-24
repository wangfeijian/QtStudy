#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "WangFeijian")
    Q_CLASSINFO("company", "Soso")
    Q_CLASSINFO("version", "1.0.0")
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
private:
    int m_age=10;
    QString m_name;
    int m_score=70;
public:
    explicit QPerson(QString fName, QObject *parent = nullptr);
    int age();
    void setAge(int value);
    void incAge();
signals:
    ageChanged(int value);
public slots:
};

#endif // QPERSON_H
