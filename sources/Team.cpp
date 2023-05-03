#include "Team.hpp"
#include <iostream>
#include <cmath>
using namespace std;
using namespace ariel;



void Team:: add(Character* character) {
    if (this->characters.size()<9){
        this->characters.push_front(character);
        this->alives++;
    }
}

ostream &ariel::operator <<(ostream &os, const Team &team) {
    os << "Leader: " << *team.leader << '\n'<<"Participants: ";
    for (auto item : team.characters) {
        os << *item << ", ";
    }
    return os;
}