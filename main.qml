import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.2
import IVIControls 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 480

    Rectangle {
        anchors.fill: parent
        color: "#303030"
    }

    DialItem {
        id: speed
        objectName: "speed"
        width: 350
        height: width
        anchors.centerIn: parent
        startAngle: 30
        spanAngle: 300
        dialWidth: 4
        dialColor: "#4646FF"

        Image {
            id: needle
            source: "qrc:/needle.png"
            anchors.centerIn: parent
            rotation: 39 + 30 + slider.value
            Behavior on rotation { SpringAnimation { spring: 2; damping: 0.2 } }
        }
    }

    Slider {
        id: slider
        anchors.top: speed.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: 400
        minimumValue: 0
        maximumValue: 300
    }
}
