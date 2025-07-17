#include "cansimulator.h"
#include <QDebug>

CANSimulator::CANSimulator(QObject *parent) : QObject(parent) {
    // Initialization code if needed
}

void CANSimulator::sendMessage(int id, float value) {
    // Simulate sending a CAN message
    qDebug() << "Sending CAN message with ID:" << id << "and value:" << value;
    // Here you would add the actual CAN message sending logic
}

float CANSimulator::receiveMessage() {
    // Simulate receiving a CAN message
    float simulatedValue = 0.0; // Replace with actual logic to get a value
    qDebug() << "Receiving CAN message with value:" << simulatedValue;
    return simulatedValue;
}