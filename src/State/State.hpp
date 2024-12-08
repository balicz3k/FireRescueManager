#pragma once
#include <iostream>

class IState
{
public:
    virtual std::string getState() = 0;
    virtual ~IState() = default;
};

class FreeState : public IState
{
public:
    std::string getState() final { return "Free"; }
};

class OnTheWayToAnAccidentState : public IState
{
public:
    std::string getState() final { return "On the way to an accident"; }
};

class InActionState : public IState
{
public:
    std::string getState() final { return "In action"; }
};

class OnTheWayToTheBaseState : public IState
{
public:
    std::string getState() final { return "On the way to the base"; }
};
