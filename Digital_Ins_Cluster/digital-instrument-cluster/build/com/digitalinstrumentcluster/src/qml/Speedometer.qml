import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: speedometer
    width: 400
    height: 400

    property real speed: 0

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            var ctx = canvas.getContext('2d');
            ctx.clearRect(0, 0, canvas.width, canvas.height);

            // Draw the speedometer background
            ctx.beginPath();
            ctx.arc(canvas.width / 2, canvas.height / 2, 150, 0, Math.PI, false);
            ctx.fillStyle = '#e0e0e0';
            ctx.fill();

            // Draw the speedometer needle
            var angle = (speed / 200) * Math.PI - Math.PI / 2; // Assuming max speed is 200
            ctx.beginPath();
            ctx.moveTo(canvas.width / 2, canvas.height / 2);
            ctx.lineTo(canvas.width / 2 + 120 * Math.cos(angle), canvas.height / 2 + 120 * Math.sin(angle));
            ctx.lineWidth = 5;
            ctx.strokeStyle = 'red';
            ctx.stroke();

            // Draw the speed text
            ctx.fillStyle = 'black';
            ctx.font = '30px Arial';
            ctx.fillText(Math.round(speed) + ' km/h', canvas.width / 2 - 30, canvas.height / 2 + 10);
        }
    }

    function updateSpeed(newSpeed) {
        speed = newSpeed;
        canvas.requestPaint();
    }
}