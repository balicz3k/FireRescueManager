#include "Accident.hpp"
#include "CentralUnit.hpp"
#include "FireStrategy.hpp"
#include "LocalThreatStrategy.hpp"

std::shared_ptr<Strategy> Accident::adjustStrategy() const
{
    if (type_ == "MZ") return std::make_shared<LocalThreatStrategy>();
    return std::make_shared<FireStrategy>();
}