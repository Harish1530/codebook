import QtQuick 2.15

Item {

    id: root

    property real currentSpeed: 0
    property real maxSpeed: 240

    function updateSpeed(value) {
        currentSpeed = value
    }

    width: 360
    height: 360

    Rectangle {
        anchors.fill: parent
        radius: width / 2
        color: "#050540"
        border.color: "white"
        border.width: 2
    }

    //---------------------------------
    // SPEED NEEDLE
    //---------------------------------

    Rectangle {

        id: needle

        width: 4
        height: parent.height * 0.42

        color: "lime"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        transformOrigin: Item.Bottom

        rotation: -120 + (root.currentSpeed / root.maxSpeed) * 240

        Behavior on rotation {
            NumberAnimation {
                duration: 200
                easing.type: Easing.InOutQuad
            }
        }
    }

    //---------------------------------
    // CENTER HUB
    //---------------------------------

    Rectangle {
        width: 20
        height: 20
        radius: 10
        color: "white"
        anchors.centerIn: parent
    }

    //---------------------------------
    // SPEED TEXT
    //---------------------------------

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 40

        text: Math.round(root.currentSpeed) + " km/h"

        color: "white"
        font.pixelSize: 22
        font.family: "Ubuntu"
    }
}
