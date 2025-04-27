#include "mammal.h"
Mammal::Mammal(QObject *parent) : Animal(parent)
{
    // Constructor implementation
    qInfo() << this << "mammal constructed.";
}
Mammal::~Mammal()
{
    // Destructor implementation
    qInfo() << this << "mammal destructed.";
}