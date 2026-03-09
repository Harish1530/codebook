pragma Singleton
import QtQuick 2.15

QtObject {

    property bool darkMode: true

    property color backgroundTop: darkMode ? "#101820" : "#e8f0ff"
    property color backgroundBottom: darkMode ? "#040b14" : "#cfdfff"

    property color gaugeFace: darkMode ? "#040121" : "#f5f7fb"
    property color gaugeBorder: darkMode ? "black" : "#8899aa"

    property color primaryText: darkMode ? "white" : "#101010"
    property color secondaryText: darkMode ? "#9ccaff" : "#3b4b6b"

    property color accent: "#2aa7ff"

    property color needleLow: "#00ff66"
    property color needleMid: "yellow"
    property color needleHigh: "red"
}
