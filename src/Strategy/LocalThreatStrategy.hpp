#pragma once

#include "Strategy.hpp"

class LocalThreatStrategy : public Strategy
{
public:
    uint8_t calculate() final { return 2; };
};