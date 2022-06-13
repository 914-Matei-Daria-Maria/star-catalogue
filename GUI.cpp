#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "GUI.h"

GUI::GUI(Service &service, const Astronomer &astronomer, TableModel& model, Models &modelHolder) : service(service), astronomer(astronomer), starsModel(&model), modelHolder(modelHolder)
{
    this->setWindowTitle(astronomer.getName().c_str());
    this->mainLayout = new QVBoxLayout(this);

    this->starsView = new QTableView;
    this->starsView->setModel(this->starsModel);
    this->mainLayout->addWidget(this->starsView);

    this->checkBox = new QCheckBox("View only my constellation", this);
    this->mainLayout->addWidget(this->checkBox);
    this->createAddStar();
    this->createSearchStar();
    this->connect();
}

void GUI::connect()
{
    QObject::connect(this->checkBox, &QCheckBox::stateChanged, this, &GUI::boxChecked);
    QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addHandler);
    QObject::connect(this->searchLE, &QLineEdit::textChanged, this, &GUI::searchHandler);
}

void GUI::boxChecked()
{
    this->starsModel->boxIsChecked();
}

void GUI::createAddStar()
{
    auto addWidget = new QWidget;
    auto addLayout = new QFormLayout(addWidget);

    this->nameLE = new QLineEdit;
    this->raLE = new QLineEdit;
    this->decLE = new QLineEdit;
    this->diameterLE = new QLineEdit;

    auto nameL = new QLabel("Name");
    auto raL = new QLabel("RA:");
    auto decL = new QLabel("Dec");
    auto diameterL = new QLabel("Diameter");

    nameL->setBuddy(this->nameLE);
    raL->setBuddy(this->raLE);
    decL->setBuddy(this->decLE);
    diameterL->setBuddy(this->diameterLE);

    addLayout->addRow(nameL, nameLE);
    addLayout->addRow(raL, raLE);
    addLayout->addRow(decL, decLE);
    addLayout->addRow(diameterL, diameterLE);

    this->addButton = new QPushButton("Add star");
    addLayout->addWidget(this->addButton);
    this->mainLayout->addWidget(addWidget);
}

void GUI::addHandler()
{
    std::string name, constellation;
    int ra, dec, diameter;
    name = this->nameLE->text().toStdString();
    constellation = this->astronomer.getConstellation();
    ra = this->raLE->text().toInt();
    dec = this->decLE->text().toInt();
    diameter = this->diameterLE->text().toInt();
    Star star(name, constellation, ra, dec, diameter);

    try
    {
        this->service.addStar(star);
        for (auto model : modelHolder.getModels())
        {
            model->dataHasChanged();
        }
    }
    catch (std::runtime_error& runtimeError)
    {
        QMessageBox::critical(this, "Error", runtimeError.what());
    }
}

void GUI::createSearchStar()
{
    this->searchLE = new QLineEdit;
    auto searchL = new QLabel("Search for a star");
    searchL->setBuddy(searchLE);
    auto searchWidget = new QWidget;
    auto searchLayout = new QFormLayout(searchWidget);
    searchLayout->addRow(searchL, searchLE);

    this->mainLayout->addWidget(searchWidget);

    this->searchList = new QListWidget;
    this->mainLayout->addWidget(searchList);
}

void GUI::searchHandler()
{
    std::string name = this->searchLE->text().toStdString();

    filteredStars = this->service.filterByName(name);

    this->searchList->clear();

    for (auto star : filteredStars)
    {
        auto item = new QListWidgetItem((star.getName() + ',' + star.getConstellation() + ',' + std::to_string(star.getDiameter())).c_str());
        this->searchList->addItem(item);
    }
}
