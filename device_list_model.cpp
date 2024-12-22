#include "device_list_model.h"


DeviceListModel::DeviceListModel(QObject *parent) : QAbstractListModel(parent)
{

}

int DeviceListModel::rowCount(const QModelIndex &parent) const
{
    return devices.size();
}

QVariant DeviceListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
        return devices.at(index.row()).getName();

    return QVariant();
}

void DeviceListModel::addDevice(const Device& device)
{
    beginInsertRows(QModelIndex(), devices.size(), devices.size());
    devices.append(device);
    endInsertRows();
}
