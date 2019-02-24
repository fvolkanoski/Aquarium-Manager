#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QMainWindow>

#include "dbmanager.h"

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

private:
    Ui::UsersWindow *ui;
};

#endif // USERSWINDOW_H
