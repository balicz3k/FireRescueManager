#pragma once

#include <vector>
#include "Iterator.hpp"

template <typename T>
class Container
{
    std::vector<T> data_;

public:
    class ContainerIterator : public Iterator<T>
    {
        typename std::vector<T>::iterator current_;
        typename std::vector<T>::iterator end_;

    public:
        ContainerIterator(typename std::vector<T>::iterator current, typename std::vector<T>::iterator end)
            : current_(current), end_(end)
        {
        }
        bool hasNext() const final { return current_ != end_; }
        T next() final { return *current_++; }
    };

    std::unique_ptr<Iterator<T>> createIterator()
    {
        return std::make_unique<ContainerIterator>(data_.begin(), data_.end());
    }
    Container() = default;
    Container(const std::vector<T>& data) : data_(data) {}
    void add(const T& element) { data_.push_back(element); }
    void remove(const T& element) { data_.erase(std::remove(data_.begin(), data_.end(), element), data_.end()); }
    std::vector<T> getData() const { return data_; }
};
