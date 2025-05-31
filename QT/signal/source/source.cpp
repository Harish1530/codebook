#include "source.h"


Source::Source(QObject *parent) : QObject(parent)
{
    // Constructor implementation
    qDebug() << "Source object created.";
}

Source::~Source()
{
    // Destructor implementation
    qDebug() << "Source object destroyed.";
}

void Source::test()
{
    emit mySignal("Hello from Source!");
}