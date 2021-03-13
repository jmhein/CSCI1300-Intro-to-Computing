// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 4 - Problem 3

/* Algorithm: 
    1) Initialize checkEqual function above main, with double variables num1, num2, num3 as inputs
Within checkEqual:
    2) Conditional if num1 = num2 = num3 - print all same
    3) Conditional check if one of the numbers are equal to each other (ie. num1 = num2 OR num1 = num3 OR num2 = num3)
    4) Else print all different
*/

#include <iostream> 
using namespace std;

// Initialize "checkEqual" function with three double inputs
void checkEqual (double num1, double num2, double num3);

int main () {
    // test 1
    // expected output:
    // All same
    checkEqual(1, 1, 1);
    
    // test 2
    // expected output:
    // Neither
    checkEqual(1.1, 1.1, 3);
    
    // test 3
    // expected output:
    // All different
    checkEqual(1.5, 6.3, 9.7);
   }

void checkEqual (double num1, double num2, double num3) // Write function below
{ 
    if (num1 == num2 && num1 == num3) // Conditional if [number] is equal to zero
    {
        cout << "All same" << endl; // print all same
    }
    else if (num1 == num2 || num1 == num3 || num2 == num3) // check if any numbers are equal (only one needs to be true, so OR statement works well)
    {
        cout << "Neither" << endl; // print neither
    }
    else // for all others (not all equal or neither)
    {
        cout << "All different" << endl; // print all different
    }
}