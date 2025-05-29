#include "calc.h"
#include <iostream>
#include <QDebug>

Calc::Calc(QObject *parent) : QObject(parent)
{
    qDebug() << "Calc object created.";
}
Calc::~Calc()
{
    qDebug() << "Calc object destroyed.";
}
int Calc::dogYears(int age) const
{
    if (age < 0) {
        qWarning() << "Invalid age for dog: " << age;
        return -1; // Invalid input
    }
    int dogAge = age * 7; // Simple conversion
    qDebug() << "Dog years for age" << age << ":" << dogAge;
    return dogAge;
}
int Calc::catYears(int age) const
{
    if (age < 0) {
        qWarning() << "Invalid age for cat: " << age;
        return -1; // Invalid input
    }
    int catAge = age * 6; // Simple conversion
    qDebug() << "Cat years for age" << age << ":" << catAge;
    return catAge;
}
