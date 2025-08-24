#ifndef FUELGAUGE_H
#define FUELGAUGE_H

#include <QObject>

class FuelGauge : public QObject {
    Q_OBJECT
public:
    explicit FuelGauge(QObject *parent = nullptr);
    void setFuelLevel(float level);
    float getFuelLevel() const;

signals:
    void fuelLevelChanged(float level);

private:
    float fuelLevel;
};

#endif // FUELGAUGE_H