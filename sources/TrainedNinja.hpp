#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ninja.hpp"
using namespace std;


namespace ariel
{
    

     class TrainedNinja   : public Ninja {
        public:
            TrainedNinja (const string& name, const Point& location) : Ninja(name, location, 120, 12) {}


     };

    

}