import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.0
import Basics.QmlController 1.0

Window
{
    id: mainWindow
    visible: true
    width: 250
    height: 350
    title: qsTr("Aquarium Manager")
    flags: Qt.Window | Qt.FramelessWindowHint
    color: "transparent"

    QmlController
    {
        id: qmlCtrl
    }

    Rectangle
    {
        anchors.fill: parent
        z: -1
        radius: 15

        gradient: Gradient
        {
            GradientStop {position: 0.0;color: "#97799F";}
            GradientStop {position: 1;color: "#54516F";}
        }
    }

    SwipeView
    {
        property string loggedInName: ""

        id: mainWindowView
        anchors.fill: parent
        currentIndex: 1
        interactive: false

        Item
        {
            id: loggedInPage

            Text
            {
                id: nameText
                x: parent.width - ((5 * text.length) + 5)
                y: 5
                text: mainWindowView.loggedInName
            }
        }

        Item
        {
            id: loginPage

            Image
            {
                id: logoLogin
                width: 70
                height: 70
                anchors.horizontalCenter: parent.horizontalCenter
                y: 30
                source: "qrc:///res/lock.png"
                mipmap: true
            }


            ColumnLayout
            {
                x: 5
                anchors.verticalCenter: parent.verticalCenter
                spacing: 15

                ColumnLayout
                {
                    TextInput
                    {
                        id: usernameInputLogin
                        text: ""
                        Layout.preferredWidth: mainWindow.width - 60
                        font.family: "Calibri"
                        font.pointSize: 10
                        color: "white"
                        padding: 0.5
                        topPadding: 4
                        leftPadding: 4

                        Rectangle
                        {
                            height: parent.height + 5
                            width: parent.width - 30
                            anchors.horizontalCenter: mainWindow.horizontalCenter
                            z: -1
                            color: "transparent"
                            border.width: 1
                            border.color: "white"
                        }

                        Text
                        {
                            text: "Enter your username."
                            color: "white"
                            visible: !usernameInputLogin.text
                            anchors.horizontalCenter: mainWindow.horizontalCenter
                            font.family: "Calibri"
                            font.pointSize: 10
                            topPadding: 4
                            leftPadding: 4
                        }
                    }
                }

                ColumnLayout
                {

                    TextInput
                    {
                        id: passwordInputLogin
                        text: ""
                        Layout.preferredWidth: mainWindow.width - 10
                        font.family: "Calibri"
                        font.pointSize: 10
                        color: "white"
                        padding: 0.5
                        topPadding: 4
                        leftPadding: 4
                        echoMode: TextInput.Password;

                        Rectangle
                        {
                            height: parent.height + 5
                            width: parent.width
                            z: -1
                            color: "transparent"
                            border.width: 1
                            border.color: "white"
                        }

                        Text
                        {
                            text: "Enter your password."
                            color: "white"
                            visible: !passwordInputLogin.text
                            font.family: "Calibri"
                            font.pointSize: 10
                            topPadding: 4
                            leftPadding: 4
                        }
                    }
                }
            }

            Button
            {
                id: loginButton
                anchors.horizontalCenter: parent.horizontalCenter
                y: mainWindow.height - 70
                text: "Login"
                onClicked:
                {
                    if(qmlCtrl.loginUser(usernameInputLogin.text, passwordInputLogin.text))
                    {
                        mainWindowView.currentIndex = 0
                        mainWindowView.loggedInName = "Welcome back, " + qmlCtrl.returnLoggedInName() + "!"
                    }
                }
            }

            Text
            {
                id: registerText
                text: "No account? Register here!"
                color: "white"
                anchors.horizontalCenter: parent.horizontalCenter
                y: mainWindow.height - 20

                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        mainWindowView.currentIndex = 2
                    }
                }
            }
        }
        Item
        {
            id: registerPage

            ColumnLayout
            {
                x: 5
                anchors.verticalCenter: parent.verticalCenter
                spacing: 15

                ColumnLayout
                {
                    Text
                    {
                        id: nameInputTextRegister
                        text: qsTr("Name: ")
                        font.family: "Calibri"
                        font.pointSize: 10
                    }

                    TextInput
                    {
                        id: nameInputRegister
                        text: ""
                        Layout.preferredWidth: mainWindow.width - 10
                        font.family: "Calibri"
                        font.pointSize: 11

                        Rectangle
                        {
                            height: parent.height
                            width: mainWindow.width - 10
                            z: -1

                            CustomBorder
                            {
                                commonBorder: false
                                lBorderwidth: 0
                                rBorderwidth: 0
                                tBorderwidth: 0
                                bBorderwidth: 1
                                borderColor: "black"
                            }
                        }

                        Text
                        {
                            text: "Enter your name."
                            color: "#aaa"
                            visible: !nameInputRegister.text
                            font.family: "Calibri"
                            font.pointSize: 11
                        }
                    }
                }

                ColumnLayout
                {
                    Text
                    {
                        id: usernameInputTextRegister
                        text: qsTr("Username: ")
                        font.family: "Calibri"
                        font.pointSize: 10
                    }

                    TextInput
                    {
                        id: usernameInputRegister
                        text: ""
                        Layout.preferredWidth: mainWindow.width - 10
                        font.family: "Calibri"
                        font.pointSize: 11

                        Rectangle
                        {
                            height: parent.height
                            width: mainWindow.width - 10
                            z: -1

                            CustomBorder
                            {
                                commonBorder: false
                                lBorderwidth: 0
                                rBorderwidth: 0
                                tBorderwidth: 0
                                bBorderwidth: 1
                                borderColor: "black"
                            }
                        }

                        Text
                        {
                            text: "Enter your username."
                            color: "#aaa"
                            visible: !usernameInputRegister.text
                            font.family: "Calibri"
                            font.pointSize: 11
                        }
                    }
                }

                ColumnLayout
                {
                    Text
                    {
                        id: passwordInputTextRegister
                        text: qsTr("Password: ")
                        font.family: "Calibri"
                        font.pointSize: 10
                    }

                    TextInput
                    {
                        id: passwordInputRegister
                        text: ""
                        Layout.preferredWidth: mainWindow.width - 10
                        font.family: "Calibri"
                        font.pointSize: 11
                        echoMode: TextInput.Password;

                        Rectangle
                        {
                            height: parent.height
                            width: mainWindow.width - 10
                            z: -1

                            CustomBorder
                            {
                                commonBorder: false
                                lBorderwidth: 0
                                rBorderwidth: 0
                                tBorderwidth: 0
                                bBorderwidth: 1
                                borderColor: "black"
                            }
                        }

                        Text
                        {
                            text: "Enter your password."
                            color: "#aaa"
                            visible: !passwordInputRegister.text
                            font.family: "Calibri"
                            font.pointSize: 11
                        }
                    }
                }
            }

            Popup
            {
                property string popupText: ""

                id: registerPopup
                x: (parent.width / 2) - 100
                y: (parent.height / 2) - 65
                width: 200
                height: 130
                modal: true
                focus: true
                closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

                Text
                {
                    id: registerPopupText
                    text: registerPopup.popupText
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: parent.y + 10
                }

                Button
                {
                    id: registerPopupButton
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: parent.height - 40
                    text: "Ok"
                    onClicked: registerPopup.close()
                }
            }

            Button
            {
                id: registerButton
                anchors.horizontalCenter: parent.horizontalCenter
                y: mainWindow.height - 70
                text: "Register"
                onClicked:
                {
                    if(qmlCtrl.registerUser(nameInputRegister.text,
                                            usernameInputRegister.text,
                                            passwordInputRegister.text))
                    {
                        nameInputRegister.text = ""
                        usernameInputRegister.text = ""
                        passwordInputRegister.text = ""

                        registerPopup.popupText = "Registered successfully!"
                        registerPopup.open()
                    }
                    else
                    {
                        registerPopup.popupText = "Error! Please try again later."
                        registerPopup.open()
                    }

                }
            }

            Text
            {
                id: loginText
                text: "Already have an account? Login here!"
                color: "#006691"
                anchors.horizontalCenter: parent.horizontalCenter
                y: mainWindow.height - 20

                MouseArea
                {
                    anchors.fill: parent

                    onClicked:
                    {
                        mainWindowView.currentIndex = 1
                    }
                }
            }
        }
    }
}
