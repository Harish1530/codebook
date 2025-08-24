#ifndef INDICATORS_H
#define INDICATORS_H

#include <QObject>

class Indicators : public QObject {
    Q_OBJECT
public:
    explicit Indicators(QObject *parent = nullptr);

    void setTurnIndicator(bool left, bool right);
    void setLowFuelWarning(bool active);
    void setEmergencyWarningLights(bool active);
    bool isLeftTurnIndicatorActive() const;
    bool isRightTurnIndicatorActive() const;
    bool isLowFuelWarningActive() const;
    bool isEmergencyWarningLightsActive() const;

signals:
    void turnIndicatorChanged(bool left, bool right);
    void lowFuelWarningChanged(bool active);
    void emergencyWarningLightsChanged(bool active);

private:
    bool leftTurnIndicator;
    bool rightTurnIndicator;
    bool lowFuelWarning;
    bool emergencyWarningLights;
};

#endif // INDICATORS_H