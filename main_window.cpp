#include "main_window.h"
#include "./ui_main_window.h"
#include <QMessageBox>
#include "add_divice_form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deviceModel = new DeviceListModel(this);
    ui->remDivListView->setModel(deviceModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addNewDiviceButton_clicked()
{
    std::unique_ptr<AddDiviceForm> dialogAddDivce;
    dialogAddDivce.reset(new AddDiviceForm(this));

    connect(dialogAddDivce.get(), &AddDiviceForm::deviceCreated, this, &MainWindow::addDeviceToList);

    dialogAddDivce->exec();
}

void MainWindow::addDeviceToList(const Device& device)
{
    deviceModel->addDevice(device);
}

