#pragma once

#include <string>

class Astronomer
{
public:
    Astronomer(const std::string &name, const std::string &constellation);

    const std::string &getName() const;

    const std::string &getConstellation() const;

private:
    std::string name;
    std::string constellation;
};