#include "userswindow.h"
#include "ui_userswindow.h"

UsersWindow::UsersWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::UsersWindow)
{
    ui->setupUi(this);
}

UsersWindow::~UsersWindow()
{
    delete ui;
}

/*
 * When the user clicks the login button we call the get user info function
 * and if we get user data from it we can check whether the user has inputted
 * correct credentials and we can log him in, if not we can display an error message.
 * TODO: Finish all of it, this is only for testing purposes.
*/
void UsersWindow::on_loginButton_clicked()
{
    DbManager dbManager;
    std::pair <bool, std::pair<QString, QString>> currentUser = dbManager.getUserInfo(ui->userInputEdit->text());


    if(currentUser.first) // User has been found.
    {
        if(currentUser.second.second == ui->passwordInputEdit->text()) // User and password is correct, we can log in.
        {
            aquariumsWindow = new AquariumsWindow();
            aquariumsWindow->show();
        }
        else
        {
            // Display an error message about invalid password.
            QMessageBox passwordErrorMessage;
            passwordErrorMessage.setText("Invalid password.");
            passwordErrorMessage.setIcon(QMessageBox::Icon::Critical);
            passwordErrorMessage.exec();
        }
    }
    else
    {
        // Display an error message about invalid user.
        QMessageBox userErrorMessage;
        userErrorMessage.setText("User not found.");
        userErrorMessage.setIcon(QMessageBox::Icon::Critical);
        userErrorMessage.exec();
    }
}

/*
 * When the user clicks the link, it displays the register new user window.
*/
void UsersWindow::on_registerLink_linkActivated(const QString &link)
{
    registerDialog = new RegisterDialog();
    registerDialog->show();
}
