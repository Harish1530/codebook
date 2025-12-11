import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Digital Instrument Cluster Simulator"

    Component.onCompleted: {
    console.log("Inside app")
}
    // Speedometer
    Speedometer {
        id: speedometer
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 200
    }
    

    // RPM Gauge
    RPMGauge {
        id: rpmGauge
        anchors.top: speedometer.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 200
    }

    // Fuel Gauge
    FuelGauge {
        id: fuelGauge
        anchors.top: rpmGauge.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 200
    }

    // Indicators
    Indicators {
        id: indicators
        anchors.top: fuelGauge.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 100
    }
}