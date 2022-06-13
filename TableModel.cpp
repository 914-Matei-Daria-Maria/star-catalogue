#include "TableModel.h"

TableModel::TableModel(Service &serv, Astronomer& a, QObject *parent): service(serv), astronomer(a), QAbstractTableModel(parent)
{
    boxChecked = false;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (boxChecked)
        return (int)this->starsFiltered.size();
    return this->service.getStarsSize();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    Star star;
    if (!boxChecked)
    {
        star = this->service.getStars()[row];
    }
    else
    {
       star = this->starsFiltered[row];
    }

    if (role == Qt::DisplayRole) {
        switch (column) {
            case 0: {
                return QString::fromStdString(star.getName());
            }
            case 1: {
                return QString::fromStdString(star.getConstellation());
            }
            case 2: {
                return QString::fromStdString(std::to_string(star.getRa()));
            }
            case 3: {
                return QString::fromStdString(std::to_string(star.getDec()));
            }
            case 4: {
                return QString::fromStdString(std::to_string(star.getDiameter()));
            }
            default:
                break;
        }
    }

    return QVariant();
}

void TableModel::boxIsChecked()
{
    this->boxChecked = !boxChecked;
    if (!this->starsFiltered.empty())
        this->starsFiltered.clear();
    for (auto s : this->service.getStars())
    {
        if (s.getConstellation() == astronomer.getConstellation())
            this->starsFiltered.push_back(s);
    }
    this->dataHasChanged();
}

void TableModel::dataHasChanged()
{
    if (this->boxChecked)
    {
        if (!this->starsFiltered.empty())
            this->starsFiltered.clear();
        for (auto s : this->service.getStars())
        {
            if (s.getConstellation() == astronomer.getConstellation())
                this->starsFiltered.push_back(s);
        }
    }
    emit layoutChanged();
}
