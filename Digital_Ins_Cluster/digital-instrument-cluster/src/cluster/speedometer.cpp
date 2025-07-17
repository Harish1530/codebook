#include "speedometer.h"

Speedometer::Speedometer() : speed(0.0f) {}

void Speedometer::setSpeed(float newSpeed) {
    speed = newSpeed;
    updateDisplay();
}

float Speedometer::getSpeed() const {
    return speed;
}

void Speedometer::updateDisplay() {
    // Code to update the speedometer display
    // This could involve emitting a signal or updating a QML property
}