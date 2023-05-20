#include "Team.hpp"
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
    if(!this-> isAlive()){
        throw runtime_error("Dead cowboy can not reload");
        return;
    }
    cout << "Cowboy "<<this->name <<" reloaded 6 bullets."<<endl;
    this->balls = 6;
}
bool Cowboy:: shoot(Character* enemy){
    if(!this-> isAlive()){
        throw runtime_error(this->getName()+" is dead.");
        return 0;
    }

    if(!enemy-> isAlive()){
        throw runtime_error(enemy->getName()+" is dead.");
        return 0;
    }
    if(enemy == this){
        throw runtime_error("No self harm");
        return 0;
    }

    if(this-> hasboolets()){
       int hitingPoints =10;
       // cout << "Cowboy "<<this->name <<"("<<this-> balls<<" bullets) shot "<< enemy->getName()<< "(-"<<hitingPoints<<")."<<endl;
        this->balls--;
        enemy->hit(hitingPoints);
        return 1;
    }
    return 0;

    
}
bool Ninja:: slash(Character* enemy) const{
    if(!this-> isAlive()){
        throw runtime_error(this->getName()+" is dead.");
        return 0;
    }

    if(!enemy-> isAlive()){
        throw runtime_error(enemy->getName()+" is dead.");
        return 0;
    }
   
    if(enemy == this){
        throw runtime_error("No self harm");
        return 0;
    }
    if (this->distance(enemy)<1){
        int hitingPoints =40;
       // cout << "Ninja "<<this->name<< " slashed "<< enemy->getName()<< "(-"<<hitingPoints<<")."<<endl;
        enemy->hit(hitingPoints);
        return 1;
    }
    return 0;

    
    
}
void Ninja :: move(const Character* enemy) {
    if(!this-> isAlive()){
        throw runtime_error(this->getName()+" is dead.");
    }

    if(!enemy-> isAlive()){
        throw runtime_error(enemy->getName()+" is dead.");
    }

    Point src = this->location;
    this->location = Point::moveTowards(this->location,enemy->getLocation(),this->speed);
    //cout << "Ninja "<<this->name <<" moved "<< this-> location.distance(src)<<" to "<< enemy->getName()<<endl;
}