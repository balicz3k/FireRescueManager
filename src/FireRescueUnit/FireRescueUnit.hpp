#pragma once
#include <string>
#include "Accident.hpp"
#include "FireEngine.hpp"
#include "PointWGS.hpp"

class FireRescueUnit
{
    std::string name_;
    PointWGS location_;
    std::shared_ptr<IState> state_;
    std::vector<std::shared_ptr<FireEngine>> fireEngines_;

public:
    FireRescueUnit() = delete;
    FireRescueUnit(FireRescueUnit&& a) noexcept;
    FireRescueUnit& operator=(FireRescueUnit&& other) noexcept;
    FireRescueUnit(const std::string& name, const PointWGS& location);
    void printInfo() const;
    uint8_t reportAvailability(const uint8_t& numOfFireEngines) const;
    void handleAccident(const Accident& accident);
    static bool cmp(const FireRescueUnit& a, const FireRescueUnit& b, const PointWGS& accidentLocation)
    {
        return PointWGS::calculateDistance(a.location_, accidentLocation) <
            PointWGS::calculateDistance(b.location_, accidentLocation);
    }
};