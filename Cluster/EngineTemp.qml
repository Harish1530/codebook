// EngineTemp.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: engineTemp
    width: 300
    height: 80

    // ── CAN-bound property ───────────────────────────────────────
    property real tempC: cluster.engineTempC   // °C from CAN

    // ── Thresholds (easy to tune) ────────────────────────────────
    property real coldThreshold: 40.0          // below this → cold (blue)
    property real normalThreshold: 80.0        // below this → normal (green)
    property real hotThreshold: 100.0          // above this → hot (red)
    property real maxTempC: 120.0              // full-bar temp

    // ── Animated display value ───────────────────────────────────
    property real displayedTemp: tempC

    onTempCChanged: displayedTemp = tempC

    Behavior on displayedTemp {
        NumberAnimation { duration: 300; easing.type: Easing.InOutQuad }
    }

    // ── Colour logic (opposite to fuel gauge) ────────────────────
    //    Fuel:  green=good(high),  red=bad(low)
    //    Temp:  blue=cold(low),    green=normal, orange=warm, red=hot(high)
    readonly property color barColor: {
        if (displayedTemp < coldThreshold)   return "#00aaff"   // cold  → blue
        if (displayedTemp < normalThreshold) return "#6BFF6B"   // normal→ green
        if (displayedTemp < hotThreshold)    return "#ff8800"   // warm  → orange
        return "#ff4d4d"                                        // hot   → red
    }

    readonly property color labelColor: {
        if (displayedTemp < coldThreshold)   return "#00aaff"
        if (displayedTemp < normalThreshold) return "white"
        if (displayedTemp < hotThreshold)    return "#ff8800"
        return "#ff4d4d"
    }

    // ── Background card ──────────────────────────────────────────
    Rectangle {
        anchors.fill: parent
        radius: 10
        color: "#151515"
        border.color: "#333"
    }

    // ── Thermometer icon (canvas-drawn, left side) ───────────────
    Canvas {
        id: iconCanvas
        width: 36
        height: 36
        anchors.verticalCenter: parent.verticalCenter
        x: 8

        onPaint: {
            var ctx = getContext("2d")
            ctx.clearRect(0, 0, width, height)

            var col = engineTemp.barColor

            // Tube body (rounded rectangle)
            ctx.strokeStyle = col
            ctx.lineWidth   = 2.5
            ctx.beginPath()
            ctx.moveTo(16, 6)
            ctx.lineTo(20, 6)
            ctx.arc(20, 8, 2, -Math.PI / 2, Math.PI / 2, false)
            ctx.lineTo(16, 10)
            ctx.arc(16, 8, 2, Math.PI / 2, -Math.PI / 2, false)
            ctx.closePath()
            ctx.stroke()

            // Tube stem
            ctx.beginPath()
            ctx.moveTo(17, 10)
            ctx.lineTo(17, 24)
            ctx.moveTo(19, 10)
            ctx.lineTo(19, 24)
            ctx.stroke()

            // Bulb at bottom
            ctx.beginPath()
            ctx.arc(18, 27, 6, 0, Math.PI * 2)
            ctx.fillStyle = col
            ctx.fill()

            // Fill level inside stem (proportional to temp)
            var fillH = 14.0 * Math.min(displayedTemp / maxTempC, 1.0)
            ctx.fillStyle = col
            ctx.fillRect(17, 24 - fillH, 2, fillH)
        }
    }

    // ── Bar + text (right of icon) ───────────────────────────────
    Item {
        anchors.left: iconCanvas.right
        anchors.leftMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 12
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        // Background track
        Rectangle {
            id: trackBg
            width: parent.width
            height: 16
            radius: 8
            color: "#2a2a2a"
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: -8

            // Filled bar
            Rectangle {
                id: barFill
                height: parent.height
                radius: 8
                width: parent.width *
                       Math.min(Math.max(displayedTemp / maxTempC, 0.02), 1.0)
                color: barColor

                // Gradient shimmer
                Rectangle {
                    anchors.fill: parent
                    radius: parent.radius
                    gradient: Gradient {
                        orientation: Gradient.Horizontal
                        GradientStop { position: 0.0; color: Qt.darker(barColor, 1.1) }
                        GradientStop { position: 0.5; color: Qt.lighter(barColor, 1.2) }
                        GradientStop { position: 1.0; color: barColor }
                    }
                    opacity: 0.6
                }

                Behavior on width {
                    NumberAnimation { duration: 300; easing.type: Easing.InOutQuad }
                }
                Behavior on color {
                    ColorAnimation { duration: 400 }
                }
            }
        }

        // Label row below bar
        Row {
            anchors.top: trackBg.bottom
            anchors.topMargin: 6
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 8

            Text {
                text: "ENG TEMP"
                color: "#aaa"
                font.pixelSize: 13
            }

            Text {
                text: Math.round(displayedTemp) + " °C"
                color: labelColor
                font.pixelSize: 13
                font.bold: true

                Behavior on color { ColorAnimation { duration: 400 } }
            }

            // Status badge
            Text {
                text: {
                    if (displayedTemp < coldThreshold)   return "COLD"
                    if (displayedTemp < normalThreshold) return "OK"
                    if (displayedTemp < hotThreshold)    return "WARM"
                    return "HOT ⚠"
                }
                color: labelColor
                font.pixelSize: 11
                font.bold: true
                opacity: 0.85
            }
        }
    }

    // ── Hot flash animation (above hotThreshold only) ─────────────
    SequentialAnimation {
        id: flashAnim
        running: displayedTemp >= hotThreshold
        loops: Animation.Infinite

        NumberAnimation {
            target: engineTemp
            property: "opacity"
            from: 1.0; to: 0.5
            duration: 400
        }
        NumberAnimation {
            target: engineTemp
            property: "opacity"
            from: 0.5; to: 1.0
            duration: 400
        }
    }

    // Stop flash and restore opacity when temp drops
    onDisplayedTempChanged: {
        if (displayedTemp < hotThreshold) {
            flashAnim.stop()
            engineTemp.opacity = 1.0
        }
        iconCanvas.requestPaint()
    }
}
