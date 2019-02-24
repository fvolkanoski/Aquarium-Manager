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

AquariumsWindow::~AquariumsWindow()
{
    delete ui;
}
