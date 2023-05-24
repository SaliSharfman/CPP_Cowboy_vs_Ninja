#include "Cowboy.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;


string Cowboy :: print() const{
    return "C "+Character::print();
}

void Cowboy :: attack(Character *enemy){
    if(this-> isAlive()&& enemy-> isAlive())
        if(!this->shoot(enemy))
            this->reload();
}

void Cowboy:: reload(){
    if(!this-> isAlive()){
        throw runtime_error("Dead cowboy can not reload");
        return;
    }
    cout << "Cowboy "<<this->getName() <<" reloaded 6 bullets."<<endl;
    this->bullets = 6;
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
        cout << "Cowboy "<<this->getName() <<"("<<this-> bullets<<" bullets) shot "<< enemy->getName()<< "(-"<<hitingPoints<<")."<<endl;
        this->bullets--;
        enemy->hit(hitingPoints);
        return 1;
    }
    return 0;

    
}