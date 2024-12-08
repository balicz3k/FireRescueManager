#include "FireEngine.hpp"

FireEngine::FireEngine(const int& id, const PointWGS& location, std::shared_ptr<IState> state)
    : id_(id), location_(location), state_(state)
{
}

// FireEngine::FireEngine(FireEngine&& other) noexcept
//     : id_(other.id_), location_(std::move(other.location_)), state_(std::move(other.state_))
// {
// }

// FireEngine& FireEngine::operator=(FireEngine&& other) noexcept
// {
//     if (this != &other)
//     {
//         id_ = other.id_;
//         location_ = std::move(other.location_);
//         state_ = std::move(other.state_);
//     }
//     return *this;
// }

void FireEngine::printInfo() const
{
    std::cout << "FireEngine id: " << id_ << " " << state_->getState() << " at " << location_ << std::endl;
}

bool FireEngine::isFree() const
{
    return state_->getState() == "Free";
}

void FireEngine::changeState(std::shared_ptr<IState> state)
{
    state_ = std::move(state);
}