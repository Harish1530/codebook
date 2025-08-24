#include "indicators.h"

Indicators::Indicators(QObject *parent): QObject(parent), 
    leftTurnIndicator(false),
    rightTurnIndicator(false),
    lowFuelWarning(false),
    emergencyWarningLights(false) {}

void Indicators::setTurnIndicator(bool left, bool right) {
    leftTurnIndicator = left;
    rightTurnIndicator = right;
    emit turnIndicatorChanged(left, right);
}

void Indicators::setLowFuelWarning(bool active) {
    lowFuelWarning = active;
    emit lowFuelWarningChanged(active);
}

bool Indicators::isLeftTurnIndicatorActive() const {
    return leftTurnIndicator;
}

bool Indicators::isRightTurnIndicatorActive() const {
    return rightTurnIndicator;
}

bool Indicators::isLowFuelWarningActive() const {
    return lowFuelWarning;
}

bool Indicators::isEmergencyWarningLightsActive() const {
    return emergencyWarningLights;
}