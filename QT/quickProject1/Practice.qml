import QtQuick 2.15

Window{
    width: 640
    height: 480
    visible: true
    title: qsTr("My Practice Code")

    property string textToShow: "hello"


    Row{
        anchors.centerIn: parent
        spacing: 20

        Rectangle{
            id:redRect
            width: 100
            height: 100
            color: "red"
            border.color: "black"
            border.width: 4
            radius: 10
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on red")
                    textToShow = "red"
                }
            }
        }


    }
}
