#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QMainWindow>

#include "dbmanager.h"
#include "aquariumswindow.h"
#include "registerdialog.h"

namespace Ui
{
    class UsersWindow;
}

class UsersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsersWindow(QWidget *parent = nullptr);
    ~UsersWindow();

private slots:
    void on_loginButton_clicked();
    void on_registerLink_linkActivated(const QString &link);

private:
    Ui::UsersWindow *ui;
    AquariumsWindow *aquariumsWindow;
    RegisterDialog *registerDialog;
};

#endif // USERSWINDOW_H
