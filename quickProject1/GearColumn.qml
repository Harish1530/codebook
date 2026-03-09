import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: gearIndicator
    property int currentGear: 0     // -1 = R, 0 = N, 1..6 gears
    property int maxGears: 6
    property int columnWidth: 60
    property color activeColor: "#00ff66"
    property color inactiveColor: "#222222"
    property color textColor: "white"

    width: columnWidth
    height: (maxGears + 2) * 34

    Column {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 6
        Repeater {
            model: maxGears + 2   // show "R", "N" and gears 1..max
            delegate: Rectangle {
                width: gearIndicator.columnWidth - 8
                height: 28
                radius: 4
                color: {
                    var idx = index - 1  // index 0 -> R, 1 -> N, 2.. -> gear1..
                    var gearVal = (idx < 0 ? -1 : (idx==0 ? 0 : idx))
                    return gearVal === gearIndicator.currentGear ? activeColor : inactiveColor
                }
                border.color: "#444"
                Text {
                    anchors.centerIn: parent
                    color: textColor
                    font.bold: true
                    font.pixelSize: 14
                    text: {
                        var idx = index - 1
                        if (idx < 0) return "R"
                        if (idx == 0) return "N"
                        return idx.toString()
                    }
                }
            }
        }
    }
}
