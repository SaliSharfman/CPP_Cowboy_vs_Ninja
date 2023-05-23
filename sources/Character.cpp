#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;


void Character :: makeCaptain() {
    if (this->isCaptain())
        throw runtime_error(this->name+" is already a captain.");
    this->captain=1;
}
void Character :: makeBusy() {
    if (this->isBusy())
        throw runtime_error(this->name+" is already a captain.");
    this->busy=1;
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
