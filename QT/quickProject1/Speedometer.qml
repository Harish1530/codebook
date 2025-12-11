// Speedometer.qml
// ---------------------------------------------------------------
// This is AI generated code, please refer KPIT AI Policy before
// using this in your projects
// ---------------------------------------------------------------
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: speedometer
    width: 400          // default size – can be overridden by the parent
    height: 400

    /* -----------------------------------------------------------------
       CONFIGURATION – original properties + animation‑related ones
       ----------------------------------------------------------------- */
    // ------------ ORIGINAL PROPERTIES ---------------------------------
    property real speed: 0               // **target** speed (km/h) set from outside
    property real maxSpeed: 200
    property int   majorTickCount: 11
    property int   smallTicksPerGap: 9

    // ------------ NEW PROPERTIES « CHANGE » --------------------------
    // How many km/h are added on each timer tick (adjustable)
    property real stepSize: 1         // default = 5 km/h per tick
    property int   stepInterval: 40

    // The value that is actually drawn on the canvas.  It is animated
    // from 0 → speed whenever the *target* speed changes.
    property real displayedSpeed: 0

    // ------------ GAUGE GEOMETRY (unchanged) ------------------------
    readonly property real startDeg: 135       // left‑bottom of the gauge
    readonly property real endDeg:   405       // right‑bottom of the gauge
    readonly property real startRad: startDeg * Math.PI / 180
    readonly property real endRad:   endDeg   * Math.PI / 180
    readonly property real gaugeSpan: endRad - startRad
    readonly property real radius: 150        // outer radius of the face
    readonly property real needleLen: 110     // length of the pointer
    readonly property real pivotRadius: 25    // radius of the dark centre knob

    /* -----------------------------------------------------------------
       TIMER – drives the step‑wise animation  « CHANGE »
       ----------------------------------------------------------------- */
    Timer {
        id: animTimer                     // name matches the usage in onSpeedChanged
        interval: stepInterval
        repeat: true
        running: false                    // started only when a new target speed arrives
        onTriggered: {
            if (displayedSpeed < speed) {
                displayedSpeed = Math.min(displayedSpeed + stepSize, speed)
                canvas.requestPaint()
            } else {
                stop()                     // reached the target → stop animating
            }
        }
    }

    // Whenever the **target** speed changes we reset the animation.
    onSpeedChanged: {
        displayedSpeed = 0                 // start from zero each time
        animTimer.start()                  // « CHANGE » (was stepTimer.start())
    }

    /* -----------------------------------------------------------------
       CANVAS – draws the gauge (now uses displayedSpeed)
       ----------------------------------------------------------------- */
    Canvas {
        id: canvas
        width: speedometer.width
        height: speedometer.height

        // Position the gauge at the left side of its parent and keep it
        // vertically centred – you can change the anchors in the parent if
        // you need a different layout.
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter

        onPaint: {
            var ctx = canvas.getContext('2d')
            ctx.clearRect(0, 0, canvas.width, canvas.height)

            var cx = canvas.width  / 2   // centre X
            var cy = canvas.height / 2   // centre Y

            // Gauge
            var innerRadius = radius - 125
            ctx.beginPath()
            ctx.arc(cx, cy, radius, startRad - 0.03, endRad + 0.03, false)
            ctx.fillStyle = '#040121'          // dark‑gray face
            ctx.fill()

            ctx.beginPath()
            ctx.arc(cx, cy, radius, startRad - 0.02, endRad + 0.02, false)
            ctx.lineWidth = 4
            ctx.strokeStyle = 'black'
            ctx.stroke()

            // Major and Minor Ticks
            ctx.strokeStyle = 'white'
            ctx.fillStyle   = 'white'
            ctx.lineWidth   = 2
            ctx.font        = '16px Arial'
            ctx.textAlign   = 'center'
            ctx.textBaseline= 'middle'

            var majorOuter = radius
            var majorInner = radius - 18      // long tick
            var minorInner = radius - 10      // short tick

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
                ctx.fillText(Math.round(majorValue).toString(),
                             xLabel, yLabel)

                // minor ticks between this major tick and the next one
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

            // ---------------------------------------------------------
            // 2️⃣  NEEDLE – now driven by displayedSpeed
            // ---------------------------------------------------------
            var clamped = Math.min(Math.max(displayedSpeed, 0), maxSpeed)
            var norm    = clamped / maxSpeed
            var needleAngle = startRad + norm * gaugeSpan

            var tipX = cx + needleLen * Math.cos(needleAngle)
            var tipY = cy + needleLen * Math.sin(needleAngle)

            var baseWidth = 8
            var halfBase  = baseWidth / 2

            // unit vectors
            var ux = Math.cos(needleAngle)
            var uy = Math.sin(needleAngle)
            var px = uy                 // perpendicular (90° clockwise)
            var py = -ux

            var baseLeftX  = cx + halfBase * px
            var baseLeftY  = cy + halfBase * py
            var baseRightX = cx - halfBase * px
            var baseRightY = cy - halfBase * py

            ctx.beginPath()
            ctx.moveTo(baseLeftX,  baseLeftY)   // left side of base
            ctx.lineTo(baseRightX, baseRightY)  // right side of base
            ctx.lineTo(tipX,       tipY)        // tip
            ctx.closePath()
            ctx.fillStyle = 'crimson'
            ctx.fill()
            ctx.lineWidth = 0.5
            ctx.strokeStyle = 'white'
            ctx.stroke()

            // ---------------------------------------------------------
            // 3️⃣  DARK PIVOT KNOB
            // ---------------------------------------------------------
            ctx.beginPath()
            ctx.arc(cx, cy, pivotRadius, 0, Math.PI * 2, true)
            ctx.fillStyle = 'black'
            ctx.fill()
            ctx.lineWidth = 2
            ctx.strokeStyle = 'white'
            ctx.stroke()

            // ---------------------------------------------------------
            // 4️⃣  SPEED TEXT (foreground)
            // ---------------------------------------------------------
            ctx.fillStyle = 'white'
            ctx.font = '15px Arial'
            ctx.textAlign = 'center'
            ctx.fillText(' km/h',
                         cx - 2,
                         cy + 2)   // a little below centre
        }
    }

    /* -----------------------------------------------------------------
       PUBLIC API – unchanged, still useful for external callers
       ----------------------------------------------------------------- */
    function updateSpeed(newSpeed) {
        // Clamp the target speed and trigger the animation
        speed = Math.min(Math.max(newSpeed, 0), maxSpeed)   // « CHANGE » (no extra requestPaint – animation timer will repaint)
    }
}
