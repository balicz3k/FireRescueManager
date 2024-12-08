#include "FireRescueUnit.hpp"
#include <chrono>
#include <numeric>
#include <thread>

FireRescueUnit::FireRescueUnit(const std::string& name, const PointWGS& location) : name_(name), location_(location)
{
    // addign 5 fire engines to the unit
    for (int i = 1; i <= 5; i++)
    {
        auto fireEngine{std::make_shared<FireEngine>(i, location, std::make_shared<FreeState>())};
        fireEngines_.push_back(fireEngine);
    }
}

FireRescueUnit::FireRescueUnit(FireRescueUnit&& other) noexcept
    : name_(std::move(other.name_))
    , location_(std::move(other.location_))
    , state_(std::move(other.state_))
    , fireEngines_(std::move(other.fireEngines_))
{
}

FireRescueUnit& FireRescueUnit::operator=(FireRescueUnit&& other) noexcept
{
    if (this != &other)
    {
        name_ = std::move(other.name_);
        location_ = std::move(other.location_);
        state_ = std::move(other.state_);
        fireEngines_ = std::move(other.fireEngines_);
    }
    return *this;
}

void FireRescueUnit::printInfo() const
{
    std::cout << "FireRescueUnit name: " << name_ << std::endl;
    std::for_each(fireEngines_.begin(), fireEngines_.end(), [](const auto fireEngine) { fireEngine->printInfo(); });
    std::cout << std::endl;
}

uint8_t FireRescueUnit::reportAvailability(const uint8_t& numOfFireEngines) const
{
    uint8_t numOfFreeFireEngines = 0;
    for (const auto& fireEngine : fireEngines_)
    {
        if (fireEngine->isFree())
        {
            numOfFreeFireEngines++;
        }
        if (numOfFreeFireEngines >= numOfFireEngines)
        {
            return numOfFreeFireEngines;
        }
    }
    return numOfFreeFireEngines;
}

void FireRescueUnit::handleAccident(const Accident& accident)
{
    uint8_t numOfFireEngines = accident.neededFireEngines();
    std::vector<std::shared_ptr<FireEngine>> fireEnginesForAccident;
    for (auto fireEngine : fireEngines_)
    {
        if (fireEngine->isFree())
        {
            fireEngine->changeState(std::make_unique<OnTheWayToAnAccidentState>());
            numOfFireEngines--;
            fireEnginesForAccident.push_back(fireEngine);
        }

        if (numOfFireEngines == 0)
        {
            break;
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 3000));
    for (auto fireEngine : fireEnginesForAccident)
    {
        fireEngine->changeState(std::make_unique<InActionState>());
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 3000));
    for (auto fireEngine : fireEnginesForAccident)
    {
        fireEngine->changeState(std::make_unique<OnTheWayToTheBaseState>());
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 3000));
    for (auto fireEngine : fireEnginesForAccident)
    {
        fireEngine->changeState(std::make_unique<FreeState>());
    }
}
