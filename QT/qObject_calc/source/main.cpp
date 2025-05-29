#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "calc.h"

Calc* getCalc(){
    Calc* cal = new Calc(); //Creating object on heap
    return cal; //Returning pointer to the object
}

int dogYears(int age, Calc *cal)
{
    return cal->dogYears(age);
}
int catYears(int age, Calc *cal)
{
    return cal->catYears(age);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "Qt Core application started.";

    Calc *cal = getCalc(); // Get the Calc object
    qInfo() << "Enter your age";
    int age;
    std::cin >> age; // Read age from standard input

    qInfo() << "Your age in dog years is:" << dogYears(age, cal);
    qInfo() << "Your age in cat years is:" << catYears(age, cal);

    delete cal; // Clean up the Calc object
    return app.exec();
}