#include "Team.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;




string Character :: print() const{
    if (this->isAlive())
        return this->name + " lives: " + to_string(this->lives) + ", location: " + this->location.print();
    return "(" + this->name + ") location: " + this->location.print();
    
}
string Cowboy :: print() const{
    return "C "+Character::print();
}
string Ninja :: print() const{
    return "N "+Character::print();
}
void Cowboy :: attack(Character *character){
    if(!this->shoot(character))
        this->reload();
}
void Ninja :: attack(Character *character){
    if(!this->slash(character))
        this->move(character);
}

ostream &ariel::operator <<(ostream &os, const Character &character) {
    os << character.print();
    return os;
}
bool Cowboy:: shoot(Character* enemy){
    if( this-> isAlive() && this->hasboolets()){
        enemy->lose(10);
        this->balls--;
        return 1;
    }
    return 0;
}
bool Ninja:: slash(Character* enemy) const{
    if (this->isAlive() && this->distance(enemy)<1){
        enemy->lose(31);
        return 1;
    }
    return 0;
}