#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Point.hpp"
using namespace std;


namespace ariel
{
    class Character{
        protected:
            Point location;
            int hitingPoints;
            bool captain, busy;
            string name;

        public:
            Character(){}
            Character(const Point &location,const int &hitingPoints, const string name):busy(0),captain(0),location(location), hitingPoints(hitingPoints), name(name){}
            bool isAlive() const{return this->hitingPoints>0;}
            bool isCaptain() const{return this->captain;}
            bool isBusy() const{return this-> busy;}
            void makeCaptain();
            void makeBusy();
            double distance(const Character *other) const{return this->location.distance(other->location);}
            string getName() const{return this->name;}
            int getHp() const{return this->hitingPoints;}
            Point getLocation() const{return this->location;}
            void hit(int hitingPoints);
            virtual string print() const ;
            virtual void attack(Character* character){}
            void Print() const {cout << *this <<endl;}

            //output
            friend ostream &operator <<(ostream &stream, const Character &Character);
            

       

    };
   
}