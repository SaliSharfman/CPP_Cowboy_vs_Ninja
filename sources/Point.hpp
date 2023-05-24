#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;


namespace ariel
{
   class Point{
        private:
            double point_x, point_y;

        public:
            Point():point_x(0.0), point_y(0.0){}
            Point(const double point_x ):point_x(point_x), point_y(0.0){}
            Point(const double &point_x,const double &point_y):point_x(point_x), point_y(point_y){}
            double distance(const Point &other) const;
            static Point moveTowards (Point src, Point dest, const double &dist);
            void Print() const {cout << *this <<endl;}
            //equals
            bool operator ==(const Point &other) const{return this->point_x == other.point_x && this->point_y == other.point_y;} 
        
            //output
            string print() const;
            friend ostream &operator <<(ostream &stream, const Point &point);

            //input
            friend istream &operator >>(istream &stream,  Point &point);

       

    };
    
   
}