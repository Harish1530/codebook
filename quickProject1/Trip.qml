import QtQuick 2.15
import QtQuick.Controls

Rectangle {
    id:tripMenu
    width: 220
    height: 120
    radius: 10
    color: "#101010"
    border.color: "#404040"

    property int trip1: 50
    property int trip2: 0
    property int activeTrip: 1

    Column {
        anchors.centerIn: parent
        spacing: 6

        Text{
            text: activeTrip === 1 ? "TRIP 1" : "TRIP 2"
            color: "White"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            text: activeTrip === 1 ? trip1.toFixed(1) + " km" : trip2.toFixed(1) + " km"
            color: "#00FFFF"
            font.pixelSize: 28
            horizontalAlignment: Text.AlignHCenter
        }

        Row {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                text: "Trip 1"
                onClicked: activeTrip = 1
            }

            Button {
                text: "Trip 2"
                onClicked: activeTrip = 2
            }
        }
    }
}
