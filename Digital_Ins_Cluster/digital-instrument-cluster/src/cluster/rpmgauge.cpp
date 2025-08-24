#include "rpmgauge.h"

RPMGauge::RPMGauge(QObject *parent) : QObject(parent), currentRPM(0.0f) {}

void RPMGauge::setRPM(float newRpm) {
    if (newRpm >= 0.0f) {
        currentRPM = newRpm;
        emit rpmChanged(currentRPM);
    }
}

float RPMGauge::getRPM() const {
    return currentRPM;
}