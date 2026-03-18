#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "clustercontroller.h"
#include "canbusmanager.h"          // ← ADD 1: include CAN manager

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        [](){ QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // ── Cluster backend
    ClusterController controller;
    engine.rootContext()->setContextProperty("cluster", &controller);

    // ← ADD 2: Create CAN manager (pass controller so it can update it)
    CanBusManager canManager(&controller);

    // ← ADD 3: Expose CAN manager to QML as "can"
    engine.rootContext()->setContextProperty("can", &canManager);

    // ← ADD 4: Auto-start CAN (virtualcan for Option C sender app)
    //   Switch this line when moving to real hardware:
    //   Peak PCAN-USB → canManager.start("peakcan",   "PCAN_USBBUS1");
    //   Vector        → canManager.start("vectorcan", "0");
    //   Linux SocketCAN → canManager.start("socketcan", "can0");
    if (canManager.start("virtualcan", "Virtual"))
        qInfo() << "[CAN] Started on virtualcan/Virtual";
    else
        qWarning() << "[CAN] Failed to start — cluster will run without CAN";

    // ── Load QML
    engine.loadFromModule("Cluster", "Main");

    // ── Safety check
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
