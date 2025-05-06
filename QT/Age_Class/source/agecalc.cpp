#include "agecalc.h"
#include <QDebug>

AgeCalc::AgeCalc(QObject *parent) : QObject(parent)
{
}

int AgeCalc::age() const
{
    return m_age;
}

void AgeCalc::setAge(int age)
{
    m_age = age;
}

QString AgeCalc::name() const
{
    return m_name;
}

void AgeCalc::setName(const QString &name)
{
    m_name = name;
}

int AgeCalc::dogYears() const
{
    return m_age * 7;
}

int AgeCalc::catYears() const
{
    return m_age * 5;
}

int AgeCalc::manYears() const
{
    return m_age;
}

void AgeCalc::meow()
{
    for(int i = 0; i < 3; i++)
    {
        qInfo() << "Meow!";
    }
}