#include "registerdialog.h"
#include "ui_registerdialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) : QDialog(parent), ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_cancelButton_clicked()
{
    RegisterDialog::close();
}

/*
 * When the user clicks the Register, we call the dbmanager
 * to insert a new user into the database.
*/
void RegisterDialog::on_registerButton_clicked()
{
    // If the fields are blank, do nothing.
    if(ui->registerUserEdit->text().size() > 0 && ui->registerPasswordEdit->text().size() > 0)
    {
        DbManager dbManager;

        // Hash the password using sha256, and write the hash to the db.
        // TODO: How do we prevent SQL injection, regex or what...?
        if(dbManager.insertUser(ui->registerUserEdit->text(), QString(QCryptographicHash::hash((ui->registerPasswordEdit->text().toLocal8Bit()),QCryptographicHash::Sha256))))
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
