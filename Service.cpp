#include <stdexcept>
#include "Service.h"

Service::Service(AstronomersRepo &astronomersRepo, StarsRepo &starsRepo) : astronomersRepo(astronomersRepo),
                                                                           starsRepo(starsRepo)
{}

void Service::addStar(Star &star)
{
    if (star.getName().empty())
        throw std::runtime_error("The name cannot be empty.");

    for (auto s : this->getStars())
    {
        if (s.getName() == star.getName())
        {
            throw std::runtime_error("The star already exists.");
        }
    }

    if (star.getDiameter() <= 0)
        throw std::runtime_error("The diameter cannot be negative.");

    this->starsRepo.addStar(star);
}

std::vector<Star> Service::filterByName(std::string &name)
{
    std::vector<Star> filtered;

    for (auto star: this->getStars())
    {
        std::string starName = star.getName();
        std::size_t found = starName.find(name);
        if (found != std::string::npos)
            filtered.push_back(star);
    }
    return filtered;
}

Service::~Service()
{
}
