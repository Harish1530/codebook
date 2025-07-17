#ifndef FUELGAUGE_H
#define FUELGAUGE_H

class FuelGauge {
public:
    FuelGauge();
    void setFuelLevel(float level);
    float getFuelLevel() const;

private:
    float fuelLevel;
};

#endif // FUELGAUGE_H