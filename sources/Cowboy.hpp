#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Character.hpp"

using namespace std;


namespace ariel
{
    
    class Cowboy : public Character {
        private:
            int balls;
        
        public:
            // Constructor
            Cowboy(const string& name, const Point& location) : Character(location, 110, name), balls(6) {}
            
            // Getter for balls
            int getBalls() const { return balls; }
            bool shoot( Character* enemy);
            bool hasboolets(){return this->balls>0;}
            void reload();
            void attack(Character* enemy);
            string print() const;
        };


}