import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import Tasks 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Органайзер")

    Tasks
    {
        id: _tasks
    }
    AddTaskButton
    {
        id: buttonQuit
        height: 30
        width: buttonQuit.height*763/300
        text: qsTr("Выход")
        onClicked: Qt.quit()
    }
    Text
    {
        x: addButton.width
        id: t1
        width: (window.width-addButton.width)/3
        height: addButton.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignBottom
        text: qsTr("название задачи")
    }
    Text
    {
        anchors.left: t1.right
        id: t2
        width: (window.width-addButton.width)/3
        height: addButton.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignBottom
        text: qsTr("дата окончания")
    }
    Text
    {
        anchors.left: t2.right
        id: t3
        width: (window.width-addButton.width)/3
        height: addButton.height
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignBottom
        text: qsTr("текущий прогресс")
    }
    AddTaskButton
    {
        y: 30
        height: 30
        width: addButton.height*763/300
        id: addButton
        text: qsTr("Добавить")
        onClicked: _tasks.addTask(tf1.text + " - " + tf2.text + " - " + tf3.text)
    }
    TextField
    {
        anchors.top: addButton.top
        anchors.left: addButton.right
        id: tf1
        width: (window.width-addButton.width)/3
        height: addButton.height
        placeholderText: qsTr("введите название")
    }
    TextField
    {
        anchors.top: tf1.top
        anchors.left: tf1.right
        id: tf2
        width: (window.width-addButton.width)/3
        height: addButton.height
        placeholderText: qsTr("дд.мм.гггг")
        validator: RegExpValidator { regExp:  /([0]{1}[1-9]{1}|[1-2]{1}[0-9]{1}|[3]{1}[0-1]{1})\.([0]{1}[1-9]{1}|[1]{1}[0-2]{1})\.[0-9]{4}/ }
//        inputMask: "99.99.9999"
//        inputMethodHints: Qt.ImhDigitsOnly
//        validator: Qt.ImhDate
    }
    TextField
    {
        anchors.top: tf2.top
        anchors.left: tf2.right
        id: tf3
        width: (window.width-addButton.width)/3
        height: addButton.height
        placeholderText: qsTr("0 - 10")
        validator: RegExpValidator { regExp:  /[0-9]{1}|[1]{1}[0]{1}/ }
    }
}
