#pragma once

#include "../Repository/AstronomersRepo.h"
#include "../Repository/StarsRepo.h"

class Service
{
public:
    Service(AstronomersRepo &astronomersRepo, StarsRepo &starsRepo);
    int getStarsSize() { return this->starsRepo.getSize(); }
    std::vector<Star> getStars() { return this->starsRepo.getStars(); }
    void addStar(Star& star);
    std::vector<Star> filterByName(std::string& name);
    ~Service();

private:
    AstronomersRepo& astronomersRepo;
    StarsRepo& starsRepo;

};