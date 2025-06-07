#include "monitor.h"

Monitor::Monitor(QObject *parent) : QObject(parent)
{
    qDebug() << "Monitor object created";
}
Monitor::~Monitor()
{
    qDebug() << "Monitor object destroyed";
}
void Monitor::closing(QString reason)
{
    qDebug() << "Monitor object closing with reason:" << reason;
    // Additional cleanup or actions can be added here
}