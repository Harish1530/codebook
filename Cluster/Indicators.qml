import QtQuick 2.15

Item {
    width: parent.width
    height: 60

    property bool engineWarning: false
    property bool serviceWarning: false
    property bool absWarning: false
    property bool leftIndicator: false
    property bool rightIndicator: false

    Row {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 40

        Rectangle {
            width: 40; height: 40
            color: leftIndicator ? "green" : "#202020"
            radius: 4
            Text { anchors.centerIn: parent; text: "←"; color: "white" }
        }

        Rectangle {
            width: 40; height: 40
            color: engineWarning ? "red" : "#202020"
            radius: 4
            Text { anchors.centerIn: parent; text: "ENG"; color: "white" }
        }

        Rectangle {
            width: 40; height: 40
            color: serviceWarning ? "yellow" : "#202020"
            radius: 4
            Text { anchors.centerIn: parent; text: "SRV"; color: "white" }
        }

        Rectangle {
            width: 40; height: 40
            color: absWarning ? "orange" : "#202020"
            radius: 4
            Text { anchors.centerIn: parent; text: "ABS"; color: "white" }
        }

        Rectangle {
            width: 40; height: 40
            color: rightIndicator ? "green" : "#202020"
            radius: 4
            Text { anchors.centerIn: parent; text: "→"; color: "white" }
        }
    }
}
