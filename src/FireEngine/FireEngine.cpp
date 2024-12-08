#include "FireEngine.hpp"

FireEngine::FireEngine(const int& id, const PointWGS& location, std::shared_ptr<IState> state)
    : id_(id), location_(location), state_(state)
{
}

void FireEngine::printInfo() const
{
    std::lock_guard<std::mutex> lock(mtx_);
    std::cout << "FireEngine id: " << id_ << " " << state_->getState() << " at " << location_ << std::endl;
}

bool FireEngine::isFree() const
{
    std::lock_guard<std::mutex> lock(mtx_);
    return state_->getState() == "Free";
}

void FireEngine::changeState(std::shared_ptr<IState> state)
{
    std::lock_guard<std::mutex> lock(mtx_);
    state_ = std::move(state);
}