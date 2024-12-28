#include "add_divice_form.h"
#include "ui_add_divice_form.h"
#include "QMessageBox"

AddDiviceForm::AddDiviceForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_divice_form)
{
    ui->setupUi(this);
    setupCommandTable();
    fillParitySettingCombo();
}

AddDiviceForm::~AddDiviceForm()
{
    delete ui;
}

void AddDiviceForm::on_cancelButton_clicked()
{
    close();
}

void AddDiviceForm::on_addDiviceButton_clicked()
{
    bool ok;
    int baud = ui->speedTransEdit->text().toInt(&ok);
    if(!ok)
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa prędkość transmisji");
        return;
    }

    int bits = ui->bitEdit->text().toInt(&ok);
    if(!ok || (bits != 7 && bits != 8))
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa liczba bitów danych");
        return;
    }

    Device::Parity parity;
    QString parityText = ui->parityCombo->currentText();
    if(parityText == "brak")
        parity = Device::Parity::None;
    else if(parityText == "parzysta")
        parity = Device::Parity::Even;
    else if(parityText == "nieparzysta")
        parity = Device::Parity::Odd;
    else
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa wartość parzystości");
        return;
    }

    int stopBits = ui->stopBitEdit->text().toInt(&ok);
    if(!ok || (stopBits != 1 && stopBits != 2))
    {
        QMessageBox::warning(this, "Błąd", "Nieprawidłowa liczba bitów stopu");
        return;
    }

    Device newDevice(ui->divNameEdit->text(), baud, bits, parity, stopBits);
    emit deviceCreated(newDevice);
    accept();
}

void AddDiviceForm::fillParitySettingCombo()
{
    ui->parityCombo->addItem("brak");
    ui->parityCombo->addItem("parzysta");
    ui->parityCombo->addItem("nieparzysta");
}

void AddDiviceForm::setupCommandTable()
{
    QStringList headers = {"OPIS", "KOMENDA"};
    ui->commandTableWidget->setColumnCount(2);
    ui->commandTableWidget->setHorizontalHeaderLabels(headers);
    ui->commandTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void AddDiviceForm::onAddCommandButtonClicked()
{
    QString commandDesc = ui->commandDescEdit->text();
    QString command = ui->commandEdit->text();

    if (commandDesc.isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Pole \"Opis\" nie może być puste");
        return;
    }

    if(command.isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Pole \"Komenda\" nie może być puste");
        return;
    }

    addCommandToTable(commandDesc, command);
    clearCommandTableInputs();
}

void AddDiviceForm::addCommandToTable(const QString &desc, const QString &command)
{
    int row = ui->commandTableWidget->rowCount();
    ui->commandTableWidget->insertRow(row);

    ui->commandTableWidget->setItem(row, 0, new QTableWidgetItem(desc));
    ui->commandTableWidget->setItem(row, 1, new QTableWidgetItem(command));
}

void AddDiviceForm::clearCommandTableInputs()
{
    ui->commandDescEdit->clear();
    ui->commandEdit->clear();
}
