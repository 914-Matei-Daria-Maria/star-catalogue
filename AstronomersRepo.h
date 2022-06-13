#pragma once

#include <vector>
#include "../Domain/Astronomer.h"

class AstronomersRepo
{
public:
    AstronomersRepo(const std::string &filename);

    void readFromFile();
    void addAstronomer(Astronomer& a);

    const std::vector<Astronomer> &getAstronomers() const;

private:
    std::vector<Astronomer> astronomers;
    std::string filename;

};