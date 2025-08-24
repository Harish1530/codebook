#ifndef CANSIMULATOR_H
#define CANSIMULATOR_H

#include <QObject>

class CANSimulator : public QObject {
    Q_OBJECT
public:
    explicit CANSimulator(QObject *parent = nullptr);
    Q_INVOKABLE void sendMessage(int id, float value);
    Q_INVOKABLE float receiveMessage(int id);
};

#endif // CANSIMULATOR_H