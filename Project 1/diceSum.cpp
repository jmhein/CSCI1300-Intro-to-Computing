// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Project 1 - Problem 2

/* Algorithm: 
    1) Initialize diceSum function above main, with integer vairable "desired_sum"
Within function:
    2) Conditional if desired_sum is <2 or >12, print "The desired sum should be between 2 and 12"
    3) Else - initialize variables for die1, die2 and count
    4) While (die1 +die2) != desired sum - roll the dice
    5) Print you rolled a [die1] and a [die2]
    6) Count ++
    7) At end of loop, print "You got a [desired_sum] in [count] rolls!"
*/

#include <iostream> 
using namespace std;

// Initialize "diceSum" function with integer input
int diceSum(int desired_sum);
int rollDie(); // initialize rolldie function given

int main () {
    // test 1
    // Expected output:
    // will roll dice until sum of roll equals 4
    diceSum(4); // first function call to test function
    
    // test 2
    // Expected output:
    // will roll dice until sum of roll equals 9
    diceSum(9); // second function call to test function
}

/* rollDie
 * returns a random integer between 1 and 6,
 * works as rolling a die.
 * return value, int number (1-6)
 */
 
int rollDie () // given function
{
return random() % 6 + 1; // given code
}

int diceSum(int desired_sum)
{
    if (desired_sum < 2 || desired_sum > 12) // conditional for any arguements not between 2 and 12
    {
        cout << "The desired sum should be between 2 and 12" << endl; // print "The desired sum should be between 2 and 12"
    }
    else // all other options
    {
        int die1; // initialize variable die1
        int die2; // initialize variable die2
        int count = 0; // initialize count variable (to count iterations of loop)
        while ((die1 + die2) != desired_sum) // while rolls do not equal desired sum
        {
            count ++; // add 1 to the count
            die1 = rollDie(); // roll die1
            die2 = rollDie(); // roll die2
            cout << "You rolled a " << die1 << " and a " << die2 << endl; // print roll per directions - repeat until die1 + die2 = desired_sum
        }
        cout << "Got a " << desired_sum << " in " << count << " rolls!" << endl; // output when die1 + die2 = desired_sum
    }
}