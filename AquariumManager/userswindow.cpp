#include "userswindow.h"
#include "ui_userswindow.h"

UsersWindow::UsersWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::UsersWindow)
{
    ui->setupUi(this);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
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
    std::pair <bool, User> currentUser = dbManager.getUserInfo(ui->userInputEdit->text());


    if(currentUser.first) // User has been found.
    {
        if(currentUser.second.password == QString(QCryptographicHash::hash((ui->passwordInputEdit->text().toLocal8Bit()), QCryptographicHash::Sha256))) // User and password is correct, we can log in.
        {
            aquariumsWindow = new AquariumsWindow();
            aquariumsWindow->show();
            aquariumsWindow->takeData(currentUser.second);
            UsersWindow::close();
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
    ui->stackedWidget->setCurrentIndex(1);
}

void UsersWindow::on_registerLink_2_linkActivated(const QString &link)
{
    ui->stackedWidget->setCurrentIndex(0);
}

/*
 * When the user clicks the Register, we call the dbmanager
 * to insert a new user into the database.
*/
void UsersWindow::on_registerButton_clicked()
{
    // If the fields are blank, do nothing.
    if(ui->registerUserEdit->text().size() > 0 && ui->registerPasswordEdit->text().size() > 0 && ui->registerNameEdit->text().size() > 0)
    {
        DbManager dbManager;

        // Hash the password using sha256, and write the hash to the db.
        // TODO: How do we prevent SQL injection, regex or what...?
        if(dbManager.insertUser(ui->registerNameEdit->text(), ui->registerUserEdit->text(), QString(QCryptographicHash::hash((ui->registerPasswordEdit->text().toLocal8Bit()),QCryptographicHash::Sha256))))
        {
            QMessageBox registerInfoBox;
            registerInfoBox.setText("User registered successfully!");
            registerInfoBox.setIcon(QMessageBox::Icon::Information);
            registerInfoBox.exec();
        }
        else
        {
            QMessageBox registerInfoBox;
            registerInfoBox.setText("Error while registering user, please try again later.");
            registerInfoBox.setIcon(QMessageBox::Icon::Critical);
            registerInfoBox.exec();
        }
    }
}
