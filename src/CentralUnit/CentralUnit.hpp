#pragma once

#include <vector>
#include "FireEngineObserver.hpp"
#include "FireRescueUnit.hpp"
#include "Strategy.hpp"

class FireRescueUnit;

class CentralUnit : public std::enable_shared_from_this<CentralUnit>
{
    FireEngineObserver fireEngineObserver_{};
    std::vector<std::shared_ptr<FireRescueUnit>> fireRescueUnits_;
    std::shared_ptr<Strategy> strategy_;

public:
    CentralUnit();
    void addFireRescueUnit(std::shared_ptr<FireRescueUnit> a) { fireRescueUnits_.push_back(a); }
    void reportAccident(const Accident& accident);
    void setStrategy(std::shared_ptr<Strategy> strategy) { strategy_ = std::move(strategy); }
    void printInfo() const;
};