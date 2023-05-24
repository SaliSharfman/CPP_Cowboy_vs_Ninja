#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;


//Copy assignment operator
Character &Character::operator=(const Character &other) {
    if (this != &other) {
        this->busy= other.busy;
        this->name = other.name;
        this->location = other.location;
        this->hitingPoints = other.hitingPoints;
        this->captain = other.captain;
    }
    return *this;
}

//Move constructor
Character::Character(Character&& other) noexcept : location(move(other.location)) { //cant Throw
    this->name = move(other.name);
    this->busy= other.busy;
    this->hitingPoints = other.hitingPoints;
    this->captain = other.captain;
}

//Move assignment operator
Character& Character::operator=(Character&& other) noexcept {
if (this != &other) {
    this->name = move(other.name);
    this->location = move(other.location);
    this->busy= other.busy;
    this->hitingPoints = other.hitingPoints;
    this->captain = other.captain;
}
return *this;
}


void Character :: makeCaptain() {
    if (this->isCaptain())
        throw runtime_error(this->name+" is already a captain.");
    this->captain=1;
}
void Character :: makeBusy() {
    if (this->isBusy())
        throw runtime_error(this->name+" is already in a team.");
    this->busy=true;
}
void Character :: hit(int hitingPoints){
    if(hitingPoints<0){
        throw invalid_argument("Hiting points should be a positive natural number.");
        return;
    }
    this-> hitingPoints-= hitingPoints;
    if(this-> hitingPoints <0)
        this-> hitingPoints = 0;
    if(!this-> isAlive())
        cout<< this->name << " died."<<endl;
}
string Character :: print() const{
    if (this->isAlive())
        return this->name + " Hiting Points: " + to_string(this->hitingPoints) + ", Location: " + this->location.print();
    return "(" + this->name + ") Location: " + this->location.print();
    
}

ostream &ariel::operator <<(ostream &os, const Character &character) {
    os << character.print();
    return os;
}
