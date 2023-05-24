#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ninja.hpp"
using namespace std;

namespace ariel
{
     const int OLD_SPEED = 8;
     const int OLD_HP = 150;
     class OldNinja  : public Ninja {
        public:
            OldNinja (const string& name, const Point& location) : Ninja(name, OLD_HP, location, OLD_SPEED) {}
     };

}