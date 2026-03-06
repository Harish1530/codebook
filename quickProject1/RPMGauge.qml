// RPMGauge.qml
// ---------------------------------------------------------------
// This is AI generated code, please refer KPIT AI Policy before
// using this in your projects
// ---------------------------------------------------------------
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: rpmGauge
    width: 400               // can be overridden by the parent
    height: 400

    // PUBLIC PROPERTIES -------------------------------------------------
    property real rpm: 0               // **target** rpm (set from outside)
    property real maxRpm: 8000
    property int   majorTickCount: 9   // 0, 1000 … 8000 → 9 major divisions
    property int   minorTicksPerGap: 9 // 4 minor ticks between two majors

    // Geometry – the gauge is a 270° sweep (135° → 405°)
    readonly property real startDeg: 135          // left‑bottom
    readonly property real endDeg:   405          // right‑bottom
    readonly property real startRad: startDeg * Math.PI / 180
    readonly property real endRad:   endDeg   * Math.PI / 180
    readonly property real gaugeSpan: {
        var s = endRad - startRad                 // 270° → 3π/2 rad
        if (s < 0) s += Math.PI * 2
        return s
    }

    // Visual constants – all derived from the component size
    readonly property real outerRadius: Math.min(width, height) * 0.43   // ≈160 px for 400×400
    readonly property real innerRadius: outerRadius - 30               // thickness = 30 px
    readonly property real needleLength: innerRadius - 10

    // Animation – stepwise increase of the displayed value
    property real displayedRpm: 0          // value that is actually drawn
    property real stepSize: 200            // rpm added per tick (adjustable)
    property int   stepInterval: 100       // ms between steps

    Timer {
        id: animTimer
        interval: stepInterval
        repeat: true
        running: false
        onTriggered: {
            if (displayedRpm < rpm) {
                displayedRpm = Math.min(displayedRpm + stepSize, rpm)
                canvas.requestPaint()
            } else {
                stop()
            }
        }
    }

    // Whenever the *target* rpm changes we (re)start the animation.
    onRpmChanged: {
        displayedRpm = 0
        animTimer.start()
    }

    // CANVAS – all drawing logic lives here
    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext('2d')
            ctx.clearRect(0, 0, width, height)

            var cx = width  / 2
            var cy = height / 2

            // ---------------------------------------------------------
            // 0️⃣  BACKGROUND RING (dark gray)
            // ---------------------------------------------------------
            ctx.beginPath()
            ctx.arc(cx, cy, outerRadius, startRad, endRad, false) // outer arc
            ctx.closePath()
            ctx.fillStyle = '#040121'                     // dark background
            ctx.fill()

            // « CHANGE » – draw a **border** around the whole gauge
            ctx.beginPath()
            ctx.arc(cx, cy, outerRadius, startRad, endRad, false)
            ctx.lineWidth = 2
            ctx.strokeStyle = 'black'   // a slightly lighter gray than the face
            ctx.stroke()

            // ---------------------------------------------------------
            // 1️⃣  MAJOR & MINOR TICKS + numeric labels
            // ---------------------------------------------------------
            ctx.strokeStyle = '#fff'
            ctx.lineWidth   = 2
            ctx.font        = '14px Arial'
            ctx.textAlign   = 'center'
            ctx.textBaseline= 'middle'

            var majorStep = maxRpm / (majorTickCount - 1)    // e.g. 0‑8000/8 = 1000
            for (var i = 0; i < majorTickCount; ++i) {
                var value = i * majorStep
                var norm  = value / maxRpm
                var angle = startRad + norm * gaugeSpan

                // ---- major tick (long)
                var xOut = cx + outerRadius * Math.cos(angle)
                var yOut = cy + outerRadius * Math.sin(angle)
                var xIn  = cx + (outerRadius - 15) * Math.cos(angle)
                var yIn  = cy + (outerRadius - 15) * Math.sin(angle)

                ctx.beginPath()
                ctx.moveTo(xOut, yOut)
                ctx.lineTo(xIn , yIn )
                ctx.stroke()

                // ---- numeric label (placed slightly inside the tick)
                var labelR = outerRadius - 30
                var xLabel = cx + labelR * Math.cos(angle)
                var yLabel = cy + labelR * Math.sin(angle)
                ctx.fillStyle = '#fff'
                ctx.fillText(Math.round(value / 1000).toString(), xLabel, yLabel)

                // ---- minor ticks
                if (i < majorTickCount - 1) {
                    var nextValue = (i + 1) * majorStep
                    var nextNorm  = nextValue / maxRpm
                    var nextAngle = startRad + nextNorm * gaugeSpan
                    var minorGap   = (nextAngle - angle) / (minorTicksPerGap + 1)

                    for (var j = 1; j <= minorTicksPerGap; ++j) {
                        var a = angle + j * minorGap
                        var xmOut = cx + outerRadius * Math.cos(a)
                        var ymOut = cy + outerRadius * Math.sin(a)
                        var xmIn  = cx + (outerRadius - 8) * Math.cos(a)
                        var ymIn  = cy + (outerRadius - 8) * Math.sin(a)

                        ctx.beginPath()
                        ctx.moveTo(xmOut, ymOut)
                        ctx.lineTo(xmIn , ymIn )
                        ctx.stroke()
                    }
                }
            }

            // ---------------------------------------------------------
            // 2️⃣  RPM “filled” arc – **transparent**, grows from 0 → max
            // ---------------------------------------------------------
            var rpmFraction = displayedRpm / maxRpm

            // colour stays green, but we give it an alpha value so the arc looks
            // semi‑transparent against the dark background.
            var fillColor = (rpmFraction > 0.75) ?
                            'rgba(255,0,0,0.35)'
                        :(rpmFraction > 0.5) ?
                            'rgba(255,255,0,0.35)'
                        :
                            'rgba(0,255,0,0.35)'

            var fillStart = startRad
            var fillEnd   = startRad + rpmFraction * gaugeSpan

            ctx.beginPath()
            // draw the arc a little inside the background ring so the border
            // remains visible
            ctx.arc(cx, cy, innerRadius + 5, fillStart, fillEnd, false)
            ctx.lineWidth = 20
            ctx.strokeStyle = fillColor
            ctx.stroke()

            // ---------------------------------------------------------
            // 3️⃣  Needle – **pointed** (triangular) – driven by displayedRpm
            // ---------------------------------------------------------
            var needleAngle = startRad + rpmFraction * gaugeSpan
            var tipX = cx + needleLength * Math.cos(needleAngle)
            var tipY = cy + needleLength * Math.sin(needleAngle)

            // base of the needle (wide)
            var baseWidth = 8                      // total width at the centre
            var halfBase  = baseWidth / 2

            // unit vectors
            var ux = Math.cos(needleAngle)
            var uy = Math.sin(needleAngle)
            // perpendicular (rotated 90° clockwise)
            var px = uy
            var py = -ux

            // two corners at the base
            var baseLeftX  = cx + halfBase * px
            var baseLeftY  = cy + halfBase * py
            var baseRightX = cx - halfBase * px
            var baseRightY = cy - halfBase * py

            ctx.beginPath()
            ctx.moveTo(baseLeftX,  baseLeftY)   // left corner of base
            ctx.lineTo(baseRightX, baseRightY)  // right corner of base
            ctx.lineTo(tipX, tipY)        // tip (sharp)
            ctx.closePath()
            ctx.fillStyle = fillColor               // white needle – easy to see
            ctx.fill()
            ctx.lineWidth = 1
            ctx.strokeStyle = '#000'
            ctx.stroke()

            // ---------------------------------------------------------
            // 4️⃣  Central pivot (covers needle base)
            // ---------------------------------------------------------
            ctx.beginPath()
            ctx.arc(cx, cy, 25, 0, Math.PI * 2, false)
            ctx.fillStyle = 'black'
            ctx.fill()
            ctx.lineWidth = 2
            ctx.strokeStyle = 'white'
            ctx.stroke()

            // ---------------------------------------------------------
            // 5️⃣  RPM numeric read‑out (foreground)
            // ---------------------------------------------------------
            ctx.fillStyle = '#fff'
            ctx.font = '12px Arial'
            ctx.textAlign = 'center'
            ctx.textBaseline = 'alphabetic'
            var centreX = cx
            var centreY = cy + outerRadius * 0
            ctx.fillText(/*Math.round(displayedRpm) +*/ ' RPM', centreX, cy)

            var lineSpacing = 9
            var secondLineY = centreY + 5 + lineSpacing

            ctx.font = '12px Arial'
            ctx.fillText('x1000', cx, secondLineY)
        }
    }

    // PUBLIC helper ----------------------------------------------------
    function setRpm(value) {
        rpm = Math.min(Math.max(value, 0), maxRpm)   // clamp to range
    }
}
