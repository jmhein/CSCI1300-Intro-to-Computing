// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 4 - Problem 1

/* Algorithm: 
    1) Initialize numberSign function above main, with integer variable "number" as input
Within numberSign:
    2) Conditional if number = zero - Print "zero"
    3) Conditional if number > zero - Print "positive"
    4) Conditional if number < zero - Print "negative"
*/

#include <iostream> 
using namespace std;

// Initialize "numberSign" function with integer input
void numberSign (int number);

int main () {
    // test 1
    // expected output:
    // zero
    numberSign(0);
    
    // test 2
    // expected output:
    // positive
    numberSign(563);
    
    // test 3
    // expected output:
    // negative
    numberSign(-56);
   }

void numberSign (int number) // Define function below
{ 
    if (number == 0) // Conditional if [number] is equal to zero
    {
        cout << "zero" << endl; // Print zero
    }
    if (number > 0) // Conditional if [number] is greater than zero
    {
        cout << "positive" << endl; // Print positive
    }
    if (number < 0) // Conditional if [number] is less than zero
    {
        cout << "negative" << endl; // Print negative
    }
}