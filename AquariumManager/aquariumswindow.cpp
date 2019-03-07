#include "aquariumswindow.h"
#include "ui_aquariumswindow.h"

AquariumsWindow::AquariumsWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AquariumsWindow)
{
    ui->setupUi(this);
}

/*
 * After the initialization of the form, this is the first function that
 * is called.
*/
void AquariumsWindow::takeData(QString user)
{
    ui->welcomeLabel->setText("Welcome back, <b>" + user + "</b>!");
    // Get aquariums data.
}

AquariumsWindow::~AquariumsWindow()
{
    delete ui;
}

/*
 * When the user clicks the logout button, add here the actions
 * that need to be done before logging out then destroy the main window.
*/
void AquariumsWindow::on_label_linkActivated(const QString &link)
{
    QApplication::quit();
}

void AquariumsWindow::on_aquariumsTabs_tabBarClicked(int index)
{
    // Get info about aquarium when the user selects it.
}
