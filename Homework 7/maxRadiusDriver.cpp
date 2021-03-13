// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 2

/* Algorithm: 
    1) Initialize maxRadius function above main - include header file "Planet.h"
    2) Within maxRadius - initialize "largest" variable and set equal to first element in planet array
    3) Initialize counter variable and set equal to 0
    4) Check if planet name is blank - return -1 if true
    5) for loop starting at index 0 - if planet at index i is greater than lagest, largest is equal to planet radius at index i and j is euqal to i (use getRadius function)
    6) Return j
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Planet.h"
using namespace std;

// Initialize maxRadius function
double maxRadius(Planet planets[], int size);

// Test file

int main()
{
   // test2
   // expected output:
   // Bird World
   // 4321
   // 3.37941e+11
   Planet planets[5]; // initialize planet array
   planets[0] = Planet("On A Cob Planet", 1234); // set first element
   planets[1] = Planet("Bird World", 4321); // set secont element
   int idx = maxRadius(planets, 2); // call maxRadius function
   cout << planets[idx].getName() << endl; // print name
   cout << planets[idx].getRadius() << endl; // print radius
   cout << planets[idx].getVolume() << endl; // print volume
   
   // test2
   // expected output:
   // -1
   Planet planets2[5]; // initalize planet array
   cout << maxRadius(planets2, 2) << endl; // call function (test return value when no elements initialized)
}

double maxRadius(Planet planets[], int size)
{
   double largest = planets[0].getRadius(); // initialize "largest" variable and set equal to radius of first element in array
   int j = 0; // index counter
   if (planets[0].getName() != "") // if name of first element is not blank - do stuff
   {
      for (int i = 0; i < size; i++) // for loop, i less than size
      {
         if (planets[i].getRadius() > largest) // if planet radius at index i is greater than largest
         {
            largest = planets[i].getRadius(); // largest = planet radius at index i
            j = i; // j = index i
         }
      }
      return j; // return j after for loop
   }
   else
   {
      return -1; // return -1 if no elements in array
   }
}