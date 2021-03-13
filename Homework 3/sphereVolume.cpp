// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 5

/* Algorithm: 
    1) Define "sphereVolume function" above the main function
    2) Input variable into sphereVolume as a double (call it radius)
    3) Calculate volume = (4/3)*pi*radius squared (call it volume)
    4) Output volume: [volume]
    5) Main function calls sphereVolume(radius) with two test cases
*/

#include <iostream> 
#include <math.h> // From previous sphereVolumeArea file - needed for pow functions?
using namespace std;

// Define sphereVolume function
void sphereVolume (double radius) { // Funtion has double input "radius" in parens
    double volume = (4.0/3.0) * M_PI * pow(radius, 3); // calculates volume of sphere based on radius input
    cout << "volume: " << volume << endl; // Prints to screen "volume: [volume]"
}

int main () {
    // test 1
    // expected output:
    // volume: 523.599
    sphereVolume(5); // first function to call sphereVolume()
    
    // test 2
    // expected output:
    // volume: 268.083
    sphereVolume(4); // second funtion to call sphereVolume()
}