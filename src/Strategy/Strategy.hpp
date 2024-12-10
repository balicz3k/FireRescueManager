#pragma once
#include <functional>
#include <tuple>

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual uint8_t calculate() = 0;
};