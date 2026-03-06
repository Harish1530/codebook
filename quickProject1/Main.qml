// Main.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 1000
    height: 600
    title: "Digital Instrument Cluster Simulator"


    Rectangle {
        id: backgroundRect
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#191919" }
            GradientStop { position: 0.6; color: "#2b2b2b" }
            GradientStop { position: 1.0; color: "#0d0d0d" }
        }
    }

    Speedometer {
        id: speedometer
        width: 350
        height: 400
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter

        // The component now animates smoothly (see the Speedometer.qml snippet below)
        // Component.onCompleted: {
        //     // Initialise with a sensible value – the mock CAN will overwrite it later.
        //     updateSpeed(0)
        // }
    }

    RPMGauge {
        id: rpmGauge
        width: 350
        height: 400          // keep it square for a perfect gauge
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        // Component.onCompleted: {
        //     setRpm(0)          // start at 0 rpm; mock CAN will drive it
        // }
    }

    FuelGauge {
        id: fuelGauge
        width: 300          // bar width
        height: 80          // bar + % text

        // Left padding – you can change this value later
        readonly property int leftPadding: 500

        anchors.top: speedometer.bottom
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: leftPadding
    }

    Indicators {
        id: indicators
        anchors.top: parent.top
        anchors.right: parent.left   // keep original layout
        height: 500
    }

    property real mockSpeed: 100      // km/h  (0 … 240)
    property real mockRpm:   5000      // rpm   (0 … 8000)
    property real mockFuel:  0.5    // 0 … 1 (50 % at start)

    Timer {
        id: mockCanTimer
        interval: 100               // 100 ms  → 10 Hz update rate
        repeat: true
        running: false              // will be started in Component.onCompleted
        onTriggered: {
            // ----- SPEED -----
            // Increment *before* applying the wrap‑around.
            mockSpeed = (mockSpeed + 1) % 240
            if (Math.abs(mockSpeed - speedometer.currentSpeed) > 0.5)
                speedometer.updateSpeed(mockSpeed)

            // ----- RPM -----
            mockRpm = (mockRpm + 50) % 8000
            if (Math.abs(mockRpm - rpmGauge.currentRpm) > 10)
                rpmGauge.setRpm(mockRpm)

            // ----- FUEL -----
            // Keep the fuel level static for now (comment out the line below
            // if you want a constant 50 %).  Uncomment to see a draining bar.
            // mockFuel = Math.max(1, mockFuel - 0.001)

            if (fuelGauge.setFuelLevel !== undefined)
                fuelGauge.setFuelLevel(mockFuel)
            else
                fuelGauge.fuelLevel = mockFuel
        }
    }

    Component.onCompleted: {
        console.log("Inside app – mock CAN started")

        // Initialise all gauges once
        speedometer.updateSpeed(mockSpeed)
        rpmGauge.setRpm(mockRpm)

        if (fuelGauge.setFuelLevel !== undefined)
            fuelGauge.setFuelLevel(mockFuel)
        else
            fuelGauge.fuelLevel = mockFuel

        // Start the mock‑CAN timer after the gauges have been initialised
        mockCanTimer.start()
    }
}
