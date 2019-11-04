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
    ui->lbl_welcomeText->setText("Welcome back, <b>" + user + "</b>!");

    // TODO: Get aquariums data.
}

AquariumsWindow::~AquariumsWindow()
{
    delete ui;
}
