#include "aquariumswindow.h"
#include "ui_aquariumswindow.h"

AquariumsWindow::AquariumsWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AquariumsWindow)
{
    ui->setupUi(this);
    QMessageBox userHelloMessage;
    userHelloMessage.setText("Welcome back!");
    userHelloMessage.setIcon(QMessageBox::Icon::Information);
    userHelloMessage.exec();
}

void AquariumsWindow::takeData(QString user)
{
    ui->welcomeLabel->setText("Welcome back, <b>" + user + "</b>!");
}

AquariumsWindow::~AquariumsWindow()
{
    delete ui;
}
