#include "Team.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
using namespace ariel;


Character* SmartTeam::getBestByCowboy(vector<Character *> characters){
    int sumcowboy = this-> CowboySum();
    int minhp = sumcowboy*10;
    Character* bestcowboy = nullptr;
    for (Character* character : characters){
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
    for (Character* character : this-> getCharacters()){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character) ){
            if(character->isAlive()&&character->distance(victim)<1)
                hp-= 40;
        }
    }
    return hp;
}
Character* SmartTeam::BestSlash(vector<Character *> characters) const{
    if(!this-> NinjaSum())
        return nullptr;
    Character* best = nullptr;
    int minhp = numeric_limits<int>::max();
    for (Character* character : characters){
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
    for (Character* character : this-> getCharacters()){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character) )
            if(character->isAlive()){
                int rounds = (character-> distance(victim))/ninja-> getSpeed();
                if(rounds<minrounds)
                    minrounds = rounds;
            }
    }
    return minrounds;
}
Character* SmartTeam::BestPosition(vector<Character *> characters) const{
    if(!this-> NinjaSum())
        return nullptr;
    Character* best = nullptr;
    int minrounds = numeric_limits<int>::max();
    for (Character* character : characters){
        int rounds = this-> roundsToSlash(character);
        if (character-> isAlive() && rounds < minrounds){
            minrounds = rounds;
            best = character;
        }
    }
    return best;
}
Character* SmartTeam::getWeak(vector<Character *> characters) const{
    Character* best = nullptr;
    int minhp = numeric_limits<int>::max();
    for (Character* character :characters){
        int hp = character-> getHp();
        if (character-> isAlive()&&hp<minhp){
            minhp = hp;
            best = character;
        }
    }
    return best;
}
Character* SmartTeam:: getVictim(Team* enemy){
    Character* victim = this-> BestSlash(enemy-> getCharacters());
    if(victim)
        return victim;
    victim = this-> getBestByCowboy(enemy-> getCharacters());
    if(victim)
        return victim;
    victim = this-> BestPosition(enemy-> getCharacters());
    if(victim)
        return victim;
    return this-> getWeak(enemy-> getCharacters());
}
vector<Character *> SmartTeam:: get_sorted(Team* team) const{ 
    vector<Character *> characters = team-> getCharacters();
    int amount = team->getAmount();
    if(!amount||amount<=0||!this-> NinjaSum())
        return characters;
    

   //bool selected[amount] = {false};
    vector<Character *> sorted{};
    for (Character* character : characters){
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character)){
            sorted.push_back(character);
        }

    }
    for (Character* character : characters){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character)){
            sorted.push_back(character);
        }
    }
    return sorted;

}
            







