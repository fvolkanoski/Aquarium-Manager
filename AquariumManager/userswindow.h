#ifndef USERSWINDOW_H
#define USERSWINDOW_H

#include <QMainWindow>

namespace Ui {
class UsersWindow;
}

class UsersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsersWindow(QWidget *parent = nullptr);
    ~UsersWindow();

private:
    Ui::UsersWindow *ui;
};

#endif // USERSWINDOW_H
