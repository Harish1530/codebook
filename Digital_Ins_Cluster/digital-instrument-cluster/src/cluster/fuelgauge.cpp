#include "fuelgauge.h"

FuelGauge::FuelGauge(QObject *parent) : QObject(parent), fuelLevel(0.0f) {}

void FuelGauge::setFuelLevel(float level) {
    if (level < 0.0f) {
        fuelLevel = 0.0f;
    } else if (level > 100.0f) {
        fuelLevel = 100.0f;
    } else {
        fuelLevel = level;
    }
    emit fuelLevelChanged(fuelLevel);
}

float FuelGauge::getFuelLevel() const {
    return fuelLevel;
}