#include "animal.h"

Animal::Animal(QObject *parent, QString name) : QObject(parent)
{
    // Constructor implementation
    this->name = name;
    qInfo() << "Animal name param: " << &name << " = " << name;
    qInfo() << "Animal name: " << this->name << " = " << this->name;
    count++;
}
Animal::~Animal()
{
    qInfo() << "Animal destructor called for:" << this->name;
    // Destructor implementation
    count--;
}
void Animal::makeSound(QString message)
{
    // Default implementation (if any)
    qDebug() << "Animal makes a sound";
}

void Animal::getCount()
{
    qInfo() << "Animal count:";
}