#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;


namespace ariel
{
    class Point{
        private:
            double point_x, point_y;

        public:
            Point():point_x(0.0), point_y(0.0){}
            Point(const double point_x ):point_x(point_x), point_y(0.0){}
            Point(const double &point_x,const double &point_y):point_x(point_x), point_y(point_y){}
            double distance(const Point &other) const;
            static Point moveTowards (const Point src, const Point dest, const double &dist);
            void Print() const {cout << *this <<endl;}
            //equals
            bool operator ==(const Point &other) const{return this->point_x == other.point_x && this->point_y == other.point_y;} 
        
            //output
            string print() const;
            friend ostream &operator <<(ostream &stream, const Point &point);

            //input
            friend istream &operator >>(istream &stream,  Point &point);

       

    };
    class Character{
        protected:
            Point location;
            int hitingPoints;
            bool captain, busy;
            string name;

        public:
            Character(){}
            Character(const Point &location,const int &hitingPoints, const string name):busy(0),captain(0),location(location), hitingPoints(hitingPoints), name(name){}
            bool isAlive() const{return this->hitingPoints>0;}
            bool isCaptain() const{return this->captain;}
            bool isBusy() const{return this-> busy;}
            void makeCaptain();
            void makeBusy();
            double distance(const Character *other) const{return this->location.distance(other->location);}
            string getName() const{return this->name;}
            int getHp() const{return this->hitingPoints;}
            Point getLocation() const{return this->location;}
            void hit(int hitingPoints);
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
            void reload();
            void attack(Character* enemy);
            string print() const;
        };

    class Ninja : public Character {
        protected:
            int speed;
        
        public:
            // Constructor
            Ninja(const string& name, const Point& location,int hitingPoints, int speed) : Character(location, hitingPoints, name), speed(speed) {}
            int getSpeed() const{return this-> speed;}
            void move(const Character* enemy);
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
            Character *captain;
        public:
            Team(Character* captain):captain(captain) { captain->makeCaptain(); this->add(captain);}
            void print() const {cout << *this <<endl;}
             //output
            friend ostream &operator <<(ostream &stream, const Team &Character);
            void add(Character *character);
            int stillAlive() const;
            Character* getCaptain();
            void updateCaptain();
            list<Character *> getCharacters() const{return this-> characters;}
            Character* getClosest(Team* other) const;
            void attack (Team*enemy);
            virtual list<Character *> get_sorted(list<Character *> characters) const;
            virtual Character* getVictim(Team* enemy) {return this ->getClosest(enemy);}
            


     };
     class Team2  : public Team {
        public:
            Team2(Character* captain): Team(captain) {}
            Character* getVictim(Team* enemy) {return this ->getClosest(enemy);}
            list<Character *> get_sorted(list<Character *> charlst) const {return charlst;}
     };

    class SmartTeam  : public Team {
        public:
            SmartTeam(Character* captain): Team(captain) {}
            Character* getBestByCowboy(Team* enemy);
            Character* getBestByNinja(Team* enemy);
            Character* getVictim(Team* enemy);
            int CowboySum() const;
     };

}