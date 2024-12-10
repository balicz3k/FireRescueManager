#include "Strategy.hpp"

class FireStrategy : public Strategy
{
public:
    uint8_t calculate() final { return 3; };
};