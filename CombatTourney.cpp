/******************************
 
 Name: Jake Seawell
 Date: 11/07/18
 Description:
 This is the main function
 for running/testing a
 fantasy combat tournament.
 
 ******************************/

// Header files needed
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "choiceFunction.hpp"
#include "Menu.hpp"
#include "intVal.hpp"
#include "CharLinkedQueue.hpp"
#include "CharQueueNode.hpp"

// Rand libraries needed
#include <cstdlib>
#include <time.h>

//stream libraries needed
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

main()
{
    // User prompted to play or quit
    int playOrNaw = choiceFunction("::Fantasy Combat:", "Play Tourney", "Quit");
    
    // If play is chosen
    if (playOrNaw == 1)
    {
        // Seed all rand functions (done only once)
        srand(time(0));
        
        // 2 pointers to characters created
        Character* p1Fighter = 0;
        Character* p2Fighter = 0;
        // 2 player queues created
        CharLinkedQueue p1queue;
        CharLinkedQueue p2queue;
        // 1 loser queue created
        CharLinkedQueue loserQueue;
        
        //create character selection menu
        Menu menu1(5, "::Character Selection::");
        menu1.setOption(1, "Berserker");
        menu1.setOption(2, "Used Car Salesman");
        menu1.setOption(3, "Shield-Maidens");
        menu1.setOption(4, "God/Goddess");
        menu1.setOption(5, "Wizard/Witch");
        
        int playAgain = 0;
	int seeLosers = 0;
        int p1Score = 0;
        int p2Score = 0;
        int numFighters = 0; 
                
        // Do-while loops until game is quit/exited
        do
        {
            // user chooses number of fighters
	    cout << "How many fighters will the players battle with?" << endl;
            numFighters = minMaxValidation(integerValidation(),1,10);

	    // Player 1 chooses fighters
            cout << endl << "Player 1:" << endl;
	    p1Score = 0;           
 
            for (int i = 0; i < numFighters; i++)
            {
                cout << endl << "Select character " << i + 1 << ":" << endl;
                int choice1 = minMaxValidation(menu1.displayMenu(),1,5);
                
                if (choice1 == 1)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p1Fighter = new Barbarian(charName);
                }
                else if (choice1 == 2)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p1Fighter = new Vampire(charName);
                }
                else if (choice1 == 3)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p1Fighter = new BlueMen(charName);
                }
                else if (choice1 == 4)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p1Fighter = new Medusa(charName);
                }
                else if (choice1 == 5)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p1Fighter = new HarryPotter(charName);
                }
                
            
                cout << endl << "Player 1 fighter " << i + 1 << ": " << p1Fighter->getName() << endl;
                cout << p1Fighter->getName() << " added to queue." << endl;
                p1queue.createList(p1Fighter);
            }            
            
            // Player 2 chooses fighters
            cout << endl << "Player 2:" << endl;
	    p2Score = 0;            

            for (int i = 0; i < numFighters; i++)
            {
                cout << endl << "Select character " << i + 1 << ":" << endl;
                int choice1 = minMaxValidation(menu1.displayMenu(),1,5);
                
                if (choice1 == 1)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p2Fighter = new Barbarian(charName);
                }
                else if (choice1 == 2)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p2Fighter = new Vampire(charName);
                }
                else if (choice1 == 3)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p2Fighter = new BlueMen(charName);
                }
                else if (choice1 == 4)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p2Fighter = new Medusa(charName);
                }
                else if (choice1 == 5)
                {
                    string charName;
                    cout << endl << "Name your character:" << endl;
                    getline(cin, charName);
                    p2Fighter = new HarryPotter(charName);
                }
                
                cout << endl << "Player 2 fighter " << i + 1 << ": " << p2Fighter->getName() << endl;
                cout << p2Fighter->getName() << " added to queue." << endl;
                p2queue.createList(p2Fighter);
            }
           
            
            cout << "__________________________" << endl;
            cout << "Press enter to begin." << endl;
            
        
            // round begins
            int round = 0;
    
	    // loop until one player queues is empty
            while (!p1queue.isEmpty() && !p2queue.isEmpty())
            {
		//increment round number
                round = round + 1;
                cout << endl << "Round: " << round << endl;
                cout << "Press enter to proceed with round." << endl;

		//get first fighter from each player queue
                p1Fighter = p1queue.getFront();
                p2Fighter = p2queue.getFront();


                // attacks begin
                int attacks = 0;
            
                //While loop until a character dies
                while (!p1Fighter->isDead() && !p2Fighter->isDead())
                {
                    attacks = attacks + 1;
                    //cin.ignore();
                    cout << "__________________________" << endl;
                    cout << "Attack: " << attacks << endl;
                    cout << endl;
                
                    // Player 1 attacks
                    cout << "Player 1's ";
                    int attack1 = p1Fighter->attack();
                    
                    // Player 2 defends
                    cout << "Player 2's ";
                    p2Fighter->defend(attack1);
                    
                    //If character 2 is still alive
                    if (!p2Fighter->isDead())
                    {
                        // Player 2 attacks
                        cout << endl << "Player 2's ";
                        int attack2 = p2Fighter->attack();
                        
                        // Player 2 defends
                        cout << "Player 1's ";
                        p1Fighter->defend(attack2);
                        
			cout << "__________________________" << endl;
                        cout << "Press enter to continue." << endl;
                    }
                }
            
                // If character 1 died and ended round
                if (p1Fighter->isDead())
                {
                    cout << endl << "End of round " << round << "." << endl;
		    cout << endl << "Player 1's fighter, " << p1Fighter->getName();
                    cout << ", " << endl << "was defeated by Player 2's fighter, " << p2Fighter->getName();
                    cout << ", after " << attacks << " attacks." << endl;
                    
		    // assign victory points
                    if (attacks == 1)
		    {
			cout << endl << "Player 2 scores 3 points for an instant victory!!" << endl;
			p2Score += 3;
		    }
		    else if (attacks <= 5)
                    {
			cout << endl << "Player 2 scores 2 points for such a quick victory!" << endl;    
			p2Score += 2;
		    }
                    else
		    {
                        cout << endl << "Player 2 scores 1 point for the victory." << endl;
			p2Score ++;
		    }		

		    // move loser to front of loser queue
                    loserQueue.addFront(p1Fighter);
                    p1queue.removeFront();
		
                    //p2 recovery function
                    p2Fighter->recharge();

                    //move winner to back of queue
                    p2queue.addBack(p2Fighter);
                    p2queue.removeFront();
                }
            
                // If character 2 died and ended round
                else if (p2Fighter->isDead())
                {
		    cout << endl << "End of round " << round << "." << endl;
                    cout << endl << "Player 2's fighter, " << p2Fighter->getName();
                    cout << ", " << endl << "was defeated by Player 1's fighter, " << p1Fighter->getName();
                    cout << ", after " << attacks << " attacks." << endl;
		
                    // assign victory points
		    if (attacks == 1)
		    {
			cout << endl << "Player 1 scores 3 points for an instant victory!!" << endl;
			p1Score += 3;
		    }
		    else if (attacks <= 5)
                    {
			cout << endl << "Player 1 scores 2 points for such a quick victory!" << endl;
			p1Score += 2;
		    }
                    else
                    {
			cout << endl << "Player 1 scores 1 point for the victory." << endl;
			p1Score ++;
		    }                    

                    // move loser to front of loser queue
		    loserQueue.addFront(p2Fighter);
                    p2queue.removeFront();

                    //p1 recovery function
                    p1Fighter->recharge();

		    // move winner to back of queue
                    p1queue.addBack(p1Fighter);
                    p1queue.removeFront();
                }
            
		//display upcoming line-ups
                cout << endl << "Player 1's upcoming line-up:" << endl;
		p1queue.printQueue();
                cout << endl;
                cout << endl << "Player 2's upcoming line-up:" << endl;
		p2queue.printQueue();
		cout << endl;

		// display current score
                cout << endl << "Current score:" << endl;
		cout << "Player1: " << p1Score << " points" << endl;
		cout << "Player2: " << p2Score << " points" << endl;
		
		cout << "__________________________" << endl;
            
            }
            
	    // game over
	    cout << endl << "Game over." << endl << endl;
            
	    // display game results
            if (p1Score > p2Score)
                cout << endl << "Player 1 wins by a score of " << p1Score << " to " << p2Score << "!" << endl;
            else if (p2Score > p1Score)
                cout << "Player 2 wins by a score of " << p2Score << " to " << p1Score << "!" << endl;
            else
                cout << "The game ends in a tie, with a score of " << p1Score << " to " << p2Score << "!" << endl;
            cout << endl;
	    
	    // prompt user to see loser queue
	    seeLosers = choiceFunction("Would you like to see who was defeated during this matchup?", "Yes", "No thanks");
            if (seeLosers ==1)
	    {
		// display loser queue
		cout << "Defeated characters (from most-recently to least-recently defeated):" << endl << "{";
		loserQueue.printQueue();
		cout << "}" << endl;
	    }
            
	    // Prompt user to play again or quit
            playAgain = choiceFunction("Would you like to play again?", "Yes, play again", "No thanks, quit the game");
            
            // Delete dynamically allocated character objects
             delete p1Fighter;
             delete p2Fighter;
            
            //clear queues
            p1queue.clearQueue();
            p2queue.clearQueue();
            loserQueue.clearQueue();
	    cout << endl;
             
          // User chose to continue. Loop back to start of game  
        } while (playAgain == 1);
        
    }
    
    // User said to quit. Game over. End program
    cout << "Game over." << endl;
    return 0;
}
