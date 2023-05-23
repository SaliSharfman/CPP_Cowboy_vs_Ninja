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
int SmartTeam::hpAfterNinjaAttack(Character* victim) const{
    if(!victim->isAlive())
        return 0;
    int hp = victim->getHp();
    for (Character* character : this-> characters){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character) ){
            if(character->isAlive()&&character->distance(victim)<1)
                hp-= 40;
        }
    }
    return hp;
}
Character* SmartTeam::BestSlash(Team* enemy) const{
    Character* best = nullptr;
    int minhp = numeric_limits<int>::max();
    for (Character* character : enemy-> getCharacters()){
        int afterattack = this-> hpAfterNinjaAttack(character);
        if (character-> isAlive() && afterattack < character->getHp() && afterattack < minhp){
            minhp = afterattack;
            best = character;
        }
    }
    return best;
}

int SmartTeam::roundsToSlash(Character* victim) const{
    int minrounds = numeric_limits<int>::max();
    if(!victim->isAlive())
        return minrounds;
    for (Character* character : this-> characters){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character) )
            if(character->isAlive()){
                int rounds = (character-> distance(victim))/ninja-> getSpeed();
                if(rounds<minrounds)
                    minrounds = rounds;
            }
    }
    return minrounds;
}
Character* SmartTeam::BestPosition(Team* enemy) const{
    Character* best = nullptr;
    int minrounds = numeric_limits<int>::max();
    for (Character* character : enemy-> getCharacters()){
        int rounds = this-> roundsToSlash(character);
        if (character-> isAlive() && rounds < minrounds){
            minrounds = rounds;
            best = character;
        }
    }
    return best;
}
Character* SmartTeam:: getVictim(Team* enemy){
    Character* victim = this-> getBestByCowboy(enemy);
    if(victim)
        return victim;
    victim = this-> BestSlash(enemy);
    if(victim)
        return victim;
    victim = this-> BestPosition(enemy);
    if(victim)
        return victim;
    return this-> getClosest(enemy);
}
            







