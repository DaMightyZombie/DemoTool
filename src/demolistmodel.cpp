#include "demolistmodel.hpp"

DemoListModel::DemoListModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    demoList = HLDemo::getDemosInDirectory("/home/rasmus/.local/share/Steam/steamapps/common/Team Fortress 2/tf/autodemos/");

}


int DemoListModel::rowCount(const QModelIndex & /*parent*/) const
{
   return demoList.size();
}

int DemoListModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 7;
}

QVariant DemoListModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        HLDemo::HLDemo demo = demoList[index.row()];
        switch (index.column()) {
        case 0:
            return demo.GetFileName().filename().c_str();
        case 1:
            return demo.GetMapName().c_str();
        case 2:
            return demo.GetPlaybackTime();
        case 3:
            return (int)demo.GetEvents()->size();
        case 4:
            return demo.GetNumTicks();
        case 5:
            return demo.GetClientName().c_str();
        case 6:
            return demo.GetServerName().c_str();
        }
        return QString();
    }
    return QVariant();
}

QVariant DemoListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return column_names[section];
    }
    return QVariant();
}
