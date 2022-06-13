#include <fstream>
#include "StarsRepo.h"

StarsRepo::StarsRepo(const std::string &filename) : filename(filename)
{
    this->readFromFile();
}

const std::vector<Star> &StarsRepo::getStars() const
{
    return stars;
}

void StarsRepo::readFromFile()
{
    std::ifstream file(this->filename);

    while(file)
    {
        std::string name, constellation, RA, Dec, diameter;
        std::getline(file, name, ',');
        if (name.empty())
            break;
        std::getline(file, constellation, ',');
        std::getline(file, RA, ',');
        std::getline(file, Dec, ',');
        std::getline(file, diameter, '\n');
        Star star(name, constellation, std::stoi(RA), std::stoi(Dec), std::stoi(diameter));
        this->addStar(star);
    }

    file.close();
}

void StarsRepo::addStar(Star& star)
{
    this->stars.push_back(star);
    this->writeToFile();
}

void StarsRepo::writeToFile()
{
    std::ofstream file(this->filename);

    for (auto star : this->stars)
    {
        file << star;
    }

    file.close();
}

StarsRepo::~StarsRepo()
{
}
