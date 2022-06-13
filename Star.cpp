#include "Star.h"

Star::Star(const std::string &name, const std::string &constellation, int ra, int dec, int diameter) : name(name),
                                                                                                       constellation(
                                                                                                               constellation),
                                                                                                       RA(ra), Dec(dec),
                                                                                                       diameter(
                                                                                                               diameter)
{}

const std::string &Star::getName() const
{
    return name;
}

const std::string &Star::getConstellation() const
{
    return constellation;
}

int Star::getRa() const
{
    return RA;
}

int Star::getDec() const
{
    return Dec;
}

int Star::getDiameter() const
{
    return diameter;
}

std::ostream &operator<<(std::ostream &os, const Star &star)
{
    os <<  star.name << "," << star.constellation << "," << star.RA << ","
       << star.Dec << "," << star.diameter << "\n";
    return os;
}
