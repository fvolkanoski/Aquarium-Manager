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
    void takeData(QString user);
    ~AquariumsWindow();

private slots:
    void on_label_linkActivated(const QString &link);

    void on_aquariumsTabs_tabBarClicked(int index);

private:
    Ui::AquariumsWindow *ui;
};

#endif // AQUARIUMSWINDOW_H
