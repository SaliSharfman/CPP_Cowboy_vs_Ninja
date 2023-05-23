#include "Ninja.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;


string Ninja :: print() const{
    return "N "+Character::print();
}

void Ninja :: attack(Character *enemy){
    if(this-> isAlive()&& enemy-> isAlive())
        if(!this->slash(enemy))
            this->move(enemy);
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