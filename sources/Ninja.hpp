#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Character.hpp"
using namespace std;


namespace ariel
{
    

    class Ninja : public Character {
        private:
            int speed;
        
        public:
            // Constructor
            Ninja(const string& name, const int hitingPoints, const Point& location, const int speed) : Character(location, hitingPoints, name), speed(speed) {}
            int getSpeed() const{return this-> speed;}
            void move(const Character* enemy);
            bool slash(Character* enemy) const;
            void attack(Character* enemy)override;
            string print() const override;
        };

     

}