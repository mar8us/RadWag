#ifndef DIVACE_H
#define DIVACE_H

#include <QString>
#include <QList>
#include <QtSerialPort/QSerialPort>

struct DivceCommand
{
    DivceCommand(const QString &description, const QString &command)
        : description(description), command(command)
    {

    }

    QString description;
    QString command;
};

class Device
{
public:
    Device(const QString& name, QSerialPort::BaudRate baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity,  QSerialPort::StopBits stopBits, QList<DivceCommand>& deviceCommands);

    QString getName() const;
    QSerialPort::BaudRate getBaudRate() const;
    QSerialPort::DataBits getDataBits() const;
    QSerialPort::Parity getParity() const;
    QSerialPort::StopBits getStopBits() const;
    QString getParityString() const;
    static QSerialPort::Parity getParityFromString(const QString& value);
    const QList<DivceCommand>& getCommands() const;

    void setName(const QString& value);
    void setBaudRate(QSerialPort::BaudRate value);
    void setDataBits(QSerialPort::DataBits value);
    void setParity(QSerialPort::Parity parity);
    void setParityFromString(const QString& value);
    void setStopBits(QSerialPort::StopBits value);
    void setCommands(const QList<DivceCommand> &newCommands);

private:
    QString name;
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::Parity parity;
    QSerialPort::StopBits stopBits;
    QList<DivceCommand> commands;
};
#endif // DIVACE_H
