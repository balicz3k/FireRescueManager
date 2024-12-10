#include "FireEngine.hpp"

FireEngine::FireEngine(const uint8_t& id, const std::string ownerUnitName)
    : id_(id), ownerUnitName_(std::move(ownerUnitName))
{
    state_ = std::make_shared<FreeState>();
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

void FireEngine::attach(FireEngineOberver* observer)
{
    this->lock();
    this->observers_.add(observer);
}

void FireEngine::detach(FireEngineOberver* observer)
{
    this->lock();
    observers_.remove(observer);
}

void FireEngine::notify(std::shared_ptr<State> state)
{
    this->lock();
    auto it = observers_.createIterator();
    while (it->hasNext())
    {
        it->next()->update(*this, state);
    }
}