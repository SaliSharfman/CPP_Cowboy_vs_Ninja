#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
using namespace ariel;


ostream &ariel::operator <<(ostream &os, const Team &team) {
    if(team.stillAlive())
        os << "Captain: " << team.captain->getName();
    else
        os << "All Dead";
    os << '\n'<<"Participants: ";
    list<Character *> characters =team.get_sorted(team.getCharacters());
    for (Character* character :characters){
            os << *character << ", ";
    }
    return os;
}

void Team:: add(Character* character) {
    if (this->characters.size()<10){
        character->makeBusy();
        this->characters.push_back(character);
    }
    else throw runtime_error("The team is full!");
}

int Team :: stillAlive() const{
    int alives =0;
    for (auto character : this->characters) 
        alives += character-> isAlive();
    return alives;
}

Character* Team:: getCaptain() {
    this-> updateCaptain();
    return this -> captain;
}
void Team:: updateCaptain() {
    if(!this->captain->isAlive()&&this->stillAlive())
    {
        Character* newcaptain = this -> getClosest(this);
        if(newcaptain != this -> captain){
            cout << "Captain changed from "<<this-> captain-> getName() << " to "<<newcaptain ->getName() << endl;
            this -> captain = this -> getClosest(this);
            this->captain->makeCaptain();
        }
    }
}


Character* Team:: getClosest(Team* other) const
{
    Character * closest = nullptr;
    if(!other->stillAlive()){
        throw runtime_error("all dead.");
    }
    else{
        double mindist = DBL_MAX;
        list<Character *> characters =this->get_sorted(other-> getCharacters());
        for (Character* character :characters)
            if(character-> isAlive() &&  character -> distance(this->captain)<mindist){
                closest = character;
                mindist = character -> distance(this->captain);
            }
    }
    return closest;
}

void Team :: attack (Team*enemy){
    if(enemy == nullptr){
        throw invalid_argument("enemy should be a pointer to a Team.");
        return;
    }
    if(!this->stillAlive()){
        throw runtime_error("dead team cant attack.");
        return;
    }
    if(!enemy->stillAlive()){
        throw runtime_error("dead team cant be attacked.");
        return;
    }
    this -> updateCaptain();
    Character* victim = this->getVictim(enemy);
    list<Character *> characters =this->get_sorted(this-> getCharacters());
    for (Character* character :characters){
        if(enemy->stillAlive()){
            if(!victim-> isAlive())
                victim = this->getVictim(enemy);
            character -> attack(victim);
        }
    }
}

list<Character *> Team:: get_sorted(list<Character *> characters) const{ 
    list<Character *> sorted{};
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
            







