import QtQuick 2.0
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    id:_root
    width: 640
    height: 200
    visible: true
    title: qsTr("select path")

    Text{
        id:_infoText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top:parent.top
        anchors.topMargin: _root.width/50
        font.pointSize: (parent.width + parent.height)/50
        color: "#F5FFFA"
        text: qsTr("enter path to audio folder : ")
    }


    StandartForm{
        id:_inputPathForm
        _width: parent.width/1.1
        _height: parent.width/14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: _infoText.bottom
        anchors.topMargin: _root.width/50
        TextInput{
            id:_inputPath
            anchors.fill: parent
            anchors.top: parent.top
            anchors.margins:parent.width/70
            font.pointSize: (_root.width + _root.height)/50
            color: "#F5FFFA"
        }
    }

    StandartForm{
        id:_saveFolder
        _width: parent.width/4
        _height: parent.width/18
        _color:_saveFolderMouseArea.containsPress ? Qt.darker("#696969",1.2) : "#696969";
        anchors.left: _inputPathForm.left
        anchors.top: _inputPathForm.bottom
        anchors.topMargin: parent.width/70
        Text{
            anchors.centerIn: parent
            font.pointSize: (parent.width + parent.height)/12
            color: "#F5FFFA"
            text: qsTr("save folder")
        }
        MouseArea{
            id:_saveFolderMouseArea
            anchors.fill: parent
            onClicked: {
                audioWork.savePathToFolderForAudio(_inputPath.text);
                if(_inputPath.text != "" && _inputPath.text != " "){
                    //var component = Qt.createComponent("qrc:/main.qml");
                    //component.createObject();
                    close()
                    exited()
                }
            }
        }
    }
    /*
    Button{
        id:_scanButton
        width: parent.width/4
        height: parent.width/10
        anchors.left: _inputPath.left
        anchors.top: _inputPath.bottom
        anchors.topMargin: parent.width/70
        font.pointSize: (_root.width + _root.height)/100
        text: "scan"
        onClicked: {
            audioWork.savePathToFolderForAudio(_inputPath.text);
            if(_inputPath.text != "" && _inputPath.text != " "){
                var component = Qt.createComponent("qrc:/main.qml");
                component.createObject();
                close()
            }
        }
    }*/
}
