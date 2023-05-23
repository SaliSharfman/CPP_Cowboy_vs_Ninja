#pragma once
#include <iostream>
#include <string>
#include <list>
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

using namespace std;


namespace ariel
{
    
     class Team {
        protected:
            list<Character *> characters{};
            Character *captain;
        public:
            Team(Character* captain):captain(captain) { captain->makeCaptain(); this->add(captain);}
            void print() const {cout << *this <<endl;}
             //output
            friend ostream &operator <<(ostream &stream, const Team &Character);
            void add(Character *character);
            int stillAlive() const;
            Character* getCaptain();
            void updateCaptain();
            list<Character *> getCharacters() const{return this-> characters;}
            Character* getClosest(Team* other) const;
            void attack (Team*enemy);
            virtual list<Character *> get_sorted(list<Character *> characters) const;
            virtual Character* getVictim(Team* enemy) {return this ->getClosest(enemy);}
            


     };
    
    class SmartTeam  : public Team {
        public:
            SmartTeam(Character* captain): Team(captain) {}
            Character* getBestByCowboy(Team* enemy);
            Character* getVictim(Team* enemy);
            int CowboySum() const;
            int hpAfterNinjaAttack(Character* victim) const;
            int roundsToSlash(Character* victim) const;
            Character* BestSlash(Team* enemy) const;
            Character* BestPosition(Team* enemy) const;
     };

}