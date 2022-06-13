#pragma once

#include <string>
#include <ostream>

class Star
{
public:
    Star(const std::string &name, const std::string &constellation, int ra, int dec, int diameter);
    Star() = default;

    const std::string &getName() const;

    const std::string &getConstellation() const;

    int getRa() const;

    int getDec() const;

    int getDiameter() const;

    friend std::ostream &operator<<(std::ostream &os, const Star &star);

private:
    std::string name;
    std::string constellation;
    int RA, Dec;
    int diameter;
};