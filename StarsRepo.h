#pragma once

#include <vector>
#include "../Domain/Star.h"

class StarsRepo
{
public:
    StarsRepo(const std::string &filename);

    const std::vector<Star> &getStars() const;
    void readFromFile();
    void writeToFile();
    void addStar(Star& star);
    int getSize() { return this->stars.size(); }

    ~StarsRepo();

private:
    std::vector<Star> stars;
    std::string filename;
};