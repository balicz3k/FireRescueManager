#include <thread>
#include "src/CentralUnit/CentralUnit.hpp"
#include "src/PointWGS/PointWGS.hpp"

void simulation(CentralUnit& CU)
{
    while (true)
    {
        CU.reportAccident(Accident());
        // std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 5000));
    }
}

void clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}

int main()
{
    CentralUnit centralUnit{};
    auto JRG_1{std::make_shared<FireRescueUnit>("JRG-1", PointWGS(50.0600401, 19.9433499))}; //  Westerplatte 19, Kraków
    auto JRG_2{
        std::make_shared<FireRescueUnit>("JRG-2", PointWGS(50.0335189, 19.9358363))}; //  Rzemieślnicza 10, Kraków
    auto JRG_3{std::make_shared<FireRescueUnit>("JRG-3", PointWGS(50.06143, 19.93658))}; // ul. Zarzecze 106, Kraków
    auto JRG_4{
        std::make_shared<FireRescueUnit>("JRG-4", PointWGS(50.0375876, 20.005719))}; // Obrońców Modlina 2, Kraków
    auto JRG_5{
        std::make_shared<FireRescueUnit>("JRG-5", PointWGS(50.0925232, 19.9192395))}; // Kazimierza Wyki 3, Kraków
    auto JRG_6{std::make_shared<FireRescueUnit>("JRG-6", PointWGS(50.0159353, 20.0156738))}; // Aleksandry 2, Kraków
    auto JRG_7{std::make_shared<FireRescueUnit>("JRG-7", PointWGS(50.0941204, 19.977386))}; // Rozrywka 26, Kraków
    auto JRG_SKAWINA{std::make_shared<FireRescueUnit>(
        "JRG w Skawinie", PointWGS(49.9721806, 19.7960337))}; // Piłsudskiego 20, Skawina
    auto JRG_SA_PSP{std::make_shared<FireRescueUnit>(
        "JRG SA PSP w Krakowie", PointWGS(50.0773545, 20.0330222))}; // Zgody 18, Kraków

    centralUnit.addFireRescueUnit(JRG_1);
    centralUnit.addFireRescueUnit(JRG_2);
    centralUnit.addFireRescueUnit(JRG_3);
    centralUnit.addFireRescueUnit(JRG_4);
    centralUnit.addFireRescueUnit(JRG_5);
    centralUnit.addFireRescueUnit(JRG_6);
    centralUnit.addFireRescueUnit(JRG_7);
    centralUnit.addFireRescueUnit(JRG_SKAWINA);
    centralUnit.addFireRescueUnit(JRG_SA_PSP);

    std::thread simulateThread1(simulation, std::ref(centralUnit));
    simulateThread1.detach();
    std::thread simulateThread2(simulation, std::ref(centralUnit));
    simulateThread2.detach();

    while (true)
    {
        clearScreen();
        centralUnit.printInfo();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}