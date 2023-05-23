#include "Team.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
using namespace ariel;

int SmartTeam::CowboySum() const{
    int sum = 0;
    for (Character* character : this-> characters){
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character) ){
            if(character->isAlive())
                sum++;
        }
    }
    return sum;
}
Character* SmartTeam::getBestByCowboy(Team* enemy){
    int sumcowboy = this-> CowboySum();
    int minhp = sumcowboy*10;
    Character* bestcowboy = nullptr;
    for (Character* character : enemy-> getCharacters()){
        if(character-> isAlive()&&character-> getHp()<=minhp){
            bestcowboy = character;
            minhp = bestcowboy-> getHp();
        }
    }
    return bestcowboy;
}
Character* SmartTeam::getBestByNinja(Team* enemy){
    int sumcowboy = this-> CowboySum();
    int minhp = sumcowboy*10;
    Character* bestcowboy = nullptr;
    for (Character* character : enemy-> getCharacters()){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character)){
            bestcowboy = character;
            minhp = bestcowboy-> getHp();
        }
    }
    return bestcowboy;
}
Character* SmartTeam:: getVictim(Team* enemy){
    Character* victim = this-> getBestByCowboy(enemy);
    if(victim)
        return victim;
    return this -> getBestByNinja(enemy);
}
            







