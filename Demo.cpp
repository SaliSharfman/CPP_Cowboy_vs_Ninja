/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);

    SmartTeam team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));
     team_B.add(new Cowboy("yoram", b));
     team_B.add(new OldNinja("roi", a));
     team_B.add(new Cowboy("yani", Point(80,80)));
     Character* george = new YoungNinja("george", Point(75,100));
     team_B.add(george);
     team_A.add(new TrainedNinja("ronit", Point(12,81)));
     team_A.add(new Cowboy("LEVI", Point(20,20)));
     team_A.add(new OldNinja("cohen", Point(3,4)));
     team_A.add(new Cowboy("bernardo", Point(60,90)));
     team_A.add(new YoungNinja("jaklin", Point(75,10)));

     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
        team_A.attack(&team_B);
        if(team_A.stillAlive() > 0 && team_B.stillAlive() > 0)
         team_B.attack(&team_A);
        team_A.print();
        team_B.print();
     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
