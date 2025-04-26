#include "animal.h"

Animal::Animal(QObject *parent, QString name) : QObject(parent)
{
    // Constructor implementation
    this->name = name;
    qInfo() << this << "constructor called" << name;

}
Animal::~Animal()
{
    // Destructor implementation
    qInfo() << this << "Animal destructor called" << name;
}
void Animal::makeSound(QString message)
{
    qInfo() << this << "Animal sound:" << message;
}
double Animal::askingPrice()
{
    // Example implementation
    return weight * 10.0; // Assuming weight is in kg and price is $10 per kg
    
}
void Animal::test()
{
    qInfo() << this << "Test Called:" << name << "Weight:" << weight;
}