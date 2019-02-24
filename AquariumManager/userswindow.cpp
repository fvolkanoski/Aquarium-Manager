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

    if(dbManager.getUserInfo(ui->userInputEdit->text()).first)
    {
        qDebug() << "Will log in.";
    }
    else
    {
        qDebug() << "User does not exist.";
    }
}
