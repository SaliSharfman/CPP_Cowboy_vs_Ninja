#include "Team.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;


double Point:: distance (const Point &other) const{
    double dx = other.x - this->x;
    double dy = other.y - this->y;
    double dist = sqrt(dx*dx + dy*dy);
    return dist;
}

Point ariel::moveTowards (const Point src, const Point dest, const double &dist){
    double real_dist = src.distance(dest);
    if (real_dist<=dist)
        return dest;
    double ratio = dist / real_dist;
    double x = (1 - ratio) * src.x + ratio * dest.x;
    double y = (1 - ratio) * src.y + ratio * dest.y;
    return Point(x,y);
}



string Point :: print() const{
    return "("+to_string(this->x)+","+to_string(this->y)+")";
}
ostream &ariel::operator <<(ostream &os, const Point &point) {
    os << point.print();
    return os;
}


istream &ariel::operator >>(istream &is,  Point &point){
    double x, y;
    char delimiter;

    if (!(is >> x)) {
        throw runtime_error("Error: Invalid input for x.");
    }

     is >> ws; // Skip leading whitespace

    // Check if there is a delimiter
    if (!is.eof() && (is.peek() == ',' || is.peek() == ' ')) 
        is >> delimiter;

    if (!(is >> y)) {
        throw runtime_error("Error: Invalid input for y.");
    }
    point = Point(x, y);
    return is;
}