#include "cansender.h"

#include <QtSerialBus/QCanBus>
#include <QtSerialBus/QCanBusDevice>
#include <QtSerialBus/QCanBusFrame>
#include <QDebug>
#include <algorithm>
#include <cmath>

// ── CAN IDs (must match canbusmanager.cpp) ───────────────────────
static constexpr quint32 ID_SPEED  = 0x100;
static constexpr quint32 ID_RPM    = 0x101;
static constexpr quint32 ID_FUEL   = 0x102;
static constexpr quint32 ID_TEMP   = 0x103;
static constexpr quint32 ID_ODO    = 0x104;
static constexpr quint32 ID_TRIP1  = 0x200;
static constexpr quint32 ID_TRIP2  = 0x201;
static constexpr quint32 ID_ACTIVE = 0x202;
static constexpr quint32 ID_GEAR   = 0x300;
static constexpr quint32 ID_IND    = 0x301;

CanSender::CanSender(QObject* parent)
    : QObject(parent) {}

CanSender::~CanSender()
{
    close();
}

bool CanSender::init(const QString& plugin, const QString& iface)
{
    close();

    QString err;
    m_dev = QCanBus::instance()->createDevice(plugin, iface, &err);
    if (!m_dev) {
        qCritical() << "[CanSender] createDevice failed:" << err;
        return false;
    }
    if (!m_dev->connectDevice()) {
        qCritical() << "[CanSender] connectDevice failed:" << m_dev->errorString();
        m_dev->deleteLater();
        m_dev = nullptr;
        return false;
    }
    qInfo() << "[CanSender] Connected on" << plugin << "/" << iface;
    return true;
}

void CanSender::close()
{
    if (!m_dev) return;
    m_dev->disconnectDevice();
    m_dev->deleteLater();
    m_dev = nullptr;
}

// ── TX methods ──────────────────────────────────────────────────

void CanSender::sendSpeed(double kph)
{
    // 0.01 kph/bit → raw = kph * 100
    quint16 raw = static_cast<quint16>(
        std::clamp(kph, 0.0, 655.35) * 100.0);
    write(ID_SPEED, le16frame(raw));
}

void CanSender::sendRpm(double rpm)
{
    // 1 rpm/bit
    quint16 raw = static_cast<quint16>(
        std::clamp(rpm, 0.0, 65535.0));
    write(ID_RPM, le16frame(raw));
}

void CanSender::sendFuel(double frac0to1)
{
    // 0..1 → 0..255
    quint8 raw = static_cast<quint8>(
        std::clamp(frac0to1, 0.0, 1.0) * 255.0 + 0.5);
    write(ID_FUEL, u8frame(raw));
}

void CanSender::sendTemp(double degC)
{
    // raw = degC + 40  (range: -40°C → 215°C in 0..255)
    int raw = static_cast<int>(std::round(degC + 40.0));
    raw = std::clamp(raw, 0, 255);
    write(ID_TEMP, u8frame(static_cast<quint8>(raw)));
}

void CanSender::sendOdometer(double km)
{
    // 0.1 km/bit
    quint32 raw = static_cast<quint32>(
        std::clamp(km, 0.0, 429496729.5) * 10.0);
    write(ID_ODO, le32frame(raw));
}

void CanSender::sendTrip1(double km, double hours,
                          double avgKph, double energyKWhKm)
{
    write(ID_TRIP1, buildTripPayload(km, hours, avgKph, energyKWhKm));
}

void CanSender::sendTrip2(double km, double hours,
                          double avgKph, double energyKWhKm)
{
    write(ID_TRIP2, buildTripPayload(km, hours, avgKph, energyKWhKm));
}

void CanSender::sendActiveTrip(int idx)
{
    write(ID_ACTIVE, u8frame(idx == 2 ? 2 : 1));
}

void CanSender::sendGear(int gear)
{
    // +1 offset: R(-1)→0, N(0)→1, 1→2 … 6→7
    quint8 raw = static_cast<quint8>(
        std::clamp(gear + 1, 0, 7));
    write(ID_GEAR, u8frame(raw));
}

void CanSender::sendIndicators(bool left,   bool right,
                               bool engine, bool abs,
                               bool service)
{
    quint8 b = 0;
    if (left)    b |= 0x01;
    if (right)   b |= 0x02;
    if (engine)  b |= 0x04;
    if (abs)     b |= 0x08;
    if (service) b |= 0x10;
    write(ID_IND, u8frame(b));
}

// ── Private helpers ──────────────────────────────────────────────

void CanSender::write(quint32 id, const QByteArray& payload)
{
    if (!m_dev) return;
    m_dev->writeFrame(QCanBusFrame(id, payload));
}

QByteArray CanSender::u8frame(quint8 v)
{
    return QByteArray(1, static_cast<char>(v));
}

QByteArray CanSender::le16frame(quint16 v)
{
    QByteArray a(2, 0);
    a[0] = static_cast<char>(v & 0xFF);
    a[1] = static_cast<char>((v >> 8) & 0xFF);
    return a;
}

QByteArray CanSender::le32frame(quint32 v)
{
    QByteArray a(4, 0);
    a[0] = static_cast<char>(v & 0xFF);
    a[1] = static_cast<char>((v >> 8)  & 0xFF);
    a[2] = static_cast<char>((v >> 16) & 0xFF);
    a[3] = static_cast<char>((v >> 24) & 0xFF);
    return a;
}

QByteArray CanSender::buildTripPayload(double km,     double hours,
                                       double avgKph, double energyKWhKm)
{
    QByteArray pl(8, 0);

    quint32 kmRaw = static_cast<quint32>(
        std::clamp(km, 0.0, 429496729.5) * 10.0);
    quint16 hrRaw = static_cast<quint16>(
        std::clamp(hours, 0.0, 655.35) * 100.0);

    // bytes 0..3 → km
    pl[0] = static_cast<char>(kmRaw & 0xFF);
    pl[1] = static_cast<char>((kmRaw >> 8)  & 0xFF);
    pl[2] = static_cast<char>((kmRaw >> 16) & 0xFF);
    pl[3] = static_cast<char>((kmRaw >> 24) & 0xFF);
    // bytes 4..5 → hours
    pl[4] = static_cast<char>(hrRaw & 0xFF);
    pl[5] = static_cast<char>((hrRaw >> 8)  & 0xFF);
    // byte 6 → avg speed (0..255 kph)
    pl[6] = static_cast<char>(static_cast<quint8>(
        std::clamp(avgKph, 0.0, 255.0)));
    // byte 7 → energy × 0.1 kWh/km
    pl[7] = static_cast<char>(static_cast<quint8>(
        std::clamp(energyKWhKm * 10.0, 0.0, 255.0)));

    return pl;
}
