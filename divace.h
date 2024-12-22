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
    static Parity getParityFromString(const QString& value);

    void setName(const QString& value);
    void setBaudRate(int value);
    void setDataBits(int value);
    void setParity(Parity value);
    void setStopBits(int value);
    void setParityFromString(const QString& value);

private:
    QString name;
    int baudRate;
    int dataBits;
    Parity parity;
    int stopBits;
};
#endif // DIVACE_H
