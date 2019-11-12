#ifndef USERSWINDOW_H
#define USERSWINDOW_H

// Qt includes.
#include <QMainWindow>
#include <QCryptographicHash>

// Project includes.
#include "dbmanager.h"
#include "aquariumswindow.h"

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

    void on_registerLink_2_linkActivated(const QString &link);

    void on_registerButton_clicked();

private:
    Ui::UsersWindow *ui;
    AquariumsWindow *aquariumsWindow;
};

#endif // USERSWINDOW_H
