#include "speedometer.h"

Speedometer::Speedometer(QObject *parent)
    : QObject(parent), currentSpeed(0.0f) {}

void Speedometer::setSpeed(float newSpeed) {
    if (currentSpeed != newSpeed) {
        currentSpeed = newSpeed;
        emit speedChanged(currentSpeed); // <-- Notify UI/QML
        updateDisplay();
    }
}

float Speedometer::getSpeed() const {
    return currentSpeed;
}

void Speedometer::updateDisplay() {
    // Example: Print to debug or update a UI element
    qDebug() << "Speed updated to:" << currentSpeed;
    // In a real app, you might update a QML property or emit a signal
}