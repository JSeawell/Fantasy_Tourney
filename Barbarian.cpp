/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the class source/
 implementation file for a class
 called Barbarian, which inherits
 from Character class, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#include "Barbarian.hpp"
#include "intVal.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/******************************
 Constructor
 ******************************/
Barbarian::Barbarian(string name1) : Character("Barbarian", 0, 12)
{
    name = name1;
}

/******************************
       Barbarian::getName()
 ******************************/
string Barbarian::getName()
{
    return name;
}

/******************************
 Barbarian::isDead
 ******************************/
bool Barbarian::isDead()
{
    if (strength <= 0)
        return true;
    else
        return false;
}

/******************************
 Barbarian::attack()
 
 This function generates a random
 attack based on the character's
 abilities, then returns that num.
 
 ******************************/
int Barbarian::attack()
{
    int ad1 = minMaxRand(1,6);
    int ad2 = minMaxRand(1,6);
    //cout << name << " rolls: " << ad1 << ", " << ad2 << endl;
    int attackDamage = (ad1 + ad2);
    //cout << name << " attacking with--> " << attackDamage << endl;
    return attackDamage;
}

/******************************
 Barbarian::defend()
 
 This function takes an attack
 as an argument, then generates
 a random defense based on the
 character's abilities.

 Neccessary armor is applied,
 damage is calculated, and
 strength points are updated
 and returned.
 
 ******************************/
int Barbarian::defend(int attackDamage)
{
    if (strength <= 0)
    {
        //cout << name << " is already dead." << endl;
    }
    else if (attackDamage == 100)
    {
        //cout << name << " was instantly turned to stone." << endl;
        strength = 0;
    }
    else
    {
        int d1 = minMaxRand(1,6);
        int d2 = minMaxRand(1,6);
        //cout << name << " rolls: " << d1 << ", " << d2 << endl;
	int defense = (d1 + d2);
       //cout << name << " defends with: " << defense << endl;
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
            //cout << armor << "/0 armor applied to: " << attackDamage << endl;
        }
        else if (attackDamage > 0 && attackDamage < armor)
        {
            actualDamage = 0;
            //cout << attackDamage << "/" << armor << " armor applied to: " << attackDamage << endl;
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
 Barbarian::recharge()
 
 This function generates
 a random recharge to the
 Barbarian's strength points.
 ******************************/
void Barbarian::recharge()
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
