#ifndef DEMOLISTMODEL_HPP
#define DEMOLISTMODEL_HPP

#include <QAbstractTableModel>

#include "hldemo.hpp"

class DemoListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    DemoListModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
private:
    std::vector<HLDemo::HLDemo> demoList;
    QString column_names[7] = {"File Name", "Map Name", "Playback Time", "Events", "Ticks", "Player", "Server"};
};

#endif // DEMOLISTMODEL_HPP
