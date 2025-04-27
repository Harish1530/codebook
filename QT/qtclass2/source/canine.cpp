#include "canine.h"

Canine::Canine(QObject *parent) : Mammal(parent)
{
    // Constructor implementation
    qInfo() << this << "canine constructed.";
}
Canine::~Canine()
{
    // Destructor implementation
    qInfo() << this << "canine destructed.";
}