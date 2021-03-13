// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 4 - Problem 2

/* Algorithm: 
    1) Initialize collatzStep function above main, with integer variable "number" as input
Within collatzStep:
    2) Conditional if number < zero - return 0
    3) Conditional if remainder is equal to zero - return number / 2
    4) Else (all non-zero and non-even numbers) - return 3 * number + 1
*/

#include <iostream> 
#include <math.h>
using namespace std;

// Initialize "collatzStep" function with integer input
int collatzStep (int number);

int main () {
    // test 1
    // expected output:
    // 28
    int test1 = collatzStep(9);
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // 9
    int test2 = collatzStep(18);
    cout << test2 << endl;
    
    // test 3
    // expected output:
    // 0
    int test3 = collatzStep(0);
    cout << test3 << endl;
   }

int collatzStep (int number) // Write function below
{ 
    if (number < 0) // Conditional if [number] is equal to zero
    {
        return 0; // return value of zero
    }
    else if (remainder(number,2) == 0) // check if [number] / 2 = 0 (even), return [number] / 2 
    {
        return number / 2; // see above comment
    }
    else // for all others (non-negative or even), return 3*number+1
    {
        return (3 * number) + 1; // see above comment
    }
}