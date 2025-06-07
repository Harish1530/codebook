#include "radio.h"

Radio::Radio(QObject *parent)
    : QObject(parent)
{
    // Constructor implementation
    qDebug() << "Radio object created";
}

Radio::~Radio()
{
    // Destructor implementation
    qDebug() << "Radio object destroyed";
}

void Radio::listen(int frequency, QString mode, QString message)
{
    // Slot implementation
    qDebug() << "Listening on frequency:" << frequency << "with mode:" << mode << "-" << message;;
    // Emit the stop signal when done
    emit stop();
}