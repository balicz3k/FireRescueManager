#pragma once

#include <string>
#include "PointWGS.hpp"

class Accident
{
    std::string type_;
    PointWGS location_;

public:
    Accident() : location_(PointWGS::randomPointWGS()) { type_ = (rand() % 100 < 70 ? "MZ" : "PZ"); }
    uint8_t neededFireEngines() const { return type_ == "MZ" ? 3 : 2; }
    PointWGS getLocation() const { return location_; }
    std::string getType() const { return type_; }
};