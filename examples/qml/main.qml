import QtQuick 2.0

Item {
  anchors.fill: parent
  
  Text {
    Component.onCompleted: {
      text = FileSystemAPI.readFile("/etc/passwd");
    }
  }
}
