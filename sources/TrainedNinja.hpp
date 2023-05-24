#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    const int TRAINED_SPEED = 12;
    const int TRAINED_HP = 120;

     class TrainedNinja   : public Ninja {
        public:
            TrainedNinja (const string& name, const Point& location) : Ninja(name, TRAINED_HP, location, TRAINED_SPEED) {}

     };

    

}