import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: rpmGauge
    width: 200
    height: 200

    property real rpm: 0
    property real maxRpm: 8000

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext('2d');
            ctx.clearRect(0, 0, width, height);

            // Draw the background
            ctx.fillStyle = '#222';
            ctx.beginPath();
            ctx.arc(width / 2, height / 2, 90, 0, Math.PI * 2);
            ctx.fill();

            // Draw the RPM arc
            ctx.strokeStyle = '#0f0';
            ctx.lineWidth = 10;
            ctx.beginPath();
            var startAngle = -Math.PI / 2;
            var endAngle = startAngle + (Math.PI * 2) * (rpm / maxRpm);
            ctx.arc(width / 2, height / 2, 80, startAngle, endAngle);
            ctx.stroke();

            // Draw the RPM text
            ctx.fillStyle = '#fff';
            ctx.font = '20px Arial';
            ctx.textAlign = 'center';
            ctx.fillText(Math.round(rpm) + ' RPM', width / 2, height / 2 + 10);
        }
    }

    onRpmChanged: {
        canvas.requestPaint();
    }
}