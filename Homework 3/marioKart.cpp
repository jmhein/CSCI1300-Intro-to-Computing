// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 10

/* Algorithm: 
    1) Define "marioKart" function above the main function
    2) Prompt user to input initial speed and distance (call them initialSpeed, distance respectively)
    3) Calculate deceleration as (initialSpeed ^ 2)/2 * distance (call it deceleration)
    4) Return "double" value for deceleration
*/

#include <iostream> 
#include <math.h> // Need to include for "pow" function
using namespace std;

// Define population function
double marioKart (double initialSpeed, double distance) { // Function has two double inputs (initialSpeed, distance)
    double deceleration = pow(initialSpeed,2) / (2 * distance); // Calculates deceleration as initialSpeed ^ 2 / 2 * distance
    return deceleration; // Returns deceleration as double
}

int main () {
    // test 1
    // expected output:
    // 1
    double test1 = marioKart(4, 8);
    cout << test1 << endl;
    
    
    // test 2
    // expected output:
    // 1.63333
    double test2 = marioKart(7, 15);
    cout << test2 << endl;
}