import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
ApplicationWindow {
visible: true
width: 1400
height: 800
title: "Digital Instrument Cluster Simulator"

Item {
    id: root
    anchors.fill: parent
    focus: true

Keys.onPressed: {
    if(event.key === Qt.Key_D){
        testPanel.visible = !testPanel.visible
        event.accepted = true
    }
}

property bool darkMode: true

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
    spacing: 30

    //---------------------------------
    // INDICATORS ROW
    //---------------------------------
    RowLayout {
        Layout.alignment: Qt.AlignHCenter
        spacing: 20

        Indicators {
            id: indicators
        }
    }

    //---------------------------------
    // MAIN INSTRUMENTS
    //---------------------------------
    RowLayout {
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignHCenter
        spacing: 60

        // SPEEDOMETER
        Speedometer {
            id: speedometer
            width: 360
            height: 360
        }

        // GEAR INDICATOR
        GearColumn {
            id: gearIndicator
            currentGear: 1
        }

        // TRIP + ODOMETER
        ColumnLayout {
            spacing: 15

            Trip {
                id: tripMenu
                width: 260
            }

            Odometer {
                id: odometer
                width: 260
            }
        }

        // RPM
        RPMGauge {
            id: rpmGauge
            width: 360
            height: 360
        }
    }


    RowLayout {
        Layout.fillWidth: true
        spacing: 10

        // Fuel gauge left side
        FuelGauge {
            id: fuelGauge
            width: 300
            height: 70
        }

        Item { Layout.fillWidth: true }

        // Engine temperature
        Rectangle {
            width: 300
            height: 70
            radius: 7
            color: "#101010"

            Row {
                anchors.centerIn: parent
                spacing: 10

                Text {
                    text: "ENGINE TEMP"
                    color: "white"
                }

                ProgressBar {
                    id: tempBar
                    width: 160
                    value: 0.35
                }

                Text {
                    text: Math.round(tempBar.value * 120) + "°C"
                    color: "white"
                }
            }
        }
    }

    RowLayout {
        Layout.alignment: Qt.AlignRight

        Text {
            text: darkMode ? "Dark" : "Light"
            color: "white"
        }

        Switch {
            checked: darkMode
            onCheckedChanged: darkMode = checked
        }
    }
}

Rectangle {

    id: testPanel
    width: parent.width
    height: 200
    color: "#222222"

    anchors.bottom: parent.bottom

    Column {

        anchors.centerIn: parent
        spacing: 10


        Row {
            spacing: 10

            Text { text: "Speed"; color: "white" }

            Slider {
                id: speedSlider
                from: 0
                to: 200
                width: 300

                onValueChanged: {
                    speedometer.updateSpeed(value)
                }
            }

            Text {
                text: Math.round(speedSlider.value) + " km/h"
                color: "white"
            }
        }

        //---------------------------------
        // RPM CONTROL
        //---------------------------------

        Row {
            spacing: 10

            Text { text: "RPM"; color: "white" }

            Slider {
                id: rpmSlider
                from: 0
                to: 8000
                width: 300

                onValueChanged: {
                    rpmGauge.setRpm(value)
                }
            }

            Text {
                text: Math.round(rpmSlider.value)
                color: "white"
            }
        }

        //---------------------------------
        // FUEL LEVEL
        //---------------------------------

        Row {
            spacing: 10

            Text { text: "Fuel"; color: "white" }

            Slider {
                from: 0
                to: 1
                width: 300

                onValueChanged: {
                    fuelGauge.targetFuel = value
                }
            }
        }

        //---------------------------------
        // GEAR SELECT
        //---------------------------------

        Row {
            spacing: 10

            Text { text: "Gear"; color: "white" }

            ComboBox {
                model: ["R","N","1","2","3","4","5","6"]

                onCurrentIndexChanged: {
                    gearIndicator.currentGear = currentIndex - 1
                }
            }
        }

        //---------------------------------
        // INDICATORS
        //---------------------------------

        Row {
            spacing: 20

            CheckBox {
                text: "Left Indicator"
                onCheckedChanged: indicators.leftIndicator = checked
            }

            CheckBox {
                text: "Right Indicator"
                onCheckedChanged: indicators.rightIndicator = checked
            }

            CheckBox {
                text: "Engine Warning"
                onCheckedChanged: indicators.engineWarning = checked
            }

            CheckBox {
                text: "ABS"
                onCheckedChanged: indicators.absWarning = checked
            }
        }

    }
}
}
}
