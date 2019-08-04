/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the class source/
 implementation file for a class
 called BlueMen, which inherits
 from Character class, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#include "BlueMen.hpp"
#include "intVal.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/******************************
 Constructor
 ******************************/
BlueMen::BlueMen(string name1) : Character("BlueMen", 3, 12)
{
	name = name1;
}

/******************************
       BlueMen::getName()
 ******************************/
string BlueMen::getName()
{
    return name;
}

/******************************
 BlueMen::isDead
 ******************************/
bool BlueMen::isDead()
{
    if (strength <= 0)
        return true;
    else
        return false;
}

/******************************
 BlueMen::attack()
 
 This function generates a random
 attack based on the character's
 abilities, then returns that num.
 
 ******************************/
int BlueMen::attack()
{
    int ad1 = minMaxRand(1,10);
    int ad2 = minMaxRand(1,10);
    //cout << name << " roll: " << ad1 << ", " << ad2 << endl;
    int attackDamage = (ad1 + ad2);
    //cout << name << " attacking with--> " << attackDamage << endl;
    return attackDamage;
}

/******************************
 BlueMen::defend()
 
 This function takes an attack
 as an argument, then generates
 a random defense based on the
 character's abilities.
 
 Neccessary armor is applied,
 damage is calculated, and
 strength points are updated
 and returned.
 
 ******************************/
int BlueMen::defend(int attackDamage)
{
    if (strength <= 0)
    {
        //cout << name << " are already dead." << endl;
    }
    else if (attackDamage == 100)
    {
        //cout << name << " were instantly turned to stone." << endl;
        strength = 0;
    }
    else
    {
        int d1 = 0;
        int d2 = 0;
        int d3 = 0;
        
        if (strength > 8)
        {
            d1 = minMaxRand(1,6);
            d2 = minMaxRand(1,6);
            d3 = minMaxRand(1,6);
            //cout << name << " defend with 3 dice because of special ability: 'Shield Wall'. They roll: " << d1 << ", " << d2 << ", " << d3 << endl;
        }
        else if (strength <= 8 && strength > 4)
        {
            d1 = minMaxRand(1,6);
            d2 = minMaxRand(1,6);
            //cout << name << " defend: Because of special ability: 'Shield Wall', they are down 1 maiden, and only defend with 2 dice." << endl;
	    cout << name << " roll: " << d1 << ", " << d2 << endl;
        }
        else if (strength <= 4)
        {
            d1 = minMaxRand(1,6);
            //cout << name << " defend: Because of special ability: 'Shield Wall', they are down two maidens." << endl;
	    //cout << "They are down to their last maiden, and only defend with one die!" << endl;
	    //cout << name << " roll: " << d1 << endl;
        }
        
        int defense = (d1 + d2 + d3);
        //cout << name << " defend with: " << defense << endl;
	attackDamage = (attackDamage - defense);
        
        int actualDamage = 0;
        if (attackDamage <= 0)
        {
            actualDamage = 0;
            //cout << "No armor needed. None applied." << endl;
        }
        else if (attackDamage > 0 && attackDamage >= armor)
        {
            actualDamage = (attackDamage - armor);
            //cout << armor << "/3 armor applied to: " << attackDamage << endl;
        }
        else if (attackDamage > 0 && attackDamage < armor)
        {
            actualDamage = 0;
            //cout << attackDamage << "/3 armor applied to: " << attackDamage << endl;
        }
        
        //cout << name << "'s strength before: " << strength << endl;
        //cout << "Damage taken: " << actualDamage << endl;
        
        strength = (strength - actualDamage);
        if (strength < 0)
            strength = 0;
        
        //cout << name << "'s strength left: " << strength << endl;
        
        if (strength == 0)
            //cout << name << " died." << endl;
    }
    return strength;
}

/******************************
 BlueMen::recharge()
 
 This function generates
 a random recharge to the
 BlueMen strength points.
 ******************************/
void BlueMen::recharge()
{
    int coef = minMaxRand(1,6);
    int preStrength = strength;
    strength = strength + coef;
    if (strength > 12)
    {
        strength = 12;
        cout << name << " gains " << (strength - preStrength) << " strength points." << endl;
    }
    else
        cout << name << " gains " << coef << " strength points." << endl;
    cout << name << " recharged to " << strength << " strength." << endl;
}
