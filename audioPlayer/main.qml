import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 2.12

Window {
    id:_root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

   StandartForm{
       id:_pathToAudioForm
       _width:_root.width/1.1
       _height:_root.height/15
       _radius:4
       _borderSize:1
       anchors.left: parent.left
       anchors.top: parent.top
       anchors.margins: (_root.width+_root.height)/30
       TextInput{
           id:_pathToAudio
           anchors.fill: parent
           anchors.centerIn: parent
           horizontalAlignment: TextInput.AlignHCenter
           font.pointSize: (_root.width+_root.height)/70
       }
   }
   ListView{
       id:_view
       width:_root.width/2
       height: _root.height/2
       anchors.top:_pathToAudioForm.bottom
       anchors.topMargin: (_root.width+_root.height)/100
       spacing: 5
       model: appEngine.listAudio
       delegate: Button{
           width:_root.width
           height: _root.height/10
           Text{
                 text:modelData
                 anchors.centerIn: parent
                 font.pointSize: (_root.width+_root.height)/80
           }
       }
   }
   Button{
       width:_root.width/10
       height: _root.height/10
       anchors.bottom: parent.bottom
       anchors.left: parent.left
       text: "click me"
       onClicked: {
           appEngine.showAllAudio(_pathToAudio.text);
       }
   }
}
