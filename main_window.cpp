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

    connect(ui->addNewDiviceButton, &QPushButton::clicked, this, &MainWindow::onAddNewDiviceButtonClicked);
    connect(ui->editDiviceButton, &QPushButton::clicked, this, &MainWindow::onEditDiviceButtonClicked);
    connect(ui->deleteDiviceButton, &QPushButton::clicked, this, &MainWindow::onDeleteDiviceButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddNewDiviceButtonClicked()
{
    std::unique_ptr<AddDiviceForm> dialogAddDivce;
    dialogAddDivce.reset(new AddDiviceForm(this));

    connect(dialogAddDivce.get(), &AddDiviceForm::deviceCreated, this, &MainWindow::addDeviceToList);

    dialogAddDivce->exec();
}

void MainWindow::onEditDiviceButtonClicked()
{

}

void MainWindow::onDeleteDiviceButtonClicked()
{

}

void MainWindow::addDeviceToList(const Device& device)
{
    deviceModel->addDevice(device);
}

