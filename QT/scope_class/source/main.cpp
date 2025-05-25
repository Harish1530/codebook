#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "animal.h"

int addTen(int age){
    return age + 10;
}

int dogYears(int age){
    return age * 7;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int age;

    qInfo() << "Enter your age in years:";
    std::cin >> age;

    qInfo() << "Your age in 10 years:" << addTen(age);
    qInfo() << "Your age in dog years:" << dogYears(age);

    // qDebug() << "Hello, World!";

    QString name = "Dog";
    qInfo() << "Animal name:" << &name;

    Animal cat(&a, "Tom");
    Animal dog(&a, "Jerry");

    qInfo() << cat.name;
    qInfo() << dog.name;
    //Animal cat;

    qInfo() << cat.count;
    cat.getCount();
    Animal::getCount();

    cat.~Animal();

    return a.exec();
}