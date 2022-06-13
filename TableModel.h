#pragma once

#include <QAbstractTableModel>
#include "../Service/Service.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    Service& service;
    bool boxChecked;
    Astronomer astronomer;
    std::vector<Star> starsFiltered;

public:
    explicit TableModel(Service& serv, Astronomer& a, QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void dataHasChanged();
    void boxIsChecked();
};