#pragma once

#include <string>
#include "PointWGS.hpp"
#include "Strategy.hpp"

class Accident
{
    std::string type_;
    PointWGS location_;

public:
    Accident() : location_(PointWGS::randomPointWGS()) { type_ = (rand() % 100 < 70 ? "MZ" : "PZ"); }
    PointWGS getLocation() const { return location_; }
    std::string getType() const { return type_; }
    std::shared_ptr<Strategy> adjustStrategy() const;
};