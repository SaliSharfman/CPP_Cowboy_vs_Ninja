#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;


namespace ariel
{
    class Point{
        private:
            double x, y;

        public:
            Point():x(0.0), y(0.0){}
            Point(const double &x,const double &y):x(x), y(y){}
            double distance(const Point &other) const;
            friend Point moveTowards (const Point src, const Point dest, const double &dist);
            void Print() const {cout << *this <<endl;}
        
            //output
            string print() const;
            friend ostream &operator <<(ostream &stream, const Point &point);

            //input
            friend istream &operator >>(istream &stream,  Point &point);

       

    };
    class Character{
        protected:
            Point location;
            int lives;
            string name;

        public:
            Character(){}
            Character(const Point &location,const int &lives, const string name):location(location), lives(lives), name(name){}
            bool isAlive() const{return this->lives>0;}
            double distance(const Character *other) const{return this->location.distance(other->location);}
            string getName() const{return this->name;}
            Point getLocation() const{return this->location;}
            void lose(int lives){this-> lives-= lives;}
            virtual string print() const ;
            virtual void attack(Character* character){}
            void Print() const {cout << *this <<endl;}

            //output
            friend ostream &operator <<(ostream &stream, const Character &Character);
            

       

    };
    class Cowboy : public Character {
        private:
            int balls;
        
        public:
            // Constructor
            Cowboy(const string& name, const Point& location) : Character(location, 110, name), balls(6) {}
            
            // Getter for balls
            int getBalls() const { return balls; }
            bool shoot( Character* enemy);
            bool hasboolets(){return this->balls>0;}
            void reload(){this->balls = 6;}
            void attack(Character* enemy);
            string print() const;
        };

    class Ninja : public Character {
        protected:
            int speed;
        
        public:
            // Constructor
            Ninja(const string& name, const Point& location,int lives, int speed) : Character(location, lives, name), speed(speed) {}
            void move(const Character* enemy) { this->location = moveTowards(this->location,enemy->getLocation(),this->speed); }
            bool slash(Character* enemy) const;
            void attack(Character* enemy);
            string print() const ;
        };
    class YoungNinja  : public Ninja {
        public:
            YoungNinja(const string& name, const Point& location) : Ninja(name, location, 100, 14) {}


    };
    
     class TrainedNinja   : public Ninja {
        public:
            TrainedNinja (const string& name, const Point& location) : Ninja(name, location, 120, 12) {}


     };

     class OldNinja  : public Ninja {
        public:
            OldNinja (const string& name, const Point& location) : Ninja(name, location, 150, 8) {}


     };
     class Team {
        protected:
            list<Character *> characters{};
            Character *leader;
            int alives;
        public:
            Team(Character* leader):leader(leader) , alives(1){this->add(leader);}
            void add(Character *character);
             //output
            friend ostream &operator <<(ostream &stream, const Team &Character);
            void print() const {cout << *this <<endl;}
            bool stillAlive() const;
            Character* getLeader();
            Character* getClosest() const;
            virtual Character* getVictim(Team* enemy) {return enemy ->getClosest();}
            void UpdateLeader() ;
            void attack (Team*enemy);




     };


}
