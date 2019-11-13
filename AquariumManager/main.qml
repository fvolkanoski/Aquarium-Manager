import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import Basics.QmlController 1.0

Window
{
    id: mainWindow
    visible: true
    width: 320
    height: 657
    title: qsTr("Aquarium Manager")

    QmlController
    {
        id: qmlCtrl
    }

    SwipeView
    {
        id: mainWindowView
        anchors.fill: parent
        currentIndex: 1
        interactive: false

        Item
        {
            id: loggedInPage
        }

        Item
        {
            id: loginPage

            Image
            {
                id: logoImageLogin
                width: 250
                height: 120
                anchors.horizontalCenter: parent.horizontalCenter
                y: 10
                source: "qrc:///res/logo.png"
                mipmap: true
            }

            ColumnLayout
            {
                x: 5
                anchors.verticalCenter: parent.verticalCenter
                spacing: 15

                ColumnLayout
                {
                    RowLayout
                    {
                        Image
                        {
                            id: usernameLogoLogin
                            Layout.preferredHeight: 16
                            Layout.preferredWidth: 16
                            source: "qrc:///res/man-user.png"
                        }
                        Text
                        {
                            id: usernameInputTextLogin
                            text: qsTr("Username: ")
                            font.family: "Calibri"
                            font.pointSize: 10
                        }
                    }


                    TextInput
                    {
                        id: usernameInputLogin
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
                            visible: !usernameInputLogin.text
                            font.family: "Calibri"
                            font.pointSize: 11
                        }
                    }
                }

                ColumnLayout
                {
                    RowLayout
                    {
                        Image
                        {
                            id: passwordLogoLogin
                            Layout.preferredHeight: 16
                            Layout.preferredWidth: 16
                            source: "qrc:///res/lock.png"
                        }
                        Text
                        {
                            id: passwordInputTextLogin
                            text: qsTr("Password: ")
                            font.family: "Calibri"
                            font.pointSize: 10
                        }
                    }


                    TextInput
                    {
                        id: passwordInputLogin
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
                            visible: !passwordInputLogin.text
                            font.family: "Calibri"
                            font.pointSize: 11
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
                    }
                }
            }

            Text
            {
                id: registerText
                text: "No account? Register here!"
                color: "#006691"
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

            Image
            {
                id: logoImageRegister
                width: 250
                height: 120
                anchors.horizontalCenter: parent.horizontalCenter
                y: 10
                source: "qrc:///res/logo.png"
                mipmap: true
            }

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

            Button
            {
                id: registerButton
                anchors.horizontalCenter: parent.horizontalCenter
                y: mainWindow.height - 70
                text: "Register"
                onClicked: qmlCtrl.registerUser(nameInputRegister.text, usernameInputRegister.text, passwordInputRegister.text)
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
