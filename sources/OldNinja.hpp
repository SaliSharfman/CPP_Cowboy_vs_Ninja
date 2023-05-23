#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ninja.hpp"
using namespace std;


namespace ariel
{
    

     class OldNinja  : public Ninja {
        public:
            OldNinja (const string& name, const Point& location) : Ninja(name, location, 150, 8) {}
     };

}