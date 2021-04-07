import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
//My
import audioM 1.0;


ListView{
    clip: true
    model:AudioModel{
        list: audioWork
    }
    delegate:RowLayout{
        Button{
            id:_playAudioButton
            property var _pathToAudio: model.audioPath
            width: parent.width
            text: model.audioName
            onClicked: {
                audioWork.playAudio(_pathToAudio);
            }
        }
    }

}
