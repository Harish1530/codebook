import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: fuelGauge
    width: 300
    height: 80

    // Public Properties
    property real targetFuel: 0.0 // Target Fuel Level
    property real displayedFuel: 0.0

    //Colours
    property color lowFuelColor: "red"
    property color normalFuelColor: "limegreen"
    property color backgroundColor: "lightgray"

    //Animation

    Timer {
        id: animTimer
        interval: 40
        repeat: true
        running: false
        onTriggered: {
            if(displayedFuel < targetFuel) {
                displayedFuel = Math.min(displayedFuel + 0.001, targetFuel)
                barCanvas.requestPaint()
            } else {
                stop()
            }
        }
    }

    // Restart Animation whenever new target arrives
    onTargetFuelChanged: {
        if(!animTimer.running)
            animTimer.start()
    }

    // PUBLIC API

    function setFuelLevel(value) {
        // Set value between 0 and 1
        targetFuel = Math.min(Math.max(value, 0), 1)
    }

    // Background Bar
    Canvas {
        id: barCanvas
        anchors.fill: parent
        onPaint: {
            var ctx = getContext('2d')
            ctx.clearRect(0, 0, width, height)

            // thin Horizantal bar centred vertically
            var barHeight = 20
            var padding = 10
            var barWidth = width - 2 * padding
            var barX = padding
            var barY = (height - barHeight) / 2 - 10

            // Background (grey)
            ctx.beginPath()
            ctx.rect(barX, barY, barWidth, barHeight)
            ctx.fillStyle = backgroundColor
            ctx.fill()

            // Filled Portion

            var fillWidth = displayedFuel * barWidth
            ctx.beginPath()
            ctx.rect(barX, barY, fillWidth, barHeight)

            var fillCol = displayedFuel < 0.2 ? lowFuelColor: normalFuelColor
            ctx.fillStyle = fillCol
            ctx.fill()
        }
    }

    // Text - percentage shown below the MenuBar
    Text {
        id: percentText
        anchors.horizontalCenter: parent.horizontalCenter
        y: (height / 2) + 10  // Position under the bar
        text: Math.round(displayedFuel * 100) + " %"
        font.pixelSize: 15
        color: "black"
    }

}
