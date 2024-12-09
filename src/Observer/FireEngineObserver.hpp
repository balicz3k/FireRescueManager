#pragma once

#include <format>
#include <iostream>
#include "FireEngine.hpp"
#include "Observer.hpp"
#include "State.hpp"

class FireEngineObserver : public Observer<FireEngine, State>
{
public:
    void update(const FireEngine& fireEngine, std::shared_ptr<State> state) final;
};
