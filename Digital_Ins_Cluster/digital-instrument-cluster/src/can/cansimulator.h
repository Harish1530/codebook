#ifndef CANSIMULATOR_H
#define CANSIMULATOR_H

class CANSimulator {
public:
    CANSimulator();
    void sendMessage(int id, float value);
    float receiveMessage(int id);
};

#endif // CANSIMULATOR_H