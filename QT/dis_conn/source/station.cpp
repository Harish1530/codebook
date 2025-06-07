#include "station.h"

Station::Station(QObject *parent, int frequency, QString mode): QObject(parent)
{
    // Constructor implementation
    this-> frequency = frequency;
    this-> mode = mode;
}

Station::~Station()
{
    // Destructor implementation
}
void Station::broadcast(QString message)
{
    // Slot implementation
    qDebug() << "Broadcasting message on frequency:" << frequency << "with mode:" << mode << "Message:" << message;
    // Emit the send signal with current frequency and mode
    emit send(frequency, mode,message);
}