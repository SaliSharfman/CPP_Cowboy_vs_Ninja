#include "Team.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;



void Character :: lose(int hitingPoints){
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
string Cowboy :: print() const{
    return "C "+Character::print();
}
string Ninja :: print() const{
    return "N "+Character::print();
}
void Cowboy :: attack(Character *enemy){
    if(this-> isAlive()&& enemy-> isAlive())
        if(!this->shoot(enemy))
            this->reload();
}
void Ninja :: attack(Character *enemy){
    if(this-> isAlive()&& enemy-> isAlive())
        if(!this->slash(enemy))
            this->move(enemy);
}

ostream &ariel::operator <<(ostream &os, const Character &character) {
    os << character.print();
    return os;
}
void Cowboy:: reload(){
    cout << "Cowboy "<<this->name <<" reloaded 6 bullets."<<endl;
    this->balls = 6;
}
bool Cowboy:: shoot(Character* enemy){
    int hitingPoints =10;
    if( this-> isAlive() && this->hasboolets()){
        cout << "Cowboy "<<this->name <<"("<<this-> balls<<" bullets) shot "<< enemy->getName()<< "(-"<<hitingPoints<<")."<<endl;
        this->balls--;
        enemy->lose(hitingPoints);
        return 1;
    }
    return 0;
}
bool Ninja:: slash(Character* enemy) const{
    int hitingPoints =40;
    if (this->isAlive() && this->distance(enemy)<1){
        cout << "Ninja "<<this->name<< " slashed "<< enemy->getName()<< "(-"<<hitingPoints<<")."<<endl;
        enemy->lose(hitingPoints);
        return 1;
    }
    return 0;
}
void Ninja :: move(const Character* enemy) {
    Point src = this->location;
    this->location = moveTowards(this->location,enemy->getLocation(),this->speed);
    cout << "Ninja "<<this->name <<" moved "<< this-> location.distance(src)<<" to "<< enemy->getName()<<endl;
}