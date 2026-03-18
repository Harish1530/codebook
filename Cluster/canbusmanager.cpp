#include "canbusmanager.h"
#include "clustercontroller.h"

#include <QtSerialBus/QCanBus>
#include <QtSerialBus/QCanBusDevice>
#include <QtSerialBus/QCanBusFrame>
#include <QVariant>
#include <QDebug>
#include <algorithm>

// -------------------- IDs (adjust to your DBC) --------------------
static constexpr quint32 ID_SPEED   = 0x100;
static constexpr quint32 ID_RPM     = 0x101;
static constexpr quint32 ID_FUEL    = 0x102;
static constexpr quint32 ID_TEMP    = 0x103;
static constexpr quint32 ID_ODO     = 0x104;

static constexpr quint32 ID_TRIPKM1 = 0x105;
static constexpr quint32 ID_TRIPKM2 = 0x106;

static constexpr quint32 ID_TRIP1   = 0x200; // [0..3] km*0.1, [4..5] hours*0.01, [6] avgKph, [7] energy*0.1
static constexpr quint32 ID_TRIP2   = 0x201; // same
static constexpr quint32 ID_ACTIVE  = 0x202; // [0] = 1 or 2
static constexpr quint32 ID_GEAR = 0x300;
static constexpr quint32 ID_IND  = 0x301;
// ------------------------------------------------------------------

CanBusManager::CanBusManager(ClusterController* cluster, QObject* parent)
    : QObject(parent), m_cluster(cluster)
{}

CanBusManager::~CanBusManager()
{
    stop();
}

bool CanBusManager::start(const QString& plugin, const QString& interfaceName, int bitrate)
{
    stop();

    QString err;
    QCanBusDevice* dev = QCanBus::instance()->createDevice(plugin, interfaceName, &err);
    if (!dev) {
        emit started(false, QStringLiteral("createDevice failed: %1").arg(err));
        return false;
    }

    if (bitrate > 0)
        dev->setConfigurationParameter(QCanBusDevice::BitRateKey, bitrate);

    connect(dev, &QCanBusDevice::framesReceived,
            this, &CanBusManager::onFramesReceived);

    // ✅ Correct lambda signature and capture; no stray tokens
    connect(dev, &QCanBusDevice::errorOccurred,
            this, [this](QCanBusDevice::CanBusError) {
                emit errorText(m_dev ? m_dev->errorString()
                                     : QStringLiteral("CAN error"));
            });

    if (!dev->connectDevice()) {
        const QString e = dev->errorString();
        dev->deleteLater();
        emit started(false, QStringLiteral("connectDevice failed: %1").arg(e));
        return false;
    }

    m_dev = dev;
    emit started(true, QString());
    return true;
}

void CanBusManager::stop()
{
    if (!m_dev) { emit stopped(); return; }
    m_dev->disconnectDevice();
    m_dev->deleteLater();
    m_dev = nullptr;
    emit stopped();
}

void CanBusManager::onFramesReceived()
{
    if (!m_dev) return;
    while (m_dev->framesAvailable() > 0) {
        const QCanBusFrame f = m_dev->readFrame();
        parseFrame(f);
    }
}

static quint16 u16le_raw(const QByteArray& p, int off)
{
    const quint8 b0 = static_cast<quint8>(p.at(off + 0));
    const quint8 b1 = static_cast<quint8>(p.at(off + 1));
    return static_cast<quint16>(b0 | (b1 << 8));
}
static quint32 u32le_raw(const QByteArray& p, int off)
{
    const quint8 b0 = static_cast<quint8>(p.at(off + 0));
    const quint8 b1 = static_cast<quint8>(p.at(off + 1));
    const quint8 b2 = static_cast<quint8>(p.at(off + 2));
    const quint8 b3 = static_cast<quint8>(p.at(off + 3));
    return static_cast<quint32>(b0 | (b1 << 8) | (b2 << 16) | (b3 << 24));
}

void CanBusManager::parseFrame(const QCanBusFrame& f)
{
    if (!m_cluster) return;

    const quint32 id = f.frameId();
    const QByteArray p = f.payload();

    if (id == ID_SPEED && p.size() >= 2) {
        const double kph = u16le_raw(p, 0) * 0.01; // 0.01 kph/bit
        m_cluster->setSpeed(static_cast<int>(std::round(kph)));
        return;
    }

    if (id == ID_RPM && p.size() >= 2) {
        const double rpm = u16le_raw(p, 0) * 1.0;
        m_cluster->setRpm(static_cast<int>(std::round(rpm)));
        return;
    }

    if (id == ID_FUEL && p.size() >= 1) {
        const double frac = std::clamp(static_cast<unsigned char>(p.at(0)) / 255.0, 0.0, 1.0);
        m_cluster->setFuel(frac);
        return;
    }

    if (id == ID_TEMP && p.size() >= 1) {
        const double t = static_cast<unsigned char>(p.at(0)) - 40.0;
        m_cluster->setEngineTempC(t);
        return;
    }

    if (id == ID_ODO && p.size() >= 4) {
        const double km = u32le_raw(p, 0) * 0.1;
        m_cluster->setOdometerKm(km);
        return;
    }

    // ---------- Trips: use QObject::setProperty to avoid reflection pitfalls ----------
    if (id == ID_TRIPKM1 && p.size() >= 4) {
        const double km = u32le_raw(p, 0) * 0.1;
        m_cluster->setProperty("trip1Km", km);   // no-op if property not present
        return;
    }
    if (id == ID_TRIPKM2 && p.size() >= 4) {
        const double km = u32le_raw(p, 0) * 0.1;
        m_cluster->setProperty("trip2Km", km);
        return;
    }
    if (id == ID_TRIP1 && p.size() >= 8) {
        const double km     = u32le_raw(p, 0) * 0.1;
        const double hours  = u16le_raw(p, 4) * 0.01;
        const double avgKph = static_cast<unsigned char>(p.at(6));
        const double energy = static_cast<unsigned char>(p.at(7)) * 0.1;
        m_cluster->setProperty("trip1Km", km);
        m_cluster->setProperty("trip1Hours", hours);
        m_cluster->setProperty("trip1AvgSpeedKph", avgKph);
        m_cluster->setProperty("trip1EnergyKWhPerKm", energy);
        return;
    }
    if (id == ID_TRIP2 && p.size() >= 8) {
        const double km     = u32le_raw(p, 0) * 0.1;
        const double hours  = u16le_raw(p, 4) * 0.01;
        const double avgKph = static_cast<unsigned char>(p.at(6));
        const double energy = static_cast<unsigned char>(p.at(7)) * 0.1;
        m_cluster->setProperty("trip2Km", km);
        m_cluster->setProperty("trip2Hours", hours);
        m_cluster->setProperty("trip2AvgSpeedKph", avgKph);
        m_cluster->setProperty("trip2EnergyKWhPerKm", energy);
        return;
    }
    if (id == ID_ACTIVE && p.size() >= 1) {
        const int at = (p.at(0) == 2) ? 2 : 1;
        m_cluster->setProperty("activeTrip", at);
        return;
    }

    if (id == ID_GEAR && p.size() >= 1) {
        int gear = static_cast<int>(static_cast<quint8>(p.at(0))) - 1; // undo +1 offset
        m_cluster->setGear(std::clamp(gear, -1, 6));
        return;
    }

    if (id == ID_IND && p.size() >= 1) {
        const quint8 b = static_cast<quint8>(p.at(0));
        m_cluster->setLeftIndicator(  b & 0x01 );
        m_cluster->setRightIndicator( b & 0x02 );
        m_cluster->setEngineWarning(  b & 0x04 );
        m_cluster->setAbsWarning(     b & 0x08 );
        m_cluster->setServiceWarning( b & 0x10 );
        return;
    }

}

// -------------------- TX helpers --------------------
static inline QByteArray le16(quint16 v) {
    QByteArray a; a.resize(2);
    a[0] = static_cast<char>(v & 0xFF);
    a[1] = static_cast<char>((v >> 8) & 0xFF);
    return a;
}
static inline QByteArray le32(quint32 v) {
    QByteArray a; a.resize(4);
    a[0] = static_cast<char>(v & 0xFF);
    a[1] = static_cast<char>((v >> 8) & 0xFF);
    a[2] = static_cast<char>((v >> 16) & 0xFF);
    a[3] = static_cast<char>((v >> 24) & 0xFF);
    return a;
}

void CanBusManager::sendSpeedKph(double kph)
{
    if (!m_dev) return;
    quint16 raw = static_cast<quint16>(std::clamp(kph, 0.0, 655.35) * 100.0);
    m_dev->writeFrame(QCanBusFrame(ID_SPEED, le16(raw)));
}

void CanBusManager::sendRpm(double rpm)
{
    if (!m_dev) return;
    quint16 raw = static_cast<quint16>(std::clamp(rpm, 0.0, 65535.0));
    m_dev->writeFrame(QCanBusFrame(ID_RPM, le16(raw)));
}

void CanBusManager::sendFuelFraction(double frac0to1)
{
    if (!m_dev) return;
    quint8 raw = static_cast<quint8>(std::clamp(frac0to1, 0.0, 1.0) * 255.0 + 0.5);
    m_dev->writeFrame(QCanBusFrame(ID_FUEL, QByteArray(1, static_cast<char>(raw))));
}

void CanBusManager::sendTempC(double tempC)
{
    if (!m_dev) return;
    int raw = static_cast<int>(std::round(tempC + 40.0));
    raw = std::clamp(raw, 0, 255);
    m_dev->writeFrame(QCanBusFrame(ID_TEMP, QByteArray(1, static_cast<char>(raw))));
}

void CanBusManager::sendOdometerKm(double km)
{
    if (!m_dev) return;
    quint32 raw = static_cast<quint32>(std::clamp(km, 0.0, 429496729.5) * 10.0);
    m_dev->writeFrame(QCanBusFrame(ID_ODO, le32(raw)));
}

void CanBusManager::sendTrip1(double km, double hours, double avgKph, double energyKWhPerKm)
{
    if (!m_dev) return;
    QByteArray pl(8, 0);
    quint32 kmRaw = static_cast<quint32>(std::clamp(km, 0.0, 429496729.5) * 10.0);
    quint16 hrRaw = static_cast<quint16>(std::clamp(hours, 0.0, 655.35) * 100.0);
    pl.replace(0, 4, le32(kmRaw));
    pl.replace(4, 2, le16(hrRaw));
    pl[6] = static_cast<char>(std::clamp(avgKph, 0.0, 255.0));
    pl[7] = static_cast<char>(std::clamp(energyKWhPerKm * 10.0, 0.0, 255.0));
    m_dev->writeFrame(QCanBusFrame(ID_TRIP1, pl));
}

void CanBusManager::sendTrip2(double km, double hours, double avgKph, double energyKWhPerKm)
{
    if (!m_dev) return;
    QByteArray pl(8, 0);
    quint32 kmRaw = static_cast<quint32>(std::clamp(km, 0.0, 429496729.5) * 10.0);
    quint16 hrRaw = static_cast<quint16>(std::clamp(hours, 0.0, 655.35) * 100.0);
    pl.replace(0, 4, le32(kmRaw));
    pl.replace(4, 2, le16(hrRaw));
    pl[6] = static_cast<char>(std::clamp(avgKph, 0.0, 255.0));
    pl[7] = static_cast<char>(std::clamp(energyKWhPerKm * 10.0, 0.0, 255.0));
    m_dev->writeFrame(QCanBusFrame(ID_TRIP2, pl));
}

void CanBusManager::setActiveTrip(int index)
{
    if (!m_dev) return;
    QByteArray pl(1, 0);
    pl[0] = static_cast<char>(index == 2 ? 2 : 1);
    m_dev->writeFrame(QCanBusFrame(ID_ACTIVE, pl));
}
