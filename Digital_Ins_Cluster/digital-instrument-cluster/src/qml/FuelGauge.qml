import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: fuelGauge
    width: 200
    height: 200
    color: "transparent"

    property real fuelLevel: 0.0 // Fuel level from 0.0 to 1.0
    property color lowFuelColor: "red"
    property color normalFuelColor: "green"

    // Background Circle
    Canvas {
        id: backgroundCanvas
        anchors.fill: parent
        onPaint: {
            var ctx = backgroundCanvas.getContext('2d');
            ctx.clearRect(0, 0, backgroundCanvas.width, backgroundCanvas.height);
            ctx.beginPath();
            ctx.arc(backgroundCanvas.width / 2, backgroundCanvas.height / 2, 80, 0, 2 * Math.PI);
            ctx.fillStyle = "lightgray";
            ctx.fill();
        }
    }

    // Fuel Level Indicator
    Canvas {
        id: fuelLevelCanvas
        anchors.fill: parent
        onPaint: {
            var ctx = fuelLevelCanvas.getContext('2d');
            ctx.clearRect(0, 0, fuelLevelCanvas.width, fuelLevelCanvas.height);
            ctx.beginPath();
            ctx.arc(fuelLevelCanvas.width / 2, fuelLevelCanvas.height / 2, 80, -Math.PI / 2, -Math.PI / 2 + (fuelLevel * 2 * Math.PI));
            ctx.lineTo(fuelLevelCanvas.width / 2, fuelLevelCanvas.height / 2);
            ctx.fillStyle = fuelLevel < 0.2 ? lowFuelColor : normalFuelColor;
            ctx.fill();
        }
    }

    // Text Display
    Text {
        anchors.centerIn: parent
        text: Math.round(fuelLevel * 100) + "%"
        font.pixelSize: 24
        color: "black"
    }

    // Update the fuel gauge when fuelLevel changes
    onFuelLevelChanged: {
        fuelLevelCanvas.requestPaint();
    }
}