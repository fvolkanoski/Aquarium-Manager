#ifndef AQUARIUMSWINDOW_H
#define AQUARIUMSWINDOW_H

//Qt includes
#include <QMainWindow>
#include <QMessageBox>

// Project includes
#include "dbmanager.h"

namespace Ui
{
    class AquariumsWindow;
}

class AquariumsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AquariumsWindow(QWidget *parent = nullptr);
    void takeData(User user);
    ~AquariumsWindow();

private:
    Ui::AquariumsWindow *ui;
};

#endif // AQUARIUMSWINDOW_H
