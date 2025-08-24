#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <QObject>
#include <QDebug>

class Speedometer: public QObject {
    Q_OBJECT
public:
    explicit Speedometer(QObject *parent = nullptr);
    void setSpeed(float speed);
    float getSpeed() const;
    void updateDisplay(); // <-- Add this

signals:
    void speedChanged(float speed); // <-- Add this if you want to notify QML/UI

private:
    float currentSpeed;
};

#endif // SPEEDOMETER_H