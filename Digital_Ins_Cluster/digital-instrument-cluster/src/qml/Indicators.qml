import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: indicators
    width: 400
    height: 100

    // Turn Indicators
    Rectangle {
        id: leftIndicator
        width: 50
        height: 50
        color: "transparent"
        border.color: "yellow"
        visible: false

        // Animation for left turn indicator
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: leftIndicator.visible
            NumberAnimation { from: 1; to: 0; duration: 0.5 }
            NumberAnimation { from: 0; to: 1; duration: 0.5 }
        }
    }

    Rectangle {
        id: rightIndicator
        width: 50
        height: 50
        color: "transparent"
        border.color: "yellow"
        visible: false

        // Animation for right turn indicator
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: rightIndicator.visible
            NumberAnimation { from: 1; to: 0; duration: 0.5 }
            NumberAnimation { from: 0; to: 1; duration: 0.5 }
        }
    }

    // Low Fuel Warning
    Rectangle {
        id: lowFuelWarning
        width: 50
        height: 50
        color: "transparent"
        border.color: "red"
        visible: false

        // Animation for low fuel warning
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: lowFuelWarning.visible
            NumberAnimation { from: 1; to: 0; duration: 0.5 }
            NumberAnimation { from: 0; to: 1; duration: 0.5 }
        }
    }

    // Emergency Warning Lights
    Rectangle {
        id: emergencyWarning
        width: 50
        height: 50
        color: "transparent"
        border.color: "red"
        visible: false

        // Animation for emergency warning lights
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: emergencyWarning.visible
            NumberAnimation { from: 1; to: 0; duration: 0.5 }
            NumberAnimation { from: 0; to: 1; duration: 0.5 }
        }
    }

    // Function to update indicators
    function updateIndicators(left, right, lowFuel, emergency) {
        leftIndicator.visible = left;
        rightIndicator.visible = right;
        lowFuelWarning.visible = lowFuel;
        emergencyWarning.visible = emergency;
    }
}