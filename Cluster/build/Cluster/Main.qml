// Main.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

ApplicationWindow {
    id: win
    visible: true
    width: 1400
    height: 800
    title: "Digital Instrument Cluster"

    property bool darkMode: true



    Item{
    //Dev Mode Debbuger
    Keys.onPressed: (event) => {
        if (event.key === Qt.Key_D) {
            console.log("Speed:", cluster.speed,
                        "RPM:", cluster.rpm,
                        "Fuel:", cluster.fuel,
                        "Temp:", cluster.engineTempC,
                        "Gear:", cluster.gear)
            event.accepted = true
        }
    }
    }



    // Background gradient
    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: darkMode ? "#191919" : "#e8f0ff" }
            GradientStop { position: 0.6; color: darkMode ? "#2b2b2b" : "#d9e6ff" }
            GradientStop { position: 1.0; color: darkMode ? "#0d0d0d" : "#cddcff" }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 30
        spacing: 20

        // ── INDICATORS ROW ──────────────────────────────────────────
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20

            Indicators {
                id: indicators
                leftIndicator:  cluster.leftIndicator
                rightIndicator: cluster.rightIndicator
                engineWarning:  cluster.engineWarning
                absWarning:     cluster.absWarning
                serviceWarning: cluster.serviceWarning
            }
        }

        // ── MAIN GAUGES ─────────────────────────────────────────────
        RowLayout {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            spacing: 60

            Speedometer {
                id: speedometer
                width: 360
                height: 360
                speed: cluster.speed
            }

            GearColumn {
                id: gearIndicator
                currentGear: cluster.gear
            }

            ColumnLayout {
                spacing: 15

                Trip {
                    id: tripMenu
                    width: 260
                }

                Odometer {
                    id: odometer
                    width: 260
                    totalDistance: cluster.odometerKm
                }
            }

            RPMGauge {
                id: rpmGauge
                width: 360
                height: 360
                rpm: cluster.rpm
            }
        }

        // ── FUEL + ENGINE TEMP ROW ───────────────────────────────────
        RowLayout {
            Layout.fillWidth: true
            spacing: 10

            FuelGauge {
                id: fuelGauge
                width: 300
                height: 80
                fuelLevel: cluster.fuel
            }

            Item { Layout.fillWidth: true }

            EngineTemp {
                id: engineTemp
                width: 300
                height: 70
                tempC: cluster.engineTempC
            }
        }

        // ── DARK MODE TOGGLE ─────────────────────────────────────────
        RowLayout {
            Layout.alignment: Qt.AlignRight
            spacing: 8

            Text {
                text: darkMode ? "🌙 Dark" : "☀ Light"
                color: "white"
                font.pixelSize: 13
            }

            Switch {
                checked: darkMode
                onCheckedChanged: darkMode = checked
            }
        }
    }

}
