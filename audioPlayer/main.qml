import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//My
import audioM 1.0;

Window {
    id:_root
    width: 640
    height: 340
    visible: true
    title: qsTr("самый лучший плеер")

    Text{
        id:_nameMusic
        anchors.left:parent.left
        anchors.top: parent.top
        anchors.margins:parent.width/50
        wrapMode: Text.Wrap
        width: parent.width/2.5 + parent.width/10
        font.pointSize: (parent.width + parent.height)/70
        text: qsTr("")
        Connections{
            target: audioWork
            function onChangeNameAudio (nameAudio){
                _nameMusic.text = nameAudio

            }
        }
    }

    /*
    Image{
        id:_plate
        source: "qrc:/plate.png"
        width:  parent.width/3
        height:  parent.width/3
        anchors.top:_nameMusic.bottom
        anchors.left: parent.left
        anchors.margins:parent.width/10
    }
    */

    //pause
    StandartForm{
        id:_pause
        _width: parent.width/10
        _height: parent.width/10
        _color:_pauseMouseArea.containsPress ? Qt.darker("#696969",1.2) : "#696969";
        anchors.left: parent.left
        anchors.top: _nameMusic.bottom
        //anchors.margins:parent.width/50
        anchors.leftMargin: _volumeSlider.width/7
        anchors.topMargin: parent.width/50
        Text{
            anchors.centerIn: parent
            font.pointSize: (parent.width + parent.height)/5
            color: "#F5FFFA"
            text: qsTr(">")
        }
        MouseArea{
            id:_pauseMouseArea
            anchors.fill: parent
            onClicked: {
                audioWork.pause();
            }
        }
    }

    //next audio
    StandartForm{
        id:_nextButton
        _width: parent.width/10
        _height: parent.width/10
        _color:_nextButtonMouseArea.containsPress ? Qt.darker("#696969",1.2) :"#696969";
        anchors.left: _previousButton.right
        anchors.top: _nameMusic.bottom
        anchors.margins:parent.width/50
        Text{
            anchors.centerIn: parent
            font.pointSize: (parent.width + parent.height)/5
            color: "#F5FFFA"
            text: qsTr(">>")
        }
        MouseArea{
            id:_nextButtonMouseArea
            anchors.fill: parent
            onClicked: {
                audioWork.next();
            }
        }
    }

    //previous audio
    StandartForm{
        id:_previousButton
        _width: parent.width/10
        _height: parent.width/10
        _color:_previousButtonMouseArea.containsPress ? Qt.darker("#696969",1.2) : "#696969";
        anchors.left: _pause.right
        anchors.top: _nameMusic.bottom
        anchors.margins:parent.width/50
        Text{
            anchors.centerIn: parent
            font.pointSize: (parent.width + parent.height)/5
            color: "#F5FFFA"
            text: qsTr("<<")
        }
        MouseArea{
            id:_previousButtonMouseArea
            anchors.fill: parent
            onClicked: {
                audioWork.previous();
            }
        }
    }

    Slider{
        id:_volumeSlider
        width: parent.width/2
        height: parent.width/10
        anchors.left: parent.left
        anchors.top: _pause.bottom
        anchors.topMargin: (parent.width + parent.height)/40
        //anchors.margins: parent.width/50
        from:0
        to:100
        value: 50
        stepSize: 1
        onPositionChanged: {
            audioWork.editVolume(value);
        }
        Text{
            anchors.top: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: (_root.width + _root.height)/70
            text: qsTr("volume")
        }
    }

    Slider{
        id:_positionSlider
        width: parent.width/2
        height: parent.width/10
        anchors.left: parent.left
        anchors.top: _volumeSlider.bottom
        anchors.topMargin: (parent.width + parent.height)/25
        //anchors.margins: parent.width/50
        from:0
        to:30000
        value: 0
        stepSize: 1
        Text{
            anchors.top: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: (_root.width + _root.height)/70
            text: qsTr("position music")
        }
        Timer{
            interval: 1000
            repeat: true
            running: true
            onTriggered: {
                audioWork.signalTimerPositionMusic();
            }
        }
        Connections{
            target: audioWork
            //onChangePositionMusic:_positionSlider.value = position
            function onChangePositionMusic(position) {
                _positionSlider.value = position
            }

            function onChangeDurationAudioSlider(max) {
                _positionSlider.to = max
            }
        }
    }

    ListView{
        id:_audioList
        clip: true

        width: parent.width/2.5
        height: parent.height
        anchors.top:parent.top
        anchors.right: parent.right
        anchors.margins:parent.width/50

        ScrollBar.vertical: ScrollBar{}
        spacing: 3

        model:AudioModel{
            list: audioWork
        }
        delegate:StandartForm{
            id:_playAudioButton
            property var _pathToAudio: model.audioPath
            _width: _audioList.width+1
            _height: _root.height/15
            _color:_playAudioButtonButtonMouseArea.containsPress ? Qt.darker("#696969",1.2) : "#696969";
            Text{
                anchors.centerIn: parent
                font.pointSize: (parent.width + parent.height)/20
                color: "#F5FFFA"
                text: model.audioName
            }
            MouseArea{
                id:_playAudioButtonButtonMouseArea
                anchors.fill: parent
                onClicked: {
                    audioWork.playAudio(_pathToAudio);
                    _nameMusic.text = model.audioName
                }
            }
        }

        /*Button{
            id:_playAudioButton
            property var _pathToAudio: model.audioPath
            width: _audioList.width
            font.pointSize: (_root.width + _root.height)/80
            text: model.audioName
            onClicked: {
                audioWork.playAudio(_pathToAudio);

            }*/
    }

}

