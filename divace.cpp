#include "divace.h"


Device::Device(const QString& name, int baudRate, int dataBits, Parity parity, int stopBits, QList<DivceCommand>& deviceCommands)
    : name(name)
    , baudRate(baudRate)
    , dataBits(dataBits)
    , parity(parity)
    , stopBits(stopBits)
    , commands(deviceCommands)
{

}

QString Device::getName() const
{
    return name;
}

int Device::getBaudRate() const
{
    return baudRate;
}

int Device::getDataBits() const
{
    return dataBits;
}

Device::Parity Device::getParity() const
{
    return parity;
}

int Device::getStopBits() const
{
    return stopBits;
}

QString Device::getParityString() const
{
    switch(parity)
    {
        case Parity::None:
            return "brak";
        case Parity::Even:
            return "parzysta";
        case Parity::Odd:
            return "nieparzysta";
        default:
            return "Unknown";
    }
}

Device::Parity Device::getParityFromString(const QString& value)
{
    if (value == "brak")
        return Parity::None;
    else if (value == "parzysta")
        return Parity::Even;
    else if (value == "nieparzysta")
        return Parity::Odd;
    else
        return Parity::None;
}

const QList<DivceCommand>& Device::getCommands() const
{
    return commands;
}

void Device::setName(const QString& value)
{
    name = value;
}

void Device::setBaudRate(int value)
{
    baudRate = value;
}

void Device::setDataBits(int value)
{
    dataBits = value;
}

void Device::setParity(Parity value)
{
    parity = value;
}

void Device::setStopBits(int value)
{
    stopBits = value;
}

void Device::setParityFromString(const QString& value)
{
    parity = getParityFromString(value);
}

void Device::setCommands(const QList<DivceCommand> &newCommands)
{
    commands = newCommands;
}
