#pragma once

#include <functional>

template <typename Subject, typename State>
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const Subject&, std::shared_ptr<State>) = 0;
};