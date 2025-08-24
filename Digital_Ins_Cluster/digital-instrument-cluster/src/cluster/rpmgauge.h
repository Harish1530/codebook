#ifndef RPMGAUGE_H
#define RPMGAUGE_H

#include <QObject>

class RPMGauge : public QObject {
    Q_OBJECT
public:
    explicit RPMGauge(QObject *parent = nullptr);
    void setRPM(float rpm);
    float getRPM() const;

signals:
    void rpmChanged(float newRPM);

private:
    float currentRPM;
};

#endif // RPMGAUGE_H
