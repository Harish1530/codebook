#ifndef INDICATORS_H
#define INDICATORS_H

class Indicators {
public:
    Indicators();

    void setTurnIndicator(bool left, bool right);
    void setLowFuelWarning(bool active);
    void setEmergencyWarningLights(bool active);

private:
    bool leftTurnIndicator;
    bool rightTurnIndicator;
    bool lowFuelWarning;
    bool emergencyWarningLights;
};

#endif // INDICATORS_H