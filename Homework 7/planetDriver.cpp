#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Planet.h"
using namespace std;

// Test file

int main()
{
   // test1
   // expected output:
   // Pluto
   // 6.35
   // Pluto has a volue of 1072.53
   Planet planet1;
   planet1.setName("Pluto"); // test set name
   planet1.setRadius(6.35); // test set radius
   cout << planet1.getName() << endl; // test get name
   cout << planet1.getRadius() << endl; // test get radius
   cout << planet1.getName() << " has a volume of " << planet1.getVolume() << endl; // test get volume
   
   // test2
   // expected output:
   // Frankenstein
   // 373.3
   // Frankenstein has a volume of 2.17903e+08
   Planet planet2;
   planet2.setName("Frankenstein"); // test set name
   planet2.setRadius(373.3); // test set radius
   cout << planet2.getName() << endl; // test get name
   cout << planet2.getRadius() << endl; // test get radius
   cout << planet2.getName() << " has a volume of " << planet2.getVolume() << endl; // test get volume
}
