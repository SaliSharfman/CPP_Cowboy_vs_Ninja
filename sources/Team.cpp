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
    for (auto character : this->characters) 
        alives += character-> isAlive();
    return alives;
}
Character* Team:: getLeader() {
    this-> UpdateLeader();
    return this -> leader;
}
Character* Team:: getClosest() const{
    double mindist = DBL_MAX;
    Character * closest = this -> leader;
    for (auto character : this->characters) 
        if(character-> isAlive() && character!= this ->leader && character -> distance(this->leader)<mindist){
            closest = character;
            mindist = character -> distance(this->leader);
        }
    return closest;
}

void Team :: attack (Team*enemy){
    for (Character* character : this->characters){
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character)){
            enemy -> UpdateLeader();
            character -> attack(this->getVictim(enemy));
        }

    }
    for (Character* character : this->characters){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character)){
            enemy -> UpdateLeader();
            character -> attack(this->getVictim(enemy));
        }
    }
    
    

}


ostream &ariel::operator <<(ostream &os, const Team &team) {
    if(team.stillAlive())
        os << "Leader: " << team.leader ->getName();
    else
        os << "All Dead";
    os << '\n'<<"Participants: ";
    for (auto item : team.characters) {
            os << *item << ", ";
        }
    return os;
}