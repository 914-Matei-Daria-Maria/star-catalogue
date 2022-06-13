#include "Astronomer.h"

Astronomer::Astronomer(const std::string &name, const std::string &constellation) : name(name),
                                                                                    constellation(constellation)
{}

const std::string &Astronomer::getName() const
{
    return name;
}

const std::string &Astronomer::getConstellation() const
{
    return constellation;
}
