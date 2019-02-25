#include "aquariumswindow.h"
#include "ui_aquariumswindow.h"

AquariumsWindow::AquariumsWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AquariumsWindow)
{
    ui->setupUi(this);
}

void AquariumsWindow::takeData(QString user)
{
    ui->welcomeLabel->setText("Welcome back, <b>" + user + "</b>!");
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
