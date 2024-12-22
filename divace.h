#ifndef DIVACE_H
#define DIVACE_H

#include <QString>

class Device
{
public:
    enum class Parity
    {
        None,
        Even,
        Odd
    };

    Device(const QString& name, int baudRate, int dataBits, Parity parity, int stopBits);

    QString getName() const;
    int getBaudRate() const;
    int getDataBits() const;
    Parity getParity() const;
    int getStopBits() const;
    QString getParityString() const;

private:
    QString name;
    int baudRate;
    int dataBits;
    Parity parity;
    int stopBits;
};
#endif // DIVACE_H
