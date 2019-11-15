import QtQuick 2.3
import QtTest 1.0 
//sudo apt-get install qtdeclarative5-test-plugin 

Rectangle {
    property string _modificableText: "Hell Yeah!"
    property color _modificableColor: "blue"

    width: parent.width
    height: 50
    color: _modificableColor

    Text
    {
        text: _modificableText
        color: "yellow"
        font.pointSize: 20
        anchors.fill: parent
        width: parent.width
}
}


