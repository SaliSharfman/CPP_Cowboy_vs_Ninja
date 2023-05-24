#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Character.hpp"

using namespace std;

namespace ariel
{
   const int COWBOY_BULLETS = 6;
   const int COWBOY_HP = 110;
    class Cowboy : public Character {
        private:
            int bullets;
        
        public:
            // Constructor
            Cowboy(const string& name, const Point& location) : Character(location, COWBOY_HP, name), bullets(COWBOY_BULLETS) {}
            
            // Getter for bullets
            int getBullets() const { return bullets; }
            bool shoot( Character* enemy);
            bool hasboolets() const{return this->bullets>0;}
            void reload();
            void attack(Character* enemy) override;
            string print() const override;
        };


}