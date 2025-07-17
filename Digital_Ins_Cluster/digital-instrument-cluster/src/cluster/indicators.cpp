#include "indicators.h"

Indicators::Indicators() : leftTurnIndicator(false), rightTurnIndicator(false), lowFuelWarning(false) {}

void Indicators::setTurnIndicator(bool left, bool right) {
    leftTurnIndicator = left;
    rightTurnIndicator = right;
    emit turnIndicatorChanged();
}

void Indicators::setLowFuelWarning(bool active) {
    lowFuelWarning = active;
    emit lowFuelWarningChanged();
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