/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the header/ class
 specification file for a class
 called HarryPotter, which inherits
 from Character class, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include "Character.hpp"
#include <string>
using std::string;

class HarryPotter : public Character
{
protected:
    string name;
    int extraLives;
public:
    HarryPotter(string name);
    
    string getName();
    bool isDead();
    
    int attack();
    int defend(int attackDamage);
    
    void recharge();
};

#endif
