#pragma once

template <typename T>
class Iterator
{
public:
    virtual ~Iterator() = default;
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
};