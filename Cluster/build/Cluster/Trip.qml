// Trip.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: tripMenu
    width: 260
    height: 150
    radius: 10
    color: "#101010"
    border.color: "#404040"

    // Local fallbacks so the screen renders even before backend properties exist
    property real trip1KmDefault: 50.0
    property real trip2KmDefault: 0.0
    property real trip1HoursDefault: 23.12       // hours (e.g., 23.12 h)
    property real trip2HoursDefault: 0.0
    property real trip1AvgKphDefault: 144.0
    property real trip2AvgKphDefault: 1.0
    property real trip1EnergyDefault: 231.4      // kWh/KM example to match screenshot
    property real trip2EnergyDefault: 231.4

    // Active trip selection
    property int activeTrip: (typeof cluster !== "undefined" && cluster.activeTrip !== undefined)
                             ? cluster.activeTrip : 1

    // ---- Helpers to read from backend or fallback ----
    function n(v, fallback) { return (typeof v === "number" && !isNaN(v)) ? v : fallback }
    function hmm(hours) {
        var h = Math.floor(Math.max(0, hours))
        var m = Math.floor((Math.max(0, hours) - h) * 60)
        function pad(x){ return (x < 10 ? "0" : "") + x }
        return pad(h) + ":" + pad(m) + " h"
    }

    // Current trip values (resolve from backend each frame)
    readonly property real curKm: activeTrip === 1
                                  ? n((cluster && cluster.trip1Km), trip1KmDefault)
                                  : n((cluster && cluster.trip2Km), trip2KmDefault)
    readonly property real curHours: activeTrip === 1
                                  ? n((cluster && cluster.trip1Hours), trip1HoursDefault)
                                  : n((cluster && cluster.trip2Hours), trip2HoursDefault)
    readonly property real curAvgKph: activeTrip === 1
                                  ? n((cluster && cluster.trip1AvgSpeedKph), trip1AvgKphDefault)
                                  : n((cluster && cluster.trip2AvgSpeedKph), trip2AvgKphDefault)
    readonly property real curEnergy: activeTrip === 1
                                  ? n((cluster && cluster.trip1EnergyKWhPerKm), trip1EnergyDefault)
                                  : n((cluster && cluster.trip2EnergyKWhPerKm), trip2EnergyDefault)

    Column {
        anchors.fill: parent
        anchors.margins: 12
        spacing: 8

        // Title
        Text {
            text: activeTrip === 1 ? "TRIP 1" : "TRIP 2"
            color: "white"
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // Two-column body
        Row {
            spacing: 14
            anchors.horizontalCenter: parent.horizontalCenter

            // Left column: DRIVING
            Column {
                spacing: 2
                Text { text: "DRIVING"; color: "#8fa6ff"; font.pixelSize: 12 }
                Text { text: curKm.toFixed(1) + " km"; color: "white"; font.pixelSize: 22; font.bold: true }
                Text { text: hmm(curHours); color: "white"; font.pixelSize: 14 }
            }

            // Divider
            Rectangle { width: 1; height: 50; color: "#303030"; anchors.verticalCenter: parent.verticalCenter }

            // Right column: AVERAGE
            Column {
                spacing: 2
                Text { text: "AVERAGE"; color: "#8fa6ff"; font.pixelSize: 12 }
                Text { text: curEnergy.toFixed(1) + " kWh/KM"; color: "white"; font.pixelSize: 18; font.bold: true }
                Text { text: Math.round(curAvgKph) + " KPH"; color: "white"; font.pixelSize: 14 }
            }
        }

        // Bottom area: reset + trip toggles
        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            // Hold-to-reset area
            Rectangle {
                id: resetArea
                radius: 4
                width: 150
                height: 20
                color: "#0c0c0c"
                border.color: holdTimer.running ? "#00c8ff" : "#3a3a3a"
                border.width: 1

                Text {
                    anchors.centerIn: parent
                    text: "HOLD OK TO RESET"
                    color: holdTimer.running ? "#00c8ff" : "#8f8f8f"
                    font.pixelSize: 11
                }

                Timer {
                    id: holdTimer
                    interval: 1200
                    repeat: false
                    onTriggered: {
                        if (cluster && cluster.resetTrip) {
                            cluster.resetTrip(activeTrip)
                        }
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onPressed: holdTimer.start()
                    onReleased: holdTimer.stop()
                    onCanceled: holdTimer.stop()
                }
            }

            // Trip selection buttons
            Row {
                spacing: 6

                Button {
                    text: "Trip 1"
                    checkable: true
                    checked: activeTrip === 1
                    onClicked: {
                        activeTrip = 1
                        if (cluster && cluster.setActiveTrip) cluster.setActiveTrip(1)
                    }
                }
                Button {
                    text: "Trip 2"
                    checkable: true
                    checked: activeTrip === 2
                    onClicked: {
                        activeTrip = 2
                        if (cluster && cluster.setActiveTrip) cluster.setActiveTrip(2)
                    }
                }
            }
        }
    }
}
