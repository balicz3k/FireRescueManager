#include "Simulation.hpp"
#include <thread>
#include "CentralUnit.hpp"

void Simulation::startSimulation()
{
    CentralUnit centralUnit{};
    while (true)
    {
        std::thread simulateThread(&Simulation::generateAccident, this, std::ref(centralUnit));
        simulateThread.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));
    }
}

void Simulation::generateAccident(CentralUnit& centralUnit)
{
    centralUnit.reportAccident(Accident());
    accidentCounter_++;
}