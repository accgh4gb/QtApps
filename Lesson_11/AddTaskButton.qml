import QtQuick 2.0

BorderImage {
    property alias text: _addButton.text
    signal clicked
    source: "qrc:/img/img/release.png"
    width: 763
    height: 300
    Text
    {
        id: _addButton
        color: "black"
        anchors.centerIn: parent
    }
    MouseArea
    {
        anchors.fill: parent
        onClicked: parent.clicked()
        onPressed: {parent.source = "qrc:/img/img/press.png"}
        onReleased: {parent.source = "qrc:/img/img/release.png"}
    }
}
