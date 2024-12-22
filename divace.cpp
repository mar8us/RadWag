#include "divace.h"


Device::Device(const QString& name, int baudRate, int dataBits, Parity parity, int stopBits)
    : name(name)
    , baudRate(baudRate)
    , dataBits(dataBits)
    , parity(parity)
    , stopBits(stopBits)
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
