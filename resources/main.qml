import QtQuick 2.3
import QtQuick.Window 2.3

Window {
    id: myWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "lightgray"

    Text {
        id: helloText
        text: "Hello world!"
        anchors.left: parent.left
        anchors.top: parent.top
        font.pointSize: 24; 
        font.bold: true
    }

    MyButton {
        id: myButtonId
        anchors.top: helloText.bottom
    }

    MyToolbar {
        id: toolbar1
        anchors.top: myButtonId.bottom 
        width: parent.width
        _modificableText: "Overloaded text!"
    }

    MyToolbar {
        anchors.top: toolbar1.bottom 
        width: parent.width
        _modificableColor: "green"
    }
}
