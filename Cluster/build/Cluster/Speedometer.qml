// Speedometer.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: speedometer
    width: 400
    height: 400

    // ------------------- CAN-Bound Properties -------------------
    // Bind directly to backend. The onSpeedChanged handler below will start the animation.
    // (cluster is exported from C++ via engine.rootContext()->setContextProperty("cluster", &controller);)
    property real speed: cluster.speed        // km/h  ← live from CAN

    // ------------------- Gauge Configuration --------------------
    property real maxSpeed: 200
    property int  majorTickCount: 11
    property int  smallTicksPerGap: 9

    // Animation params
    property real stepSize: 0.5               // km/h per timer tick
    property int  stepInterval: 20            // ms

    // Animated value actually drawn
    property real displayedSpeed: 0

    // Geometry
    readonly property real startDeg: 135
    readonly property real endDeg:   405
    readonly property real startRad: startDeg * Math.PI / 180
    readonly property real endRad:   endDeg   * Math.PI / 180
    readonly property real gaugeSpan: endRad - startRad
    readonly property real radius: Math.min(width, height) * 0.43
    readonly property real needleLen: radius - 32
    readonly property real pivotRadius: 25

    // ------------------- Animation Timer ------------------------
    Timer {
        id: animTimer
        interval: stepInterval
        repeat: true
        running: false
        onTriggered: {
            if (displayedSpeed < speed) {
                displayedSpeed = Math.min(displayedSpeed + stepSize, speed)
            } else if (displayedSpeed > speed) {
                displayedSpeed = Math.max(displayedSpeed - stepSize, speed)
            } else {
                animTimer.stop()
            }
            canvas.requestPaint()
        }
    }

    // Start smoothing whenever the CAN value changes
    onSpeedChanged: if (!animTimer.running) animTimer.start()

    // Repaint on size changes as well
    onWidthChanged:  canvas.requestPaint()
    onHeightChanged: canvas.requestPaint()

    // ------------------- Canvas Rendering -----------------------
    Canvas {
        id: canvas
        anchors.centerIn: parent
        width:  speedometer.width
        height: speedometer.height

        onPaint: {
            var ctx = canvas.getContext('2d')
            ctx.clearRect(0, 0, width, height)

            var cx = width / 2
            var cy = height / 2

            // Face
            ctx.beginPath()
            ctx.arc(cx, cy, radius, startRad - 0.03, endRad + 0.03, false)
            ctx.fillStyle = '#040121'
            ctx.fill()

            // Rim
            ctx.beginPath()
            ctx.arc(cx, cy, radius, startRad - 0.02, endRad + 0.02, false)
            ctx.lineWidth = 4
            ctx.strokeStyle = 'black'
            ctx.stroke()

            // Ticks & labels
            ctx.strokeStyle = 'white'
            ctx.fillStyle   = 'white'
            ctx.lineWidth   = 2
            ctx.font        = '16px Ubuntu, DejaVu Sans, Sans-Serif'
            ctx.textAlign   = 'center'
            ctx.textBaseline= 'middle'

            var majorOuter = radius
            var majorInner = radius - 18
            var minorInner = radius - 10
            var majorStep = maxSpeed / (majorTickCount - 1)

            for (var i = 0; i < majorTickCount; ++i) {
                var majorValue = i * majorStep
                var norm       = majorValue / maxSpeed
                var angleMajor = startRad + norm * gaugeSpan

                var xMOut = cx + majorOuter * Math.cos(angleMajor)
                var yMOut = cy + majorOuter * Math.sin(angleMajor)
                var xMIn  = cx + majorInner * Math.cos(angleMajor)
                var yMIn  = cy + majorInner * Math.sin(angleMajor)

                ctx.beginPath()
                ctx.moveTo(xMOut, yMOut)
                ctx.lineTo(xMIn , yMIn )
                ctx.stroke()

                // numeric label
                var labelRadius = radius - 30
                var xLabel = cx + labelRadius * Math.cos(angleMajor)
                var yLabel = cy + labelRadius * Math.sin(angleMajor)
                ctx.fillText(Math.round(majorValue).toString(), xLabel, yLabel)

                // minor ticks
                if (i < majorTickCount - 1) {
                    var nextValue = (i + 1) * majorStep
                    var nextNorm  = nextValue / maxSpeed
                    var angleNext = startRad + nextNorm * gaugeSpan
                    var gapAngle  = (angleNext - angleMajor) / (smallTicksPerGap + 1)

                    for (var j = 1; j <= smallTicksPerGap; ++j) {
                        var angleMinor = angleMajor + j * gapAngle
                        var xOut = cx + majorOuter * Math.cos(angleMinor)
                        var yOut = cy + majorOuter * Math.sin(angleMinor)
                        var xIn  = cx + minorInner * Math.cos(angleMinor)
                        var yIn  = cy + minorInner * Math.sin(angleMinor)

                        ctx.beginPath()
                        ctx.moveTo(xOut, yOut)
                        ctx.lineTo(xIn , yIn )
                        ctx.stroke()
                    }
                }
            }

            // Needle (driven by displayedSpeed)
            var clamped = Math.min(Math.max(displayedSpeed, 0), maxSpeed)
            var norm = clamped / maxSpeed
            var needleAngle = startRad + norm * gaugeSpan

            var tipX = cx + needleLen * Math.cos(needleAngle)
            var tipY = cy + needleLen * Math.sin(needleAngle)

            var baseWidth = 8
            var halfBase = baseWidth / 2
            var ux = Math.cos(needleAngle)
            var uy = Math.sin(needleAngle)
            var px = uy
            var py = -ux

            var baseLeftX  = cx + halfBase * px
            var baseLeftY  = cy + halfBase * py
            var baseRightX = cx - halfBase * px
            var baseRightY = cy - halfBase * py

            ctx.beginPath()
            ctx.moveTo(baseLeftX,  baseLeftY)
            ctx.lineTo(baseRightX, baseRightY)
            ctx.lineTo(tipX, tipY)
            ctx.closePath()
            ctx.fillStyle = 'crimson'
            ctx.fill()
            ctx.lineWidth = 0.5
            ctx.strokeStyle = 'white'
            ctx.stroke()

            // Pivot
            ctx.beginPath()
            ctx.arc(cx, cy, pivotRadius, 0, Math.PI * 2, true)
            ctx.fillStyle = 'black'
            ctx.fill()
            ctx.lineWidth = 2
            ctx.strokeStyle = 'white'
            ctx.stroke()

            // Unit text
            ctx.fillStyle = 'white'
            ctx.font = '15px Arial'
            ctx.textAlign = 'center'
            ctx.fillText('km/h', cx , cy + 2)
        }
    }
}
