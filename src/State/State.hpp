#pragma once
#include <iostream>

class State
{
public:
    virtual std::string toString() = 0;
    virtual ~State() = default;
};

class FreeState : public State
{
public:
    std::string toString() final { return "Free"; }
};

class OnTheWayToAnAccidentState : public State
{
public:
    std::string toString() final { return "On the way to an accident"; }
};

class InActionState : public State
{
public:
    std::string toString() final { return "In action"; }
};

class OnTheWayToTheBaseState : public State
{
public:
    std::string toString() final { return "On the way to the base"; }
};
