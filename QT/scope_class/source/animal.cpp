#include "animal.h"

Animal::Animal(QObject *parent, QString name) : QObject(parent)
{
    // Constructor implementation
    this->name = name;
    qInfo() << "Animal name param: " << &name << " = " << name;
    qInfo() << "Animal name: " << this->name << " = " << this->name;
}
Animal::~Animal()
{
    qInfo() << "Animal destructor called for:" << this->name;
    // Destructor implementation
}
void Animal::makeSound(QString message)
{
    // Default implementation (if any)
    qDebug() << "Animal makes a sound";
}