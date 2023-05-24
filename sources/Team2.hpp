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
            Character* getVictim(Team* enemy) override{return this ->getClosest(enemy);}
            vector<Character *> get_sorted(Team* team) const override{return team->getCharacters();} 
            
     };


}