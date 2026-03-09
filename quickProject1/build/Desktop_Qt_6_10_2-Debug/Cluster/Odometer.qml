import QtQuick 2.15

Rectangle {
    id: odometer
    width: 240
    height: 50
    radius: 5
    color: "black"
    border.color: "#606060"

    property int totalDistance: 0 // 0 to 10,00,000

    Text {
        anchors.centerIn: parent
        text: totalDistance.toString().padStart(7,"0") + " km"
        color: "#00FF00"
        font.pixelSize: 22
        font.family: "Ubuntu"
    }
}
