#include "mockcan.h"
#include <QTimer>
#include <QDebug>
#include <random>

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
    // Use static to initialize the random engine and distributions only once
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> speedDist(0.0f, 200.0f);
    static std::uniform_real_distribution<float> rpmDist(0.0f, 8000.0f);
    static std::uniform_real_distribution<float> fuelDist(0.0f, 100.0f);

    float speed = speedDist(gen);
    float rpm = rpmDist(gen);
    float fuelLevel = fuelDist(gen);

    emit speedChanged(speed);
    emit rpmChanged(rpm);
    emit fuelLevelChanged(fuelLevel);
}