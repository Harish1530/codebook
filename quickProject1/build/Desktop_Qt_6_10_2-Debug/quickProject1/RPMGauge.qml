import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: rpmGauge
    width: 400
    height: 400

    property real rpm: 0
    property real maxRpm: 8000
    property int majorTickCount: 9
    property int minorTicksPerGap: 9

    readonly property real startDeg: 135
    readonly property real endDeg: 405
    readonly property real startRad: startDeg * Math.PI / 180
    readonly property real endRad: endDeg * Math.PI / 180
    readonly property real gaugeSpan: endRad - startRad

    readonly property real outerRadius: Math.min(width, height) * 0.43
    readonly property real innerRadius: outerRadius - 30
    readonly property real needleLength: innerRadius - 10

    property real displayedRpm: 0
    property real stepSize: 200
    property int stepInterval: 40

    Timer {
        id: animTimer
        interval: stepInterval
        repeat: true
        running: false

        onTriggered: {

            if (displayedRpm < rpm) {
                displayedRpm = Math.min(displayedRpm + stepSize, rpm)

            } else if (displayedRpm > rpm) {
                displayedRpm = Math.max(displayedRpm - stepSize, rpm)

            } else {
                stop()
            }

            canvas.requestPaint()
        }
    }

    onRpmChanged: {
        if (!animTimer.running)
            animTimer.start()
    }

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {

            var ctx = getContext("2d")
            ctx.clearRect(0,0,width,height)

            var cx = width/2
            var cy = height/2

            ctx.beginPath()
            ctx.arc(cx, cy, outerRadius, startRad, endRad, false)
            ctx.fillStyle = "#040121"
            ctx.fill()

            ctx.beginPath()
            ctx.arc(cx, cy, outerRadius, startRad, endRad, false)
            ctx.lineWidth = 2
            ctx.strokeStyle = "black"
            ctx.stroke()

            ctx.strokeStyle = "#fff"
            ctx.lineWidth = 2
            ctx.font = "18px DejaVu Sans"
            ctx.textAlign = "center"
            ctx.textBaseline = "middle"

            var majorStep = maxRpm / (majorTickCount - 1)

            for (var i=0;i<majorTickCount;i++){

                var value = i * majorStep
                var norm = value / maxRpm
                var angle = startRad + norm * gaugeSpan

                var xOut = cx + outerRadius * Math.cos(angle)
                var yOut = cy + outerRadius * Math.sin(angle)

                var xIn = cx + (outerRadius - 15) * Math.cos(angle)
                var yIn = cy + (outerRadius - 15) * Math.sin(angle)

                ctx.beginPath()
                ctx.moveTo(xOut,yOut)
                ctx.lineTo(xIn,yIn)
                ctx.stroke()

                var labelR = outerRadius - 30
                var xLabel = cx + labelR * Math.cos(angle)
                var yLabel = cy + labelR * Math.sin(angle)

                var label = Math.round(value / 1000).toString()
                if (value >= 0) {
                    ctx.fillStyle = "white"
                    ctx.fillText(label, xLabel, yLabel)
                }

                if(i < majorTickCount-1){

                    var nextValue = (i+1) * majorStep
                    var nextNorm = nextValue / maxRpm
                    var nextAngle = startRad + nextNorm * gaugeSpan

                    var gap = (nextAngle-angle)/(minorTicksPerGap+1)

                    for(var j=1;j<=minorTicksPerGap;j++){

                        var a = angle + j * gap

                        var xmOut = cx + outerRadius * Math.cos(a)
                        var ymOut = cy + outerRadius * Math.sin(a)

                        var xmIn = cx + (outerRadius - 8) * Math.cos(a)
                        var ymIn = cy + (outerRadius - 8) * Math.sin(a)

                        ctx.beginPath()
                        ctx.moveTo(xmOut,ymOut)
                        ctx.lineTo(xmIn,ymIn)
                        ctx.stroke()
                    }
                }
            }

            var clamped = Math.min(Math.max(displayedRpm,0),maxRpm)
            var rpmFraction = clamped / maxRpm

            var needleAngle = startRad + rpmFraction * gaugeSpan

            var tipX = cx + needleLength * Math.cos(needleAngle)
            var tipY = cy + needleLength * Math.sin(needleAngle)

            var baseWidth = 8
            var halfBase = baseWidth/2

            var ux = Math.cos(needleAngle)
            var uy = Math.sin(needleAngle)

            var px = uy
            var py = -ux

            var baseLeftX = cx + halfBase * px
            var baseLeftY = cy + halfBase * py

            var baseRightX = cx - halfBase * px
            var baseRightY = cy - halfBase * py

            ctx.beginPath()
            ctx.moveTo(baseLeftX,baseLeftY)
            ctx.lineTo(baseRightX,baseRightY)
            ctx.lineTo(tipX,tipY)
            ctx.closePath()

            var needleColor =
                (rpmFraction > 0.75) ? "red" :
                (rpmFraction > 0.5) ? "yellow" :
                "lime"

            ctx.fillStyle = needleColor
            ctx.fill()

            ctx.strokeStyle = "#000"
            ctx.lineWidth = 1
            ctx.stroke()

            ctx.beginPath()
            ctx.arc(cx,cy,25,0,Math.PI*2,false)
            ctx.fillStyle="black"
            ctx.fill()
            ctx.lineWidth=2
            ctx.strokeStyle="white"
            ctx.stroke()

            ctx.fillStyle="#fff"
            ctx.font="12px Ubuntu"
            ctx.textAlign="center"

            ctx.fillText("RPM",cx + 1,cy - 5)

            ctx.fillText("x1000",cx,cy+7)
        }
    }

    function setRpm(value){
        rpm = Math.min(Math.max(value,0),maxRpm)
    }
}
