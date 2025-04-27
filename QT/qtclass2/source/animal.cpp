#include "animal.h"

Animal::Animal(QObject *parent) : QObject(parent)
{
    // Constructor implementation
    qInfo() << this << "animal cronstructed.";

}
