#include "PointWGS.hpp"
#include <cmath>
#include <cstdlib>

PointWGS::PointWGS(const long double& x, const long double& y) : latitude_(x), longitude_(y) {}

PointWGS PointWGS::randomPointWGS()
{
    // Area limits
    long double maxLatitute{50.154564013341734};
    long double minLatitute{49.95855025648944};
    long double maxLongitude{20.02470275868903};
    long double minLongitude{19.688292482742394};

    long double latitude = minLatitute +
        static_cast<long double>(rand()) / (static_cast<long double>(RAND_MAX / (maxLatitute - minLatitute)));
    long double longitude = minLongitude +
        static_cast<long double>(rand()) / (static_cast<long double>(RAND_MAX / (maxLongitude - minLongitude)));

    return PointWGS(latitude, longitude);
}

double PointWGS::calculateDistance(const PointWGS& a, const PointWGS& b)
{
    const long double R = 6371.0; // Radius of the Earth in kilometers

    // Convert latitude and longitude from degrees to radians
    long double lat1 = a.latitude_ * M_PI / 180.0;
    long double lon1 = a.longitude_ * M_PI / 180.0;
    long double lat2 = b.latitude_ * M_PI / 180.0;
    long double lon2 = b.longitude_ * M_PI / 180.0;

    // Difference in latitude and longitude
    long double dLat = lat2 - lat1;
    long double dLon = lon2 - lon1;

    // Haversine formula
    long double aHarv =
        std::pow(std::sin(dLat / 2), 2) + std::cos(lat1) * std::cos(lat2) * std::pow(std::sin(dLon / 2), 2);
    long double cHarv = 2 * std::asin(std::sqrt(aHarv));

    // Distance in kilometers
    return R * cHarv;
}

std::ostream& operator<<(std::ostream& os, const PointWGS& a)
{
    os << "[" << a.latitude_ << "," << a.longitude_ << "]";
    return os;
}
