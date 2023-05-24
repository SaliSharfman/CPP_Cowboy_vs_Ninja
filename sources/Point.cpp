#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace ariel;


double Point:: distance (const Point &other) const{
    double dx = other.point_x - this->point_x;
    double dy = other.point_y - this->point_y;
    double dist = sqrt(dx*dx + dy*dy);
    return dist;
}

Point Point::moveTowards (Point src, Point dest, const double &dist){
    if(dist<0){
        throw invalid_argument("Distance should be a positive number.");
        return src;
    }
    double real_dist = src.distance(dest);
    if (real_dist<=dist)
        return dest;
    double ratio = dist / real_dist;
    double x = (1 - ratio) * src.point_x + ratio * dest.point_x;
    double y = (1 - ratio) * src.point_y + ratio * dest.point_y;
    return Point(x,y);
}



string Point :: print() const{
    return "("+to_string(this->point_x)+","+to_string(this->point_y)+")";
}
ostream &ariel::operator <<(ostream &os, const Point &point) {
    os << point.print();
    return os;
}
