#ifndef AGECALC_H
#define AGECALC_H

#include <QObject>

class AgeCalc : public QObject
{
    Q_OBJECT
public:
    explicit AgeCalc(QObject *parent = nullptr);

    int age() const;
    void setAge(int age);

    QString name() const;
    void setName(const QString &name);

    int dogYears() const;
    int catYears() const;
    int manYears() const;

    void meow();

private: 
    int m_age;
    QString m_name;
};

#endif // AGECALC_H