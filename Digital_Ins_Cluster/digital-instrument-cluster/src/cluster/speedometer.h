#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

class Speedometer {
public:
    Speedometer();
    void setSpeed(float speed);
    float getSpeed() const;

private:
    float currentSpeed;
};

#endif // SPEEDOMETER_H