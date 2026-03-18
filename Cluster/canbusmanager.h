#pragma once
#include <QObject>
#include <QByteArray>

class QCanBusDevice;
class QCanBusFrame;
class ClusterController;

class CanBusManager : public QObject
{
    Q_OBJECT
public:
    explicit CanBusManager(ClusterController* cluster, QObject* parent=nullptr);
    ~CanBusManager();

    // Start/stop a CAN interface (examples: "socketcan","vcan0" | "peakcan","PCAN_USBBUS1" | "vectorcan","0")
    Q_INVOKABLE bool start(const QString& plugin, const QString& interfaceName, int bitrate = -1);
    Q_INVOKABLE void stop();
    Q_INVOKABLE bool isRunning() const { return m_dev != nullptr; }

    // -------------------- TX helper API (optional simulator) --------------------
    Q_INVOKABLE void sendSpeedKph(double kph);
    Q_INVOKABLE void sendRpm(double rpm);
    Q_INVOKABLE void sendFuelFraction(double frac0to1);
    Q_INVOKABLE void sendTempC(double tempC);
    Q_INVOKABLE void sendOdometerKm(double km);
    Q_INVOKABLE void sendTrip1(double km, double hours, double avgKph, double energyKWhPerKm);
    Q_INVOKABLE void sendTrip2(double km, double hours, double avgKph, double energyKWhPerKm);
    Q_INVOKABLE void setActiveTrip(int index); // 1 or 2

signals:
    void started(bool ok, const QString& error);
    void stopped();
    void errorText(const QString& text);

private slots:
    void onFramesReceived();

private:
    void parseFrame(const QCanBusFrame& f);

    // small helpers
    static quint16 u16le(const QByteArray& p, int off);
    static quint32 u32le(const QByteArray& p, int off);

private:
    QCanBusDevice* m_dev = nullptr;
    ClusterController* m_cluster = nullptr;
};
