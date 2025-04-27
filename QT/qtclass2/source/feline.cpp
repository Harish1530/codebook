#include "feline.h"

Feline::Feline(QObject *parent) : Mammal(parent)
{
    // Constructor implementation
    qInfo() << this << "feline constructed.";
}
Feline::~Feline()
{
    // Destructor implementation
    qInfo() << this << "feline destructed.";
}