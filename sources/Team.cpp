#include "Team.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
using namespace ariel;


ostream &ariel::operator <<(ostream &os, const Team &team) {
    if(team.stillAlive())
        os << "Leader: " << team.leader ->getName();
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
    if (this->characters.size()<9){
        this->characters.push_back(character);
    }
}

bool Team :: stillAlive() const{
    int alives =0;
    for (auto character : this->characters) 
        alives += character-> isAlive();
    return alives;
}

Character* Team:: getLeader() {
    this-> UpdateLeader();
    return this -> leader;
}
void Team:: UpdateLeader() {
    if(!this->leader->isAlive())
    {
        Character* newleader = this -> getClosest(this);
        if(newleader != this -> leader){
            cout << "Leader changed from "<<this-> leader-> getName() << " to "<<newleader ->getName() << endl;
            this -> leader = this -> getClosest(this);
        }
    }
}


Character* Team:: getClosest(Team* other) const{
    double mindist = DBL_MAX;
    Character * closest = other -> leader;
    list<Character *> characters =this->get_sorted(other-> getCharacters());
    for (Character* character :characters)
        if(character-> isAlive() && character!= other ->leader && character -> distance(other->leader)<mindist){
            closest = character;
            mindist = character -> distance(other->leader);
        }
    return closest;
}

void Team :: attack (Team*enemy){
    Character* victim = this->getVictim(enemy);
    list<Character *> characters =this->get_sorted(this-> getCharacters());
    for (Character* character :characters){
        enemy -> UpdateLeader();
        if(!victim-> isAlive())
            victim = this->getVictim(enemy);
        character -> attack(victim);
        enemy -> UpdateLeader();
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
    return this ->getClosest(enemy);
}
            







