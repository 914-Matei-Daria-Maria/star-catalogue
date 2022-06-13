#include <fstream>
#include "AstronomersRepo.h"

AstronomersRepo::AstronomersRepo(const std::string &filename) : filename(filename)
{
    this->readFromFile();
}

const std::vector<Astronomer> &AstronomersRepo::getAstronomers() const
{
    return astronomers;
}

void AstronomersRepo::readFromFile()
{
    std::ifstream file(this->filename);

    while(file)
    {
        std::string name, constellation;
        std::getline(file, name, ',');
        if (name.empty())
            break;
        std::getline(file, constellation, '\n');
        Astronomer a(name, constellation);
        this->addAstronomer(a);
    }

    file.close();
}

void AstronomersRepo::addAstronomer(Astronomer &a)
{
    this->astronomers.push_back(a);
}
