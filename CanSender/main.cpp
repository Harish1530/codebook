#include <QCoreApplication>
#include <QTimer>
#include <QDebug>
#include <cmath>
#include <algorithm>

#include "cansender.h"

// ============================================================
//  Simulation State
// ============================================================
struct SimState
{
    double t           = 0.0;
    double speedKph    = 0.0;
    double rpm         = 800.0;
    int    gear        = 0;
    double fuel        = 1.0;
    double tempC       = 20.0;
    double odoKm       = 12345.0;
    double trip1Km     = 0.0;
    double trip1Hours  = 0.0;
    double trip2Km     = 500.0;
    double trip2Hours  = 5.3;
    bool   leftOn      = false;
    bool   rightOn     = false;
    bool   engineWarn  = false;
    bool   absWarn     = false;
    bool   serviceWarn = false;
};

// ============================================================
//  Gear helper
// ============================================================
static int estimateGear(double kph)
{
    if (kph <= 0)  return 0;
    if (kph < 20)  return 1;
    if (kph < 40)  return 2;
    if (kph < 60)  return 3;
    if (kph < 80)  return 4;
    if (kph < 100) return 5;
    return 6;
}

// ============================================================
//  Simulator class — avoids lambda capture issues on MinGW
// ============================================================
class Simulator : public QObject
{
    Q_OBJECT

public:
    explicit Simulator(CanSender* sender, QObject* parent = nullptr)
        : QObject(parent)
        , m_sender(sender)
        , m_tickCount(0)
    {}

    void start()
    {
        // Send initial static values once
        m_sender->sendActiveTrip(1);
        m_sender->sendOdometer(m_sim.odoKm);
        m_sender->sendTrip1(0.0, 0.0, 0.0, 0.0);
        m_sender->sendTrip2(m_sim.trip2Km, m_sim.trip2Hours, 80.0, 180.0);
        m_sender->sendGear(0);
        m_sender->sendIndicators(false, false, false, false, false);

        connect(&m_timer, &QTimer::timeout,
                this,     &Simulator::onTick);

        m_timer.start(50);  // 20 Hz
    }

public slots:
    void onTick()
    {
        m_sim.t += 0.05;
        m_tickCount++;

        tick_speed();
        tick_rpm();
        tick_fuel();
        tick_temp();
        tick_odometer();
        tick_trip();
        tick_gear();
        tick_indicators();
        tick_log();
    }

private:
    // ── Speed: smooth sine 0..120 km/h ───────────────────────────
    void tick_speed()
    {
        double target = 60.0 + 60.0 * std::sin(m_sim.t * 0.3);
        m_sim.speedKph += (target - m_sim.speedKph) * 0.05;
        m_sim.speedKph  = std::clamp(m_sim.speedKph, 0.0, 200.0);
        m_sender->sendSpeed(m_sim.speedKph);
    }

    // ── RPM: proportional to speed ───────────────────────────────
    void tick_rpm()
    {
        m_sim.rpm = 800.0 + m_sim.speedKph * 28.0;
        m_sim.rpm = std::clamp(m_sim.rpm, 800.0, 7500.0);
        m_sender->sendRpm(m_sim.rpm);
    }

    // ── Fuel: slowly drains ──────────────────────────────────────
    void tick_fuel()
    {
        m_sim.fuel = std::max(0.0, m_sim.fuel - 0.00005);
        m_sender->sendFuel(m_sim.fuel);
    }

    // ── Engine temp: rises 20°C → 90°C over ~60s ─────────────────
    void tick_temp()
    {
        if (m_sim.tempC < 90.0)
            m_sim.tempC = std::min(90.0, m_sim.tempC + 0.02);
        m_sender->sendTemp(m_sim.tempC);
    }

    // ── Odometer: accumulates with speed ─────────────────────────
    void tick_odometer()
    {
        m_sim.odoKm += (m_sim.speedKph / 3600.0) * 0.05;
        m_sender->sendOdometer(m_sim.odoKm);
    }

    // ── Trip 1: accumulates with speed ───────────────────────────
    void tick_trip()
    {
        m_sim.trip1Km    += (m_sim.speedKph / 3600.0) * 0.05;
        m_sim.trip1Hours += (1.0 / 3600.0) * 0.05;
        m_sender->sendTrip1(
            m_sim.trip1Km,
            m_sim.trip1Hours,
            m_sim.speedKph,
            231.4
            );
    }

    // ── Gear: estimated from speed, send only on change ──────────
    void tick_gear()
    {
        int newGear = estimateGear(m_sim.speedKph);
        if (newGear != m_sim.gear) {
            m_sim.gear = newGear;
            m_sender->sendGear(m_sim.gear);
            qInfo() << "[Gear] ->" << m_sim.gear;
        }
    }

    // ── Indicators: various demo patterns ────────────────────────
    void tick_indicators()
    {
        bool newLeft    = (static_cast<int>(m_sim.t) % 5) < 2;
        bool newRight   = (static_cast<int>(m_sim.t) % 8) < 2;
        bool newEngine  = (m_sim.tempC >= 88.0);
        bool newAbs     = (m_sim.t >= 30.0 && m_sim.t < 32.0);
        bool newService = (m_sim.fuel < 0.15);

        // Only transmit on change to avoid flooding bus
        if (newLeft    != m_sim.leftOn     ||
            newRight   != m_sim.rightOn    ||
            newEngine  != m_sim.engineWarn ||
            newAbs     != m_sim.absWarn    ||
            newService != m_sim.serviceWarn)
        {
            m_sim.leftOn      = newLeft;
            m_sim.rightOn     = newRight;
            m_sim.engineWarn  = newEngine;
            m_sim.absWarn     = newAbs;
            m_sim.serviceWarn = newService;

            m_sender->sendIndicators(
                m_sim.leftOn,
                m_sim.rightOn,
                m_sim.engineWarn,
                m_sim.absWarn,
                m_sim.serviceWarn
                );
        }
    }

    // ── Console log: every second (every 20 ticks at 20 Hz) ──────
    void tick_log()
    {
        if (m_tickCount % 20 != 0) return;

        qInfo().nospace()
            << "─────────────────────────────────────\n"
            << "  t      : " << QString::number(m_sim.t,'f',1) << " s\n"
            << "  Speed  : " << static_cast<int>(m_sim.speedKph) << " km/h\n"
            << "  RPM    : " << static_cast<int>(m_sim.rpm) << "\n"
            << "  Fuel   : " << QString::number(m_sim.fuel*100,'f',1) << " %\n"
            << "  Temp   : " << QString::number(m_sim.tempC,'f',1) << " °C\n"
            << "  Gear   : " << m_sim.gear << "\n"
            << "  Odo    : " << QString::number(m_sim.odoKm,'f',2) << " km\n"
            << "  Trip1  : " << QString::number(m_sim.trip1Km,'f',2) << " km  "
            << QString::number(m_sim.trip1Hours*60,'f',1) << " min\n"
            << "  L/R/E/ABS/SVC: "
            << m_sim.leftOn    << "/"
            << m_sim.rightOn   << "/"
            << m_sim.engineWarn<< "/"
            << m_sim.absWarn   << "/"
            << m_sim.serviceWarn;
    }

private:
    CanSender* m_sender    = nullptr;
    QTimer     m_timer;
    SimState   m_sim;
    int        m_tickCount = 0;
};

// ============================================================
//  main()
// ============================================================
int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    CanSender sender;

    // Change to match your cluster's canManager.start() call:
    //   Virtual (same PC):  "virtualcan", "Virtual"
    //   Peak PCAN-USB:      "peakcan",    "PCAN_USBBUS1"
    //   Vector:             "vectorcan",  "0"
    //   Linux SocketCAN:    "socketcan",  "can0"
    if (!sender.init("virtualcan", "Virtual")) {
        qCritical() << "[CanSender] Failed to connect. Exiting.";
        return 1;
    }

    Simulator sim(&sender);
    sim.start();

    qInfo() << "╔══════════════════════════════════════╗";
    qInfo() << "║   CanSender running at 20 Hz         ║";
    qInfo() << "║   Plugin  : virtualcan               ║";
    qInfo() << "║   Channel : Virtual                  ║";
    qInfo() << "║   Press Ctrl+C to stop               ║";
    qInfo() << "╚══════════════════════════════════════╝";

    return app.exec();
}

#include "main.moc"   // needed because Simulator is defined in main.cpp
