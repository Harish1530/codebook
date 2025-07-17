#include "rpmgauge.h"

RPMGauge::RPMGauge(QObject *parent) : QObject(parent), rpm(0.0f) {}

void RPMGauge::setRPM(float newRpm) {
    if (newRpm >= 0.0f) {
        rpm = newRpm;
        emit rpmChanged(rpm);
    }
}

float RPMGauge::getRPM() const {
    return rpm;
}