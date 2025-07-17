#include "mockcan.h"
#include <QTimer>
#include <QDebug>

MockCAN::MockCAN(QObject *parent) : QObject(parent), timer(new QTimer(this)) {
    connect(timer, &QTimer::timeout, this, &MockCAN::generateMockData);
}

void MockCAN::startMock() {
    timer->start(1000); // Generate mock data every second
}

void MockCAN::stopMock() {
    timer->stop();
}

void MockCAN::generateMockData() {
    // Simulate CAN messages for speed, RPM, and fuel level
    float speed = static_cast<float>(qrand() % 200); // Random speed between 0 and 200
    float rpm = static_cast<float>(qrand() % 8000); // Random RPM between 0 and 8000
    float fuelLevel = static_cast<float>(qrand() % 100); // Random fuel level between 0 and 100

    emit speedChanged(speed);
    emit rpmChanged(rpm);
    emit fuelLevelChanged(fuelLevel);
}