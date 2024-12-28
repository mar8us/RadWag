#ifndef DIVACE_H
#define DIVACE_H

#include <QString>
#include <QList>

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
    enum class Parity
    {
        None,
        Even,
        Odd
    };

    Device(const QString& name, int baudRate, int dataBits, Parity parity, int stopBits, QList<DivceCommand>& deviceCommands);

    QString getName() const;
    int getBaudRate() const;
    int getDataBits() const;
    Parity getParity() const;
    int getStopBits() const;
    QString getParityString() const;
    static Parity getParityFromString(const QString& value);
    const QList<DivceCommand>& getCommands() const;

    void setName(const QString& value);
    void setBaudRate(int value);
    void setDataBits(int value);
    void setParity(Parity value);
    void setStopBits(int value);
    void setParityFromString(const QString& value);
    void setCommands(const QList<DivceCommand> &newCommands);

private:
    QString name;
    int baudRate;
    int dataBits;
    Parity parity;
    int stopBits;
    QList<DivceCommand> commands;
};
#endif // DIVACE_H
