#include "clustercontroller.h"
#include <QtGlobal>
#include <algorithm>

ClusterController::ClusterController(QObject *parent)
    : QObject(parent)
{
}

// ----- Speed -----
void ClusterController::setSpeed(int value) {
    if (m_speed == value) return;
    m_speed = value;
    emit speedChanged();
}

// ----- RPM -----
void ClusterController::setRpm(int value) {
    if (m_rpm == value) return;
    m_rpm = value;
    emit rpmChanged();
}

// ----- Fuel (0..1) -----
void ClusterController::setFuel(double value) {
    value = std::clamp(value, 0.0, 1.0);
    if (qFuzzyCompare(m_fuel, value)) return;
    m_fuel = value;
    emit fuelChanged();
}

// ----- Gear (-1..6) -----
void ClusterController::setGear(int value) {
    if (m_gear == value) return;
    m_gear = value;
    emit gearChanged();
}

// ----- Engine Temp -----
void ClusterController::setEngineTempC(double value) {
    if (qFuzzyCompare(m_engineTempC, value)) return;
    m_engineTempC = value;
    emit engineTempCChanged();
}

// ----- Trip -----

static inline bool fuzzyEq(double a, double b){ return qFuzzyCompare(a, b); }

void ClusterController::setTrip1Km(double v){ if (fuzzyEq(m_trip1Km, v)) return; m_trip1Km = v; emit trip1KmChanged(); }
void ClusterController::setTrip2Km(double v){ if (fuzzyEq(m_trip2Km, v)) return; m_trip2Km = v; emit trip2KmChanged(); }

void ClusterController::setTrip1Hours(double v){ if (fuzzyEq(m_trip1Hours, v)) return; m_trip1Hours = v; emit trip1HoursChanged(); }
void ClusterController::setTrip2Hours(double v){ if (fuzzyEq(m_trip2Hours, v)) return; m_trip2Hours = v; emit trip2HoursChanged(); }

void ClusterController::setTrip1AvgSpeedKph(double v){ if (fuzzyEq(m_trip1AvgSpeedKph, v)) return; m_trip1AvgSpeedKph = v; emit trip1AvgSpeedKphChanged(); }
void ClusterController::setTrip2AvgSpeedKph(double v){ if (fuzzyEq(m_trip2AvgSpeedKph, v)) return; m_trip2AvgSpeedKph = v; emit trip2AvgSpeedKphChanged(); }

void ClusterController::setTrip1EnergyKWhPerKm(double v){ if (fuzzyEq(m_trip1EnergyKWhPerKm, v)) return; m_trip1EnergyKWhPerKm = v; emit trip1EnergyKWhPerKmChanged(); }
void ClusterController::setTrip2EnergyKWhPerKm(double v){ if (fuzzyEq(m_trip2EnergyKWhPerKm, v)) return; m_trip2EnergyKWhPerKm = v; emit trip2EnergyKWhPerKmChanged(); }

void ClusterController::setActiveTrip(int v){ if (m_activeTrip == v) return; m_activeTrip = (v==2?2:1); emit activeTripChanged(); }

// Reset implementation: zero the selected trip and emit signals
void ClusterController::resetTrip(int index)
{
    if (index == 2) {
        setTrip2Km(0); setTrip2Hours(0); setTrip2AvgSpeedKph(0); setTrip2EnergyKWhPerKm(0);
    } else {
        setTrip1Km(0); setTrip1Hours(0); setTrip1AvgSpeedKph(0); setTrip1EnergyKWhPerKm(0);
    }
}


// ----- Odometer -----
void ClusterController::setOdometerKm(double value) {
    if (qFuzzyCompare(m_odometerKm, value)) return;
    m_odometerKm = value;
    emit odometerKmChanged();
}

// ----- Indicators -----
void ClusterController::setLeftIndicator(bool value) {
    if (m_leftIndicator == value) return;
    m_leftIndicator = value;
    emit indicatorsChanged();
}

void ClusterController::setRightIndicator(bool value) {
    if (m_rightIndicator == value) return;
    m_rightIndicator = value;
    emit indicatorsChanged();
}

void ClusterController::setEngineWarning(bool value) {
    if (m_engineWarning == value) return;
    m_engineWarning = value;
    emit indicatorsChanged();
}

void ClusterController::setAbsWarning(bool value) {
    if (m_absWarning == value) return;
    m_absWarning = value;
    emit indicatorsChanged();
}

void ClusterController::setServiceWarning(bool value) {
    if (m_serviceWarning == value) return;
    m_serviceWarning = value;
    emit indicatorsChanged();
}
