#include "FireEngine.hpp"

FireEngine::FireEngine(const uint8_t& id, const std::string ownerUnitName)
    : id_(id), ownerUnitName_(std::move(ownerUnitName))
{
    state_ = std::make_shared<FreeState>();
}

void FireEngine::printInfo() const
{
    this->lock();
    std::cout << "FireEngine id: " << id_ << " " << state_->toString() << std::endl;
}

bool FireEngine::isFree() const
{
    std::lock_guard<std::mutex> lock(mtx_);
    return state_->toString() == "Free";
}

void FireEngine::changeState(std::shared_ptr<State> state)
{
    this->lock();
    this->notify(state);
    state_ = std::move(state);
}

bool FireEngine::attach(FireEngineOberver* observer)
{
    this->lock();
    return observers_.insert(observer).second;
}

bool FireEngine::detach(FireEngineOberver* observer)
{
    this->lock();
    return observers_.erase(observer) == 1;
}

void FireEngine::notify(std::shared_ptr<State> state)
{
    this->lock();
    for (const auto& observer : observers_)
    {
        observer->update(*this, state);
    }
}