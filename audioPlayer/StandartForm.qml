import QtQuick 2.0
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle{
    property var _width: 30
    property var _height: 20
    property var _color: "#696969"
    width: _width
    height: _height
    radius: (parent.height+parent.width)/90
    color: _color
}
