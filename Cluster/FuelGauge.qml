import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: fuelGauge
    width: 300
    height: 80

    // Fuel values
    property real fuelLevel: 0.0        // Target value 0..1
    property real displayedFuel: 0.5    // Animated value 0..1

    property int interval: 30

    property color lowFuelColor: "#ff4d4d"
    property color normalFuelColor: "#6BFF6B"
    property color backgroundColor: "#d9d9d9"

    Timer {
        id: animTimer
        interval: fuelGauge.interval
        repeat: true
        running: false

        onTriggered: {
            const speed = 0.004

            if (displayedFuel < fuelLevel) {
                displayedFuel = Math.min(displayedFuel + speed, fuelLevel)
            } else if (displayedFuel > fuelLevel) {      // FIXED
                displayedFuel = Math.max(displayedFuel - speed, fuelLevel)
            } else {
                stop()
            }
            barCanvas.requestPaint()
        }
    }

    // Trigger animation when fuelLevel changes
    onFuelLevelChanged: if (!animTimer.running) animTimer.start()

    // Public API
    function setfuelLevel(value) {
        fuelLevel = Math.min(Math.max(value, 0), 1)   // FIXED
    }

    // Drawing code
    Canvas {
        id: barCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

            var barHeight = 26
            var padding = 15
            var radius = barHeight / 2
            var barWidth = width - padding * 2
            var barX = padding
            var barY = (height - barHeight) / 2 - 8

            // Background rounded bar
            ctx.fillStyle = backgroundColor
            ctx.beginPath()
            ctx.moveTo(barX + radius, barY)
            ctx.lineTo(barX + barWidth - radius, barY)
            ctx.quadraticCurveTo(barX + barWidth, barY, barX + barWidth, barY + radius)
            ctx.lineTo(barX + barWidth, barY + barHeight - radius)
            ctx.quadraticCurveTo(barX + barWidth, barY + barHeight, barX + barWidth - radius, barY + barHeight)
            ctx.lineTo(barX + radius, barY + barHeight)
            ctx.quadraticCurveTo(barX, barY + barHeight, barX, barY + barHeight - radius)
            ctx.lineTo(barX, barY + radius)
            ctx.quadraticCurveTo(barX, barY, barX + radius, barY)
            ctx.fill()

            // Filled portion
            var fillWidth = displayedFuel * barWidth
            var fillColor = displayedFuel < 0.2 ? lowFuelColor : normalFuelColor

            var gradient = ctx.createLinearGradient(barX, 0, barX + fillWidth, 0)
            gradient.addColorStop(0, fillColor)
            gradient.addColorStop(1, Qt.lighter(fillColor, 1.2))

            ctx.fillStyle = gradient
            ctx.beginPath()
            var w = Math.max(fillWidth, radius * 2)
            ctx.moveTo(barX + radius, barY)
            ctx.lineTo(barX + w - radius, barY)
            ctx.quadraticCurveTo(barX + w, barY, barX + w, barY + radius)
            ctx.lineTo(barX + w, barY + barHeight - radius)
            ctx.quadraticCurveTo(barX + w, barY + barHeight, barX + w - radius, barY + barHeight)
            ctx.lineTo(barX + radius, barY + barHeight)
            ctx.quadraticCurveTo(barX, barY + barHeight, barX, barY + barHeight - radius)
            ctx.lineTo(barX, barY + radius)
            ctx.quadraticCurveTo(barX, barY, barX + radius, barY)
            ctx.fill()
        }
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        y: (height / 2) + 10
        text: Math.round(displayedFuel * 100) + "%"
        font.pixelSize: 18
        font.bold: true
        color: displayedFuel < 0.2 ? lowFuelColor : "#333"
        opacity: 0.9
    }
}
