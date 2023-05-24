#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

using namespace std;


namespace ariel
{
    
     class Team {
        private:
            vector<Character *> characters{};
            Character *captain;
            int amount;
        public:
            Team(Character* captain):captain(captain), amount(0){ captain->makeCaptain(); this->add(captain);}
            virtual ~Team(); //Destructor
            Team(const Team &other); //copy
            Team &operator=(const Team &other); //Copy assignment operator
            Team(Team &&other) noexcept; //Move constructor
            Team &operator=(Team &&other) noexcept; //Move assignment operator
            void print() const {cout << *this <<endl;}
             //output
            friend ostream &operator <<(ostream &stream, const Team &Character);
            int getAmount()const{return this-> amount;}
            void add(Character *character);
            int stillAlive() const;
            Character* getCaptain();
            int CowboySum() const;
            int NinjaSum() const;
            void updateCaptain();
            vector<Character *> getCharacters() const{return this-> characters;}
            Character* getClosest(Team* other) const;
            void attack (Team*enemy);
            virtual vector<Character *> get_sorted(Team* team) const;
            virtual Character* getVictim(Team* enemy) {return this ->getClosest(enemy);}
            


     };
    
    class SmartTeam  : public Team {
        public:
            SmartTeam(Character* captain): Team(captain) {}
            Character* getVictim(Team* enemy) override;
            vector<Character *> get_sorted(Team* team) const override;
            int hpAfterNinjaAttack(Character* victim) const;
            int roundsToSlash(Character* victim) const;
            Character* getBestByCowboy(vector<Character *> characters);
            Character* BestSlash(vector<Character *> characters) const;
            Character* BestPosition(vector<Character *> characters) const;
            Character* getWeak(vector<Character *> characters) const;
            
     };

}