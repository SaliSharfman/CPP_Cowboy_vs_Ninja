#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ninja.hpp"
using namespace std;


namespace ariel
{
    class YoungNinja  : public Ninja {
        public:
            YoungNinja(const string& name, const Point& location) : Ninja(name, location, 100, 14) {}


    };
    
    

     
}