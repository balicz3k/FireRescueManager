#pragma once

#include <vector>
#include "Accident.hpp"
#include "FireEngineObserver.hpp"
#include "FireRescueUnit.hpp"

class CentralUnit
{
    FireEngineObserver fireEngineObserver_{};
    std::vector<std::shared_ptr<FireRescueUnit>> fireRescueUnits_;

public:
    CentralUnit();
    void addFireRescueUnit(std::shared_ptr<FireRescueUnit> a) { fireRescueUnits_.push_back(a); }
    void reportAccident(const Accident& accident);
    void printInfo() const;
};