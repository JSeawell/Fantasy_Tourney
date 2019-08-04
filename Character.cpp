/******************************
 
 Name: Jake Seawell
 Date: 10/23/18
 Description:
 This is the class source/
 implementation file for a class
 called Character, which
 represents characters is a
 fantasy combat game.
 
 ******************************/

#include "Character.hpp"
#include "intVal.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/******************************
          Constructor
 ******************************/
Character::Character(string name, int armor, int strength) :
    name(name), armor(armor), strength(strength)
{
    name = name;
}

/******************************
       Character::getName()
 ******************************/
string Character::getName()
{
    return name;
}


/******************************
 Character::isDead
 ******************************/
bool Character::isDead()
{
    if (strength <= 0)
        return true;
    else
        return false;
}

/******************************
 Character::attack()
 
 This function generates a random
 attack based on the character's
 abilities, then returns that num.
 
 ******************************/
int Character::attack()
{
    	int attackDamage = minMaxRand(0,10);
	//cout << "Character attacking--> " << attackDamage << endl;
    	return attackDamage;
}

/******************************
 Character::defend()
 
 This function takes an attack
 as an argument, then generates
 a random defense based on the
 character's abilities.
 
 Neccessary armor is applied,
 damage is calculated, and
 strength points are updated
 and returned.
 
 ******************************/
int Character::defend(int attackDamage)
{
	if (strength <= 0)
	{
		//cout << "Character is already dead." << endl;
	}
	else
	{	
    int defense = minMaxRand(0,10);
    attackDamage = (attackDamage - defense);
    //cout << "Character defends with " << defense << endl;
        
	int actualDamage = 0;
	if (attackDamage <= 0)
    	{
        	actualDamage = 0;
        	//cout << "No armor needed. None applied." << endl;
    	}
	else if (attackDamage > 0 && attackDamage >= armor)
    	{
        	actualDamage = (attackDamage - armor);
        	//cout << armor << " armor applied to: " << attackDamage << endl;
    	}
	else if (attackDamage > 0 && attackDamage < armor)
	{
		actualDamage = 0;
		//cout << attackDamage << " of " << armor << " armor applied to: " << attackDamage << endl;

	}
	
    //cout << "Character strength before: " << strength << endl;
	//cout << "Actual damage: " << actualDamage << endl;

	strength = (strength - actualDamage);
	if (strength < 0)
		strength = 0;
    	
	//cout << "Character strength left: " << strength << endl;
    		
	if (strength == 0)
		//cout << "Character died." << endl;
	}
	return strength;
}

/******************************
 Character::recharge()
 
 This function generates
 a random recharge to the
 characters strength points.
 ******************************/
void Character::recharge()
{
    int coef = minMaxRand(1,5);
    int preStrength = strength;
    strength = strength + coef;
    if (strength > 10)
    {
        strength = 10;
        cout << name << " gains " << (strength - preStrength) << " strength points." << endl;
    }
    else
        cout << "Character gains " << coef << " strength points." << endl;
    cout << "Character recharged to " << strength << " strength." << endl;
}

