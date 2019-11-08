import QtQuick 2.3

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


