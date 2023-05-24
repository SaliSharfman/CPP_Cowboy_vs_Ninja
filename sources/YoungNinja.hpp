#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    const int YOUNG_SPEED =14;
    const int  YOUNG_HP =100;
    class YoungNinja  : public Ninja {
        
        public:
            YoungNinja(const string& name, const Point& location) : Ninja(name, YOUNG_HP, location, YOUNG_SPEED) {}
    };
    
    

     
}