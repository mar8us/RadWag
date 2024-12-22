#ifndef DEVICE_STORAGE_H
#define DEVICE_STORAGE_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDir>
#include "divace.h"

class DeviceStorage
{
public:
    static QString getStoragePath();
    static bool saveToFile(const QList<Device>& devices);
    static QList<Device> loadFromFile();
};

#endif // DEVICE_STORAGE_H
