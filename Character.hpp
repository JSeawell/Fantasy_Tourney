/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the header/ class
 specification file for a class
 called Character, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#ifndef Character_hpp
#define Character_hpp

#include <string>
using std::string;

class Character
{
protected:
    string name;
    int armor;
    int strength;
public:
    Character(string, int, int);
    
    virtual string getName();	
    virtual bool isDead();
    
    virtual int attack();
    virtual int defend(int attackDamage);
    
    virtual void recharge();
};

#endif
