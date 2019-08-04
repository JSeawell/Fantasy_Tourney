/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the header/ class
 specification file for a class
 called Vampire, which inherits
 from Character class, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#ifndef Vampire_hpp
#define Vampire_hpp

#include "Character.hpp"
#include <string>
using std::string;

class Vampire : public Character
{
protected:
    string name;
public:
    Vampire(string name);
    
    string getName();
    bool isDead();
    
    int attack();
    int defend(int attackDamage);
    
    void recharge();
};

#endif
