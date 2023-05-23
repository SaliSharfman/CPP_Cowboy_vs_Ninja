#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Team.hpp"
using namespace std;


namespace ariel
{
    
     class Team2  : public Team {
        public:
            Team2(Character* captain): Team(captain) {}
            Character* getVictim(Team* enemy) {return this ->getClosest(enemy);}
            list<Character *> get_sorted(list<Character *> charlst) const {return charlst;}
     };


}