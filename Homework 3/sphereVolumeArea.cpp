// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 4

/* Algorithm: 
    1) Define new variable surface area after the code provided (call it surface_area)
    2) Calculate surafce_area as 4 * pi * radius squared (radius is already provided via given code for volume)
    3) Output volume (from previous code) and surface area
*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl; // given code
    double radius; // given code
    cin >> radius; // given code
    double volume; // given code - Any particular reason the variable isn't initialized on the same line?
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    
    double surface_area; // defines surface area as a doulbe vairalbe 
    surface_area = 4 * M_PI * pow(radius, 2); // initializes surface area with proper formula
    cout << "surface area: " << surface_area << endl; // prints surface area (volume already printed above)
}
   