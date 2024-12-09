#include "FireEngineObserver.hpp"

void FireEngineObserver::update(const FireEngine& fireEngine, std::shared_ptr<State> state)
{
    std::cout << std::format(
                     "FireEngine {} from {} change state from {} to {}.",
                     fireEngine.getId(),
                     fireEngine.getOwnerUnitName(),
                     fireEngine.getState()->toString(),
                     state->toString())
              << std::endl;
}