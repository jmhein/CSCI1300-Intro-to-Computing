// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 6

/* Algorithm: 
    1) Define "sphereSurfaceArea" function above the main function
    2) Input radius into sphereSurfaceArea as a double (call it radius)
    3) Calculate surface area as 4 * pi * radius squared (call it surface_area)
    4) Print surface area: [surface_area]
    5) Main function calls sphereSurfaceArea(radius) with two test cases
*/

#include <iostream> 
#include <math.h> 
using namespace std;

// Define sphereSurfaceArea function
void sphereSurfaceArea (double radius) { // Function has double input "radius" in parens
    double surface_area = 4 * M_PI * pow(radius, 2); // calculates surface area of sphere based on radius input
    cout << "surface area: " << surface_area << endl; // Prints to screen "surface area: [surface_area]"
}

int main () {
    // test 1
    // expected output:
    // surface area: 314.159
    sphereSurfaceArea(5); // first function to call sphereSurfaceArea()
    
    // test 2
    // expected output:
    // surface area: 201.062
    sphereSurfaceArea(4); // second funtion to call sphereSurfaceArea()
}