#pragma once
#include "PointWGS.hpp"
#include "State.hpp"

class FireEngine
{
    int id_;
    PointWGS location_;
    std::shared_ptr<IState> state_;

public:
    FireEngine() = delete;
    // FireEngine(FireEngine&& other) noexcept;
    // FireEngine& operator=(FireEngine&& other) noexcept;
    FireEngine(const int& id, const PointWGS& location, std::shared_ptr<IState> state);
    void printInfo() const;
    bool isFree() const;
    void changeState(std::shared_ptr<IState> state);
};