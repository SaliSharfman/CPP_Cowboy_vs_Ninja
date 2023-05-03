#include "Team.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
using namespace ariel;


void Team:: UpdateLeader() {
    if(!this->leader->isAlive())
        this -> leader = this -> getClosest();
}
void Team:: add(Character* character) {
    if (this->characters.size()<9){
        this->characters.push_back(character);
        this->alives++;
    }
}


bool Team :: stillAlive() const{
    int alives =0;
    for (auto item : this->characters) 
        alives += item-> isAlive();
    return alives;
}
Character* Team:: getLeader() {
    if(this -> leader -> isAlive())
        return this -> leader;
    this -> leader = this -> getClosest();
    return this -> leader;
}
Character* Team:: getClosest() const{
    double mindist = DBL_MAX;
    Character * closest = this -> leader;
    for (auto item : this->characters) 
        if(item-> isAlive() && item!= this ->leader && item -> distance(this->leader)<mindist){
            closest = item;
            mindist = item -> distance(this->leader);
        }
    return closest;
}

void Team :: attack (Team*enemy){
    Character * victim = enemy->getVictim(enemy);
    for (Character* character : this->characters){
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character))
            enemy -> UpdateLeader();
            character -> attack(victim);
    }
    for (Character* character : this->characters){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character))
            enemy -> UpdateLeader();
            character -> attack(victim);
    }
    
    

}


ostream &ariel::operator <<(ostream &os, const Team &team) {
    os << "Leader: " << team.leader ->getName() << '\n'<<"Participants: ";
    for (auto item : team.characters) {
        os << *item << ", ";
    }
    return os;
}
