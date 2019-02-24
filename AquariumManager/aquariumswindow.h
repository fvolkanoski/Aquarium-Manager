#ifndef AQUARIUMSWINDOW_H
#define AQUARIUMSWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui
{
    class AquariumsWindow;
}

class AquariumsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AquariumsWindow(QWidget *parent = nullptr);
    ~AquariumsWindow();

private:
    Ui::AquariumsWindow *ui;
};

#endif // AQUARIUMSWINDOW_H
