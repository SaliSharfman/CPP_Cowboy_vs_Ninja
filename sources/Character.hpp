#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Point.hpp"
using namespace std;


namespace ariel
{
    class Character{
        private:
            Point location;
            int hitingPoints;
            bool captain, busy;
            string name;

        public:
            Character():hitingPoints(0),busy(false),captain(false){}
            Character(const Point &location,const int &hitingPoints, const string &name):busy(false),captain(false),location(location), hitingPoints(hitingPoints), name(name){}
            virtual ~Character(){}
            Character(const Character &other):busy(other.busy),captain(other.captain),location(other.location), hitingPoints(other.hitingPoints), name(other.name){}
            Character &operator=(const Character& other); //Copy assignment operator
            Character(Character&& other) noexcept; //Move constructor
            Character &operator=(Character&& other) noexcept; //Move assignment operator
            bool isAlive() const{return this->hitingPoints>0;}
            bool isCaptain() const{return this->captain;}
            bool isBusy() const{return this-> busy;}
            void makeCaptain();
            void makeBusy();
            void getOut(){this->captain=false; this->busy=false;}
            double distance(const Character *other) const{return this->location.distance(other->location);}
            string getName() const{return this->name;}
            int getHp() const{return this->hitingPoints;}
            Point getLocation() const{return this->location;}
            void setLocation(Point location) {this->location = location;}
            void hit(int hitingPoints);
            virtual string print() const ;
            virtual void attack(Character* character){}
            void Print() const {cout << *this <<endl;}

            //output
            friend ostream &operator <<(ostream &stream, const Character &Character);
            

       

    };
   
}