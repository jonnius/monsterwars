/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2015 Simon Stuerz <stuerz.simon@gmail.com>               *
 *                                                                         *
 *  This file is part of Monster Wars.                                     *
 *                                                                         *
 *  Monster Wars is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, version 3 of the License.                *
 *                                                                         *
 *  Monster Wars is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with Monster Wars. If not, see <http://www.gnu.org/licenses/>.   *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

import QtQuick 2.7
import MonsterWars 1.0

Item{
    id: root
    property string menuTitle
    signal closeClicked()

    Rectangle {
        id: toolBar
        anchors.fill: parent
        color: "black"

        Text {
            text: menuTitle
            color: "white"
            font.bold: true
            font.pixelSize: root.height * 3 / 4
            anchors {
                left: parent.left
                leftMargin: root.height / 2
                horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: exitRectangle
            anchors {
                right: toolBar.right
                rightMargin: root.height  / 2
                verticalCenter: toolBar.verticalCenter
            }

            height: toolBar.height
            width: height

            color: "transparent"
            radius: 1

            Image {
                id: closeIcon
                anchors.fill: parent
                anchors.margins: root.height / 6
                source: "file:" + dataDirectory + "/images/close-white.png"
            }

            MouseArea {
                anchors.fill: exitRectangle
                onClicked: {
                    pageStack.pop()
                    closeClicked()
                }
            }
        }
    }
}
