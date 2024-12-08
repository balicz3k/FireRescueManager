#pragma once
#include <vector>
#include "Accident.hpp"
#include "FireRescueUnit.hpp"

class CentralUnit
{
    std::vector<std::shared_ptr<FireRescueUnit>> fireRescueUnits_;

public:
    void addFireRescueUnit(std::shared_ptr<FireRescueUnit> a) { fireRescueUnits_.push_back(a); }

    void reportAccident(const Accident& accident)
    {
        uint8_t numOfNeededFireEngines = accident.neededFireEngines();

        sort(
            fireRescueUnits_.begin(),
            fireRescueUnits_.end(),
            [&accident](std::shared_ptr<FireRescueUnit> a, std::shared_ptr<FireRescueUnit> b)
            { return FireRescueUnit::cmp(*a, *b, accident.getLocation()); });

        for (auto& fireRescueUnit : fireRescueUnits_)
        {
            auto reportedNumOfFireEngines = fireRescueUnit->reportAvailability(numOfNeededFireEngines);
            if (reportedNumOfFireEngines >= numOfNeededFireEngines)
            {
                fireRescueUnit->handleAccident(accident);
                return;
            }
            else if (reportedNumOfFireEngines > 0)
            {
                fireRescueUnit->handleAccident(accident);
                numOfNeededFireEngines -= reportedNumOfFireEngines;
            }
        }
    }

    void printInfo() const
    {
        std::for_each(
            fireRescueUnits_.begin(),
            fireRescueUnits_.end(),
            [](const auto fireRescueUnit)
            {
                fireRescueUnit->printInfo();
                std::cout << std::endl;
            });
    }
};