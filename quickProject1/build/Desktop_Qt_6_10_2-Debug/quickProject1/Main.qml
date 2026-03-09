import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Cluster 1.0

ApplicationWindow {

    visible: true
    width: 1600
    height: 900
    title: "Digital Instrument Cluster Simulator"

    property bool showTripMenu: false
    property bool darkMode: true

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0; color: darkMode ? "#101820" : "#e8f0ff" }
            GradientStop { position: 1; color: darkMode ? "#040b14" : "#cfdfff" }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 30
        spacing: 25

        //--------------------------------------------------
        // TOP INDICATORS
        //--------------------------------------------------

        RowLayout {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            spacing: 40

            Indicators {
                id: indicators
            }

            Item { Layout.fillWidth: true }

            Text {
                text: "23°C"
                color: "white"
                font.pixelSize: 18
            }

            Text {
                text: "P"
                color: "#00ff88"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                text: "14:19"
                color: "white"
                font.pixelSize: 18
            }
        }

        //--------------------------------------------------
        // MAIN CLUSTER
        //--------------------------------------------------

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.alignment: Qt.AlignHCenter
            spacing: 60

            //----------------------------------
            // LEFT GAUGE (RPM)
            //----------------------------------

            RPMGauge {
                id: rpmGauge
                width: 380
                height: 380
            }

            //----------------------------------
            // CENTER HUD
            //----------------------------------

            Item {

                id: centerHUD
                width: 420
                height: 420

                //----------------------------------
                // HUD BACKGROUND CIRCLE
                //----------------------------------

                Rectangle {
                    anchors.centerIn: parent
                    width: 320
                    height: 320
                    radius: 160

                    gradient: Gradient {
                        GradientStop { position: 0; color: "#0c2d57" }
                        GradientStop { position: 1; color: "#00152e" }
                    }

                    border.color: "#2aa7ff"
                    border.width: 2
                }

                //----------------------------------
                // CENTER TOP MENU
                //----------------------------------

                Text {
                    id: topMenuText
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 30

                    text: showTripMenu ? "TRIP MENU" : "ADAS"
                    color: "#55ff88"
                    font.pixelSize: 20
                    font.bold: true
                }

                //----------------------------------
                // ADAS DISPLAY (DEFAULT)
                //----------------------------------

                Column {

                    visible: !showTripMenu
                    anchors.centerIn: parent
                    spacing: 10

                    Text {
                        id: speedText
                        text: "0"
                        color: "white"
                        font.pixelSize: 80
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Text {
                        text: "km/h"
                        color: "#a0cfff"
                        font.pixelSize: 18
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Rectangle {
                        width: 120
                        height: 50
                        radius: 10
                        color: "#0f1f33"

                        Text {
                            anchors.centerIn: parent
                            text: "ADAS ACTIVE"
                            color: "#66ccff"
                            font.pixelSize: 14
                        }
                    }
                }

                //----------------------------------
                // TRIP MENU (RIGHT CLICK)
                //----------------------------------

                Column {

                    visible: showTripMenu
                    anchors.centerIn: parent
                    spacing: 15

                    Trip {
                        id: tripMenu
                        width: 250
                    }

                    Odometer {
                        id: odometer
                        width: 250
                    }
                }

                //----------------------------------
                // RIGHT CLICK MENU SWITCH
                //----------------------------------

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.RightButton

                    onClicked: {
                        showTripMenu = !showTripMenu
                    }
                }
            }

            //----------------------------------
            // RIGHT GAUGE (SPEED)
            //----------------------------------

            Speedometer {
                id: speedometer
                width: 380
                height: 380
            }
        }

        //--------------------------------------------------
        // BOTTOM INFO ROW
        //--------------------------------------------------

        RowLayout {

            Layout.fillWidth: true
            spacing: 40

            FuelGauge {
                id: fuelGauge
                width: 260
                height: 70
            }

            Item { Layout.fillWidth: true }

            //----------------------------------
            // ENGINE TEMP
            //----------------------------------

            Rectangle {
                width: 300
                height: 70
                radius: 8
                color: "#0c1118"

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

            //----------------------------------
            // LIGHT / DARK MODE SWITCH
            //----------------------------------

            Row {

                spacing: 10

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
    }
}
