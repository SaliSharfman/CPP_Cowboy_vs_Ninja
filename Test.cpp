#include "doctest.h"

#include <iostream>
#include <string>
using namespace std;

#include "sources/Team.hpp"
using namespace ariel;

const double eps =0.0001;
TEST_CASE("Point")
{
    Point a ,b, c;
    CHECK_NOTHROW(a=Point(6,8));
    CHECK_NOTHROW(b=Point());
    CHECK_NOTHROW(c=Point(6));
    double dist;
    CHECK_NOTHROW(dist = a.distance(b));
    CHECK(dist==10);
    CHECK_NOTHROW(dist = a.distance(c));
    CHECK(dist==8);
    CHECK_NOTHROW(c= moveTowards(a,b,10));
    CHECK(c==b);
    CHECK_NOTHROW(c= moveTowards(b,a,15));
    CHECK(c==a);
    CHECK_NOTHROW(c= moveTowards(b,a,3));
    CHECK(c.distance(a)==7);
    CHECK(c.distance(b)==3);
   
    
}

TEST_CASE("Character")
{
    Character a ,b, c;
    CHECK_NOTHROW(a=Character(Point(6,8),10,"ch1"));
    CHECK_NOTHROW(b=Character(Point(),10,"ch2"));
    CHECK(a.isAlive());
    CHECK(a.distance(&b)==10);
    CHECK(a.getName()=="ch1");
    CHECK(a.getLocation()==Point(6,8));
    CHECK(a.getHp()==10);
    CHECK_NOTHROW(a.lose(5));
    CHECK(a.isAlive());
    CHECK_NOTHROW(a.lose(10));
    CHECK(!a.isAlive());
}

TEST_CASE("Cowboy")
{
    Cowboy *a ,*b;
    Character c(Point(),19,"ch1");
    CHECK_NOTHROW(a= new Cowboy("cow1",Point(6,8)));
    CHECK_NOTHROW(b=new Cowboy("cow2",Point()));
    CHECK(a->isAlive());
    CHECK(a->distance(b)==10);
    CHECK(a->getName()=="cow1");
    CHECK(a->getLocation()==Point(6,8));
    CHECK(a->getHp()==110);
    CHECK(a->getBalls()==6);
    CHECK(b->getHp()==110);
    CHECK(a->shoot(b));
    CHECK(b->getHp()==100);
    CHECK(a->getBalls()==5);
    CHECK(a->shoot(&c));
    CHECK(a->getBalls()==4);
    CHECK(c.isAlive());
    CHECK_NOTHROW(a->attack(&c));
    CHECK(a->getBalls()==3);
    CHECK(!c.isAlive());
    CHECK_NOTHROW(a->attack(&c));
    CHECK(a->getBalls()==3);
    CHECK(a->shoot(&c));
    CHECK(a->getBalls()==2);
    CHECK_NOTHROW(a->attack(b));
    CHECK(b->getHp()==90);
    CHECK(a->getBalls()==1);
    CHECK(a->hasboolets());
    CHECK(a->shoot(b));
    CHECK(b->getHp()==80);
    CHECK(!a->hasboolets());
    CHECK_NOTHROW(a->attack(&c));
    CHECK(!a->hasboolets());
    CHECK(!a->shoot(b));
    CHECK(b->getHp()==80);
    CHECK_NOTHROW(a->attack(b));
    CHECK(b->getHp()==80);
    CHECK(a->getBalls()==6);
    CHECK(a->hasboolets());
    CHECK_NOTHROW(a->attack(b));
    CHECK(b->getHp()==70);
    CHECK(a->getBalls()==5);
    CHECK_NOTHROW(a->reload());
    CHECK(a->getBalls()==6);

}

TEST_CASE("Ninja")
{
    Ninja *ninja ,*young, *trained, *old;
    CHECK_NOTHROW(ninja= new Ninja("ninja",Point(),50,3));
    CHECK(ninja->isAlive());
    CHECK(ninja->getName()=="ninja");
    CHECK(ninja->getLocation()==Point(0,0));
    CHECK(ninja->getHp()==50);
    CHECK(ninja->getSpeed()==3);
    CHECK_NOTHROW(young=new YoungNinja("young",Point(10)));
    CHECK(young->isAlive());
    CHECK(young->getName()=="young");
    CHECK(young->getLocation()==Point(10,0));
    CHECK(young->getHp()==100);
    CHECK(young->getSpeed()==14);
    CHECK_NOTHROW(trained= new TrainedNinja("trained",Point(20)));
    CHECK(trained->isAlive());
    CHECK(trained->getName()=="trained");
    CHECK(trained->getLocation()==Point(20,0));
    CHECK(trained->getHp()==120);
    CHECK(trained->getSpeed()==12);
    CHECK_NOTHROW(old=new OldNinja("old",Point(30)));
    CHECK(old->isAlive());
    CHECK(old->getName()=="old");
    CHECK(old->getLocation()==Point(30));
    CHECK(old->getHp()==150);
    CHECK(old->getSpeed()==8);

    CHECK_NOTHROW(ninja->move(young));
    CHECK(ninja->getLocation()==Point(3));
    CHECK(!ninja->slash(young));
    CHECK(young->getHp()==100);

    CHECK_NOTHROW(young->move(ninja));
    CHECK(young->getLocation()==Point(3));
    CHECK(ninja->slash(young));
    CHECK(young->getHp()==60);

    CHECK_NOTHROW(young-> attack(old));
    CHECK(young->getLocation()==Point(17));
    
    CHECK_NOTHROW(old->attack(young));
    CHECK(young->getHp()==60);
    CHECK(old->getLocation()==Point(22));

    CHECK_NOTHROW(old->attack(young));
    CHECK(young->getHp()==60);
    CHECK(old->getLocation()==Point(17));

    CHECK_NOTHROW(old-> attack(young));
    CHECK(young->getHp()==20);

    CHECK(young-> slash(old));
    CHECK(old-> getHp()==110);

    CHECK_NOTHROW(old-> attack(young));
    CHECK(!young-> isAlive());

    CHECK(!young-> slash(old));
    CHECK(old-> getHp()==110);




    

}


