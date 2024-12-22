#ifndef DEVICE_LIST_MODEL_H
#define DEVICE_LIST_MODEL_H
#include "divace.h"
#include <QObject>
#include <qabstractitemmodel.h>

class DeviceListModel : public QAbstractListModel
{
    Q_OBJECT
private:
    QList<Device> devices;

public:
    DeviceListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void addDevice(const Device& device);
};

#endif // DEVICE_LIST_MODEL_H
