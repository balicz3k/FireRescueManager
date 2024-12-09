#include "CentralUnit.hpp"
#include <algorithm>

CentralUnit::CentralUnit()
    : fireRescueUnits_{/* Westerplatte 19, Kraków */
                       std::make_shared<FireRescueUnit>("JRG-1", PointWGS(50.0600401, 19.9433499)),
                       /* Rzemieślnicza 10, Kraków */
                       std::make_shared<FireRescueUnit>("JRG-2", PointWGS(50.0335189, 19.9358363)),
                       /* Zarzecze 106, Kraków */
                       std::make_shared<FireRescueUnit>("JRG-3", PointWGS(50.06143, 19.93658)),
                       /* Obrońców Modlina 2, Kraków */
                       std::make_shared<FireRescueUnit>("JRG-4", PointWGS(50.0375876, 20.005719)),
                       /* Kazimierza Wyki 3, Kraków */
                       std::make_shared<FireRescueUnit>("JRG-5", PointWGS(50.0925232, 19.9192395)),
                       /*  Aleksandry 2, Kraków */
                       std::make_shared<FireRescueUnit>("JRG-6", PointWGS(50.0159353, 20.0156738)),
                       /* Rozrywka 26, Kraków */
                       std::make_shared<FireRescueUnit>("JRG-7", PointWGS(50.0941204, 19.977386)),
                       /* // Piłsudskiego 20, Skawina */
                       std::make_shared<FireRescueUnit>("JRG w Skawinie", PointWGS(49.9721806, 19.7960337)),
                       /* Zgody 18, Kraków */
                       std::make_shared<FireRescueUnit>("JRG SA PSP w Krakowie", PointWGS(50.0773545, 20.0330222))}
{
    for (auto& fireRescueUnit : fireRescueUnits_)
    {
        fireRescueUnit->attachForAllFireEngines(&fireEngineObserver_);
    }
}

void CentralUnit::reportAccident(const Accident& accident)
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

void CentralUnit::printInfo() const
{
    std::for_each(
        fireRescueUnits_.begin(),
        fireRescueUnits_.end(),
        [](const auto fireRescueUnit) { fireRescueUnit->printInfo(); });
}