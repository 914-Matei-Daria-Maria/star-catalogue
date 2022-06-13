#pragma once

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QListWidget>
#include "../Service/Service.h"
#include "TableModel.h"

class Models
{
private:
    std::vector<TableModel*> models;

public:
    Models() = default;
    void addModel(TableModel* model) { this->models.push_back(model); }
    std::vector<TableModel*> getModels() { return this->models; }
};

class GUI: public QWidget
{
    Q_OBJECT
public:
    GUI(Service &service, const Astronomer &astronomer, TableModel& model, Models &modelHolder);

private:
    Service& service;
    Astronomer astronomer;
    Models& modelHolder;
    std::vector<Star> filteredStars;

    QVBoxLayout* mainLayout;
    QTableView* starsView;
    TableModel* starsModel;
    QCheckBox* checkBox;
    QLineEdit* nameLE, *raLE, *decLE, *diameterLE;
    QPushButton* addButton;
    QLineEdit* searchLE;
    QListWidget* searchList;

    void connect();
    void createAddStar();
    void createSearchStar();

public slots:
    void boxChecked();
    void addHandler();
    void searchHandler();

};