#pragma once

#include "CentralUnit.hpp"

class Simulation
{
    uint8_t accidentCounter_{0};

public:
    void startSimulation();
    void generateAccident(CentralUnit& centralUnit);
};
