#include "Team.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;



void Character :: lose(int lives){
    this-> lives-= lives;
    if(this-> lives <0)
        this-> lives = 0;
    if(!this-> isAlive())
        cout<< this->name << " died."<<endl;
}
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
    int lives =10;
    if( this-> isAlive() && this->hasboolets()){
        enemy->lose(lives);
        cout << "Cowboy "<<this->name <<"("<<this-> balls<<" bullets) shot "<< enemy->getName()<< "(-"<<lives<<")."<<endl;
        this->balls--;
        return 1;
    }
    return 0;
}
bool Ninja:: slash(Character* enemy) const{
    int lives =31;
    if (this->isAlive() && this->distance(enemy)<1){
        cout << "Ninja "<<this->name<< " slashed "<< enemy->getName()<< "(-"<<lives<<")."<<endl;
        enemy->lose(lives);
        return 1;
    }
    return 0;
}
void Ninja :: move(const Character* enemy) {
    Point src = this->location;
    this->location = moveTowards(this->location,enemy->getLocation(),this->speed);
    cout << "Ninja "<<this->name <<" moved "<< this-> location.distance(src)<<" to "<< enemy->getName()<<endl;
}
