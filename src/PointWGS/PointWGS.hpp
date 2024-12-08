#pragma once
#include <iostream>

class PointWGS
{
    long double latitude_;
    long double longitude_;

public:
    PointWGS() = delete;
    PointWGS(const long double& latitude, const long double& longitude);
    static PointWGS randomPointWGS();
    static double calculateDistance(const PointWGS& a, const PointWGS& b);

    friend std::ostream& operator<<(std::ostream& os, const PointWGS& a);
};
