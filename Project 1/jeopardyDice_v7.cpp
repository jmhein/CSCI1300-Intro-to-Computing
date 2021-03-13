// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Project 1 - Problem 3

/* Algorithm: 
    1) Initialize necessary functions above main
    	- rollDie (given)
    	- game (given - driver for game)
    	- A function for the potential outcomes of rollDie (call it dieScore)
    	- A function for computing the human turn total (call it humanTurn) - will return a value each turn
    	- A function for computing the computer turn total (call it computerTurn) - will return a value each turn
    	- A function that will print the winner of the game (call it printWinner) - prints winner (per directions, need one that prints an outcome)

	2) Within game function
		- Print greeting "Welcome to Jeopardy Dice!"
		- Initialize total score variables for human and computer, and set each equal to 0 (call it humanTotalScore and computerTotalScore)
		- Set entire game fucntion in "while" loop - conditional while (computerTotalScore < 80 && humanTotalScore < 80) - Game continues until a player as reached 80
		- Print "It is now human's turn" (per directions, human always starts)
		- Prompt user if they want to roll dice (yes or no)
		- If no - print computerTotalScore and humanTotalScore (separate lines, computer first - reference example for specific formatting)
		- Else set humanTotalScore = humanTotalScore + humanTurn(); (calls human turn function - human takes their turn and adds turn total to total score)
		- After human turn is done - print computerTotalScore and humanTotalScore (same format as before)
		- Conditional if (humanTotalScore < 80) - print "It is now computer's turn" (if human reaches 80 and there is not a condition here, computer will get an extra turn)
		- set computerTotalScore = computerTotalScore + computerTurn(); (calls computer turn function - computer takes their turn and adds turn total to total score)
		- At end of turn, print computerTotalScore and humanTotalScore
		- Once one player reaches 80 - call printWinner function
	
	3) Within dieScore function
		- Input the number rolled on the dice
		- Use switch conditional for each number to return roll_score
		- 1 = 1
		- 2 = 0
		- 3 = 3
		- 4 = 15
		- 5 = 0
		- 6 = 6
		
	4) Within humanTurn function
		- initiate human turn total variable and set equal to zero
		- initiate roll_choice variable and set equal to 'y' (need to be y to enter loop)
		- initial roll variable
		- While roll_choice = y - roll the dice
		- call dieScore function based on number rolled
		- If roll score = 0 - turn total is equal to roll score
		- print number rolled
		- print human turn total
		- set roll_choice = 'n' to exit loop
		- If roll score = 15 - turn total is equal to roll score
		- print number rolled
		- print human turn total
		- set roll_choice = 'n' to exit loop
		- else (roll is 1, 3 or 6)
		- human turn total = previous total plus number rolled
		- print number rolled
		- print turn total
		- prompt user if they want to roll again
		- set roll_choice = to user input
		- return value for turn total at the end of the turn
		
	5) within computerTurn function
		- initiate turn total variable and set equal to zero
		- initiate roll_score variable (used as a condition in loop)
		- initiate roll variable
		- while computer turn total is < 10 AND roll_score != 0 (i.e. doesn't roll 2 or 5)
		- roll the dice
		- call dieScore function to return roll_score
		- if roll score = 0 - turn total = roll score and print number rolled and turn total (loop will exit here)
		- if roll score = 15 - turn total = roll score and print number rolled and turn total (loop will exit here)
		- else (roll 1, 3 or 6) - turn total = previous score plus number rolled (computer will continue to roll unil loop condition breaks)
		- return computer turn total once turn is completed
		
	6) within printWinner function
		- two integer inputs (human turn total and computer turn total)
		- conditional if human total score > 80 - print "Congratulations! human won this round of Jeopardy Dice!"
		- conditional if computer total score > 80 - print "Congratulations! computer won this round of Jeopardy Dice!"
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

// List of initialized functions
int rollDie();
int dieScore(int roll);
int turnHuman();
int turnComputer();
void printWinner(int humanTotalScore, int computerTotalScore);
void game();

// main function - Do not edit
int main()
{
	// start the game! 
	game();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * game 
 * driver function to play the game
 * the function does not return any value
 */

void game()
{
	cout << "Welcome to Jeopardy Dice!" << endl; // Welcome note per directions
	cout << endl; // empty line, per format provided
	int humanTotalScore = 0; // Set total score for human player to zero
	int computerTotalScore = 0; // Set total score for computer player to zero
	while (humanTotalScore < 80 && computerTotalScore < 80) // Game is ongoing until one player reaches 80 pts or more
	{
	    cout << "It is now human's turn" << endl; // Notification of human turn
	    cout << endl; // empty line per format provided
	    cout << "Do you want to roll a dice (Y/N)?:" << endl; // Prompt user if they want to roll the dice
	    char roll_choice; // Initiate roll_choice variable
	    cin >> roll_choice; // roll_choice = user input Y or N
	    if (roll_choice == 'n' || roll_choice == 'N') // if user chooses not to roll
	    {
	    	cout << "computer: " << computerTotalScore << endl; // print computer total score
	    	cout << "human: " << humanTotalScore << endl; // print human total score
	    	cout << endl; // extra line, per format provided
	    }
	    else // if answer is yes
	    {
		    humanTotalScore = humanTotalScore + turnHuman(); // human total score = previous score plus human turn score (call function turnHuman)
		    cout << "computer: " << computerTotalScore << endl; // at end of human turn, print computer score
		    cout << "human: " << humanTotalScore << endl; // at end of human turn, print human score
		    cout << endl;
	    }
	    if (humanTotalScore < 80) // if human score is less than 80 (without conditional computer will get an extra turn when human reaches 80+ first)
	    {
		    cout << "It is now computer's turn" << endl; // print it is now computer's turn
		    cout << endl; // empty space per format provided
		    computerTotalScore = computerTotalScore + turnComputer(); // computer total score = previous total score plus computer turn score (call function turnComputer)
		    cout << "computer: " << computerTotalScore << endl; // at end of computers turn, print computer total score
		    cout << "human: " << humanTotalScore << endl; // at end of computers turn, print human total score
		    cout << endl; // empty line per format provided
	    }
	}
	printWinner(humanTotalScore, computerTotalScore); // call function printWinner when game is concluded
}
	    
//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * rollDie 
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */

int rollDie()
{
	return random() % 6 + 1; 
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * dieScore
 * returns the outcome of the roll based on the number rolled 
 */
 
int dieScore(int roll) // integer input roll
{
 	int roll_score; // initiate roll_score within function
 	switch(roll)
    {
 		case 1: roll_score = 1; // if 1 is rolled - roll_score = 1
            break;
        case 2: roll_score = 0; // if 2 is rolled - roll_score = 0
            break;
        case 3: roll_score = 3; // if 3 is rolled - roll_score = 3
            break; 
        case 4: roll_score = 15; // if 4 is rolled - roll_score = 15
            break;
        case 5: roll_score = 0; // if 5 is rolled - roll_score = 0
            break; 
        case 6: roll_score = 6; // if 6 is rolled - roll_score = 6
            break;
    }
    return roll_score; // return value roll score based on number rolled 1 - 6
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * turnHuman
 * Provides mechanics for human to take their turn rolling dice
 * returns a value for the humans turn score
 */

int turnHuman()
{
 	int humanTurnTotal = 0; // initialize turn total variable = set equal to zero
 	int roll; // initialize variable roll
 	char roll_choice = 'y'; // initiate roll_choice within function - set equal to 'y' to enter while loop
 	while (roll_choice == 'y' || roll_choice == 'Y') // while roll_choice is y
 	{
		roll = rollDie(); // roll the dice
 		int roll_score = dieScore(roll); // call dieScore function - returns a score based on number rolled
 		if (roll_score == 0) // if roll_score is zero (roll = 2 or roll = 5)
 		{
 			humanTurnTotal = roll_score; // turn total is equal to the roll_score (0)
 			cout << "You rolled a " << roll << endl; // print number rolled
 			cout << "Your turn total is " << roll_score << endl; // print turn total
 			roll_choice = 'n'; // set roll_choice equal to 'n' to exit loop
		}
		else if (roll_score == 15) // if roll_score is 15 (roll = 4)
		{
			humanTurnTotal = roll_score; // turn total is equal to the roll_score (15)
			cout << "You rolled a " << roll << endl; // print number rolled
			cout << "Your turn total is " << humanTurnTotal << endl; // print turn total
			roll_choice = 'n'; // set roll_choice equal to 'n' to exit loop
		}
		else // all other options (roll = 1, 3, or 6)
		{
			humanTurnTotal = (humanTurnTotal + roll); // turn total is equal to previous total plus number rolled
			cout << "You rolled a " << roll << endl; // print number rolled
			cout << "Your turn total is " << humanTurnTotal << endl; // print turn total
			cout << "Do you want to roll again (Y/N)?:" << endl; // promt user if they want to roll again
			cin >> roll_choice; // roll_choice equal to user input
		}
	}
	return humanTurnTotal; // return the human turn total value once turn is finished
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * turnComputer
 * Provides mechanics for computer to take their turn rolling dice
 * returns a value for the computers turn score
 */

int turnComputer()
{
 	int computerTurnTotal = 0; // initialize turn total variable and set equal to zero
 	int roll; // initialize roll variable
 	int roll_score; // initialize roll_score variable (used as condition in loop)
 	while (computerTurnTotal < 10 && roll_score != 0) // while computer turn total is less than 10 AND roll_score does not equal 0 (i.e. roll a 2 or a 5)
 	{
 		roll = rollDie(); // roll the dice
 		roll_score = dieScore(roll); // call dieScore function - will break the loop if returns zero
 		if (roll_score == 0) // if score is zero
 		{
 			computerTurnTotal = roll_score; // turn total is equal to roll_score (0)
 			cout << "Computer rolled a " << roll << endl; // print number rolled
 			cout << "Computer turn total is " << computerTurnTotal << endl; // print computer turn total
 		}
 		else if (roll_score == 15) // if score is 15 (roll is 4()
 		{
 		    computerTurnTotal = roll_score; // turn total is equal to roll_score (15) - Loop will break since score is greater than 10
 		    cout << "Computer rolled a " << roll << endl; // print number rolled
 		    cout << "Computer turn total is " << computerTurnTotal << endl; // print computer turn total
 		}
 		else // all other options (roll is 1, 3, or 6)
 		{
 		    computerTurnTotal = computerTurnTotal + roll_score; // turn total is equal to previous turn total + number rolled
 		    cout << "Computer rolled a " << roll << endl; // print number rolled
 		    cout << "Computer turn total is " << computerTurnTotal << endl; // print computer turn total
 		}
 	}
 	return computerTurnTotal; // once computer turn is done, return the value for the computers turn 
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * printWinner
 * Prints "Congratulations! [player] won this round of Jeopardy Dice" based on who reaches 80 first
 */

void printWinner(int humanTotalScore, int computerTotalScore) // two integer inputs
{
	if (humanTotalScore >= 80) // if human score > 80
	{
		cout << "Congratulations! human won this round of Jeopardy Dice!" << endl; // print human winner
	}
	if (computerTotalScore >= 80) // if computer score > 80
	{
		cout << "Congratulations! computer won this round of Jeopardy Dice!" << endl; // print computer winner
	}
}