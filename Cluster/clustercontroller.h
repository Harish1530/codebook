#pragma once
#include <QObject>

class ClusterController : public QObject
{
    Q_OBJECT

    // Core driving data
    Q_PROPERTY(int    speed        READ speed        WRITE setSpeed        NOTIFY speedChanged)          // km/h
    Q_PROPERTY(int    rpm          READ rpm          WRITE setRpm          NOTIFY rpmChanged)            // rpm
    Q_PROPERTY(double fuel         READ fuel         WRITE setFuel         NOTIFY fuelChanged)           // 0..1
    Q_PROPERTY(int    gear         READ gear         WRITE setGear         NOTIFY gearChanged)           // -1=R,0=N,1..6

    // Temps & distances
    Q_PROPERTY(double engineTempC  READ engineTempC  WRITE setEngineTempC  NOTIFY engineTempCChanged)    // deg C
    Q_PROPERTY(double odometerKm   READ odometerKm   WRITE setOdometerKm   NOTIFY odometerKmChanged)     // km

    // Indicators / warnings
    Q_PROPERTY(bool   leftIndicator  READ leftIndicator  WRITE setLeftIndicator  NOTIFY indicatorsChanged)
    Q_PROPERTY(bool   rightIndicator READ rightIndicator WRITE setRightIndicator NOTIFY indicatorsChanged)
    Q_PROPERTY(bool   engineWarning  READ engineWarning  WRITE setEngineWarning  NOTIFY indicatorsChanged)
    Q_PROPERTY(bool   absWarning     READ absWarning     WRITE setAbsWarning     NOTIFY indicatorsChanged)
    Q_PROPERTY(bool   serviceWarning READ serviceWarning WRITE setServiceWarning NOTIFY indicatorsChanged)

    // Trip 1/2 metrics
    Q_PROPERTY(double trip1Km            READ trip1Km            WRITE setTrip1Km            NOTIFY trip1KmChanged)
    Q_PROPERTY(double trip2Km            READ trip2Km            WRITE setTrip2Km            NOTIFY trip2KmChanged)
    Q_PROPERTY(double trip1Hours         READ trip1Hours         WRITE setTrip1Hours         NOTIFY trip1HoursChanged)
    Q_PROPERTY(double trip2Hours         READ trip2Hours         WRITE setTrip2Hours         NOTIFY trip2HoursChanged)
    Q_PROPERTY(double trip1AvgSpeedKph   READ trip1AvgSpeedKph   WRITE setTrip1AvgSpeedKph   NOTIFY trip1AvgSpeedKphChanged)
    Q_PROPERTY(double trip2AvgSpeedKph   READ trip2AvgSpeedKph   WRITE setTrip2AvgSpeedKph   NOTIFY trip2AvgSpeedKphChanged)
    Q_PROPERTY(double trip1EnergyKWhPerKm READ trip1EnergyKWhPerKm WRITE setTrip1EnergyKWhPerKm NOTIFY trip1EnergyKWhPerKmChanged)
    Q_PROPERTY(double trip2EnergyKWhPerKm READ trip2EnergyKWhPerKm WRITE setTrip2EnergyKWhPerKm NOTIFY trip2EnergyKWhPerKmChanged)
    Q_PROPERTY(int    activeTrip         READ activeTrip         WRITE setActiveTrip         NOTIFY activeTripChanged)

    Q_INVOKABLE void resetTrip(int index);


public:
    explicit ClusterController(QObject *parent = nullptr);

    // Getters
    int speed() const { return m_speed; }
    int rpm() const { return m_rpm; }
    double fuel() const { return m_fuel; }
    int gear() const { return m_gear; }

    double engineTempC() const { return m_engineTempC; }
    double odometerKm() const { return m_odometerKm; }


    double trip1Km() const { return m_trip1Km; }    double trip2Km() const { return m_trip2Km; }
    double trip1Hours() const { return m_trip1Hours; } double trip2Hours() const { return m_trip2Hours; }
    double trip1AvgSpeedKph() const { return m_trip1AvgSpeedKph; } double trip2AvgSpeedKph() const { return m_trip2AvgSpeedKph; }
    double trip1EnergyKWhPerKm() const { return m_trip1EnergyKWhPerKm; } double trip2EnergyKWhPerKm() const { return m_trip2EnergyKWhPerKm; }
    int activeTrip() const { return m_activeTrip; }


    bool leftIndicator() const { return m_leftIndicator; }
    bool rightIndicator() const { return m_rightIndicator; }
    bool engineWarning() const { return m_engineWarning; }
    bool absWarning() const { return m_absWarning; }
    bool serviceWarning() const { return m_serviceWarning; }

public slots:
    // Setters (with change guards)
    void setSpeed(int value);
    void setRpm(int value);
    void setFuel(double value);          // clamps 0..1
    void setGear(int value);

    void setEngineTempC(double value);
    void setOdometerKm(double value);


    void setTrip1Km(double v);
    void setTrip2Km(double v);
    void setTrip1Hours(double v);
    void setTrip2Hours(double v);
    void setTrip1AvgSpeedKph(double v);
    void setTrip2AvgSpeedKph(double v);
    void setTrip1EnergyKWhPerKm(double v);
    void setTrip2EnergyKWhPerKm(double v);
    void setActiveTrip(int v);


    void setLeftIndicator(bool value);
    void setRightIndicator(bool value);
    void setEngineWarning(bool value);
    void setAbsWarning(bool value);
    void setServiceWarning(bool value);

signals:
    void speedChanged();
    void rpmChanged();
    void fuelChanged();
    void gearChanged();

    void engineTempCChanged();
    void odometerKmChanged();

    void trip1KmChanged();
    void trip2KmChanged();
    void trip1HoursChanged();
    void trip2HoursChanged();
    void trip1AvgSpeedKphChanged();
    void trip2AvgSpeedKphChanged();
    void trip1EnergyKWhPerKmChanged();
    void trip2EnergyKWhPerKmChanged();
    void activeTripChanged();


    void indicatorsChanged();

private:
    int    m_speed{0};
    int    m_rpm{0};
    double m_fuel{0.0};      // 0..1
    int    m_gear{0};        // -1..6

    double m_engineTempC{0.0};
    double m_odometerKm{0.0};

    double m_trip1Km{0}, m_trip2Km{0};
    double m_trip1Hours{0}, m_trip2Hours{0};
    double m_trip1AvgSpeedKph{0}, m_trip2AvgSpeedKph{0};
    double m_trip1EnergyKWhPerKm{0}, m_trip2EnergyKWhPerKm{0};
    int    m_activeTrip{1};


    bool   m_leftIndicator{false};
    bool   m_rightIndicator{false};
    bool   m_engineWarning{false};
    bool   m_absWarning{false};
    bool   m_serviceWarning{false};
};
