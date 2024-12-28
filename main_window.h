#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "device_list_model.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DeviceListModel* deviceModel;

    void addDeviceToList(const Device& device);

private slots:
    void onAddNewDiviceButtonClicked();
    void onEditDiviceButtonClicked();
    void onDeleteDiviceButtonClicked();
};
#endif // MAIN_WINDOW_H
