#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "cansimulator.h"
#include "cluster/speedometer.h"
#include "cluster/rpmgauge.h"
#include "cluster/fuelgauge.h"
#include "cluster/indicators.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Register C++ classes with QML
    qmlRegisterType<Speedometer>("com.digitalinstrumentcluster", 1, 0, "Speedometer");
    qmlRegisterType<RPMGauge>("com.digitalinstrumentcluster", 1, 0, "RPMGauge");
    qmlRegisterType<FuelGauge>("com.digitalinstrumentcluster", 1, 0, "FuelGauge");
    qmlRegisterType<Indicators>("com.digitalinstrumentcluster", 1, 0, "Indicators");
    qmlRegisterType<CANSimulator>("com.digitalinstrumentcluster", 1, 0, "CANSimulator");

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}