#ifndef CANSENDER_H
#define CANSENDER_H

#pragma once

#include <QObject>
#include <QByteArray>
#include <QString>

class QCanBusDevice;

class CanSender : public QObject
{
    Q_OBJECT

public:
    explicit CanSender(QObject* parent = nullptr);
    ~CanSender();

    // Connect to CAN interface
    // Examples:
    //   Virtual:    init("virtualcan", "Virtual")
    //   Peak PCAN:  init("peakcan",    "PCAN_USBBUS1")
    //   Vector:     init("vectorcan",  "0")
    //   SocketCAN:  init("socketcan",  "can0")
    bool init(const QString& plugin, const QString& iface);
    void close();
    bool isConnected() const { return m_dev != nullptr; }

    // ── TX methods (match IDs in canbusmanager.cpp) ──────────────
    void sendSpeed(double kph);                    // ID 0x100
    void sendRpm(double rpm);                      // ID 0x101
    void sendFuel(double frac0to1);                // ID 0x102
    void sendTemp(double degC);                    // ID 0x103
    void sendOdometer(double km);                  // ID 0x104

    void sendTrip1(double km, double hours,
                   double avgKph, double energyKWhKm);   // ID 0x200
    void sendTrip2(double km, double hours,
                   double avgKph, double energyKWhKm);   // ID 0x201

    void sendActiveTrip(int idx);                  // ID 0x202  (1 or 2)

    // gear: -1=R, 0=N, 1..6
    void sendGear(int gear);                       // ID 0x300

    // Indicator bits: bit0=left, bit1=right, bit2=engine,
    //                 bit3=abs,  bit4=service
    void sendIndicators(bool left,    bool right,
                        bool engine,  bool abs,
                        bool service);             // ID 0x301

private:
    QCanBusDevice* m_dev = nullptr;

    // Write a frame to the bus
    void write(quint32 id, const QByteArray& payload);

    // Payload builders
    static QByteArray u8frame (quint8  v);
    static QByteArray le16frame(quint16 v);
    static QByteArray le32frame(quint32 v);
    static QByteArray buildTripPayload(double km,     double hours,
                                       double avgKph, double energyKWhKm);
};

#endif // CANSENDER_H
