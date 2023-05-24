#include "Team.hpp"
#include <iostream>
#include <cmath>
#include <cfloat>
using namespace std;
using namespace ariel;




//Destructor
Team::~Team() {
    for (Character *character : this->characters) {
        character-> getOut();
    }
    this->characters.clear();
    this->captain = nullptr;
    this->amount = 0;
}

//copy
Team::Team(const Team &other) : amount(other.amount),captain(other.captain), characters(other.characters) {
    }

//Copy assignment operator
Team &Team::operator=(const Team &other) {
    if (this != &other) {
        this->captain = other.captain;
        this->amount= other.amount;
        this->characters = other.characters;
    }
    return *this;
}

//Move constructor
Team::Team(Team &&other) noexcept : captain(other.captain), characters(move(other.characters)) {
    other.captain = nullptr;
}

//Move assignment operator
Team &Team::operator=(Team &&other) noexcept {
    if (this != &other) {
        for (Character *character : characters) {
            character-> getOut();
        }
        this-> characters.clear();
        amount = other.amount;
        captain = other.captain;
        characters = move(other.characters);
        other.captain = nullptr;
    }
    return *this;
}



ostream &ariel::operator <<(ostream &os, const Team &team) {
    if(team.stillAlive())
        os << "Captain: " << team.captain->getName();
    else
        os << "All Dead";
    os << '\n'<<"Participants: ";
    Team tmp = team;
    vector<Character *> characters =team.get_sorted(&tmp);
    for (Character* character :characters){
            os << *character << ", ";
    }
    return os;
}


void Team:: add(Character* character) {
    if (this->amount<10){
        character->makeBusy();
        this->characters.push_back(character);
        this->amount++;
    }
    else throw runtime_error("The team is full!");
}

int Team :: stillAlive() const{
    int alives =0;
    for (auto character : this->characters) 
        alives += character-> isAlive();
    return alives;
}

Character* Team:: getCaptain() {
    this-> updateCaptain();
    return this -> captain;
}
void Team:: updateCaptain() {
    if(!this->captain->isAlive()&&this->stillAlive())
    {
        Character* newcaptain = this -> getClosest(this);
        if(newcaptain != this -> captain){
            cout << "Captain changed from "<<this-> captain-> getName() << " to "<<newcaptain ->getName() << endl;
            this -> captain = this -> getClosest(this);
            this->captain->makeCaptain();
        }
    }
}
int Team::CowboySum() const{
    int sum = 0;
    for (Character* character : this-> characters){
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character) ){
            if(character->isAlive())
                sum++;
        }
    }
    return sum;
}
int Team::NinjaSum() const{
    int sum = 0;
    for (Character* character : this-> characters){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character) ){
            if(character->isAlive())
                sum++;
        }
    }
    return sum;
}




Character* Team:: getClosest(Team* other) const
{
    Character * closest = nullptr;
    if(!other->stillAlive()){
        throw runtime_error("all dead.");
    }
    else{
        double mindist = DBL_MAX;
        vector<Character *> characters =this->get_sorted(other);
        for (Character* character :characters)
            if(character-> isAlive() &&  character -> distance(this->captain)<mindist){
                closest = character;
                mindist = character -> distance(this->captain);
            }
    }
    return closest;
}

void Team :: attack (Team*enemy){
    if(enemy == nullptr){
        throw invalid_argument("enemy should be a pointer to a Team.");
        return;
    }
    if(!this->stillAlive()){
        throw runtime_error("dead team cant attack.");
        return;
    }
    if(!enemy->stillAlive()){
        throw runtime_error("dead team cant be attacked.");
        return;
    }
    this -> updateCaptain();
    Character* victim = this->getVictim(enemy);
    vector<Character *> characters =this->get_sorted(this);
    for (Character* character :characters){
        if(enemy->stillAlive()){
            if(!victim-> isAlive())
                victim = this->getVictim(enemy);
            character -> attack(victim);
        }
    }
}

vector<Character *> Team:: get_sorted(Team* team) const{
    vector<Character *> sorted{};
    for (Character* character : team-> getCharacters()){
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character)){
            sorted.push_back(character);
        }

    }
    for (Character* character : team-> getCharacters()){
        if (Ninja* ninja = dynamic_cast<Ninja*>(character)){
            sorted.push_back(character);
        }
    }
    return sorted;

}