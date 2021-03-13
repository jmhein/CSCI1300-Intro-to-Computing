#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Player.h"
using namespace std;

// Test file

int main()
{
   // test1
   // expected output:
   // Jeremy
   // 58976.5
   // Jeremy has 58976.5 points.
   Player player1; // test default constructor
   player1.setName("Jeremy"); // test set name
   player1.setPoints(58976.5); // test set points
   cout << player1.getName() << endl; // test get name
   cout << player1.getPoints() << endl; // test get points
   cout << player1.getName() << " has " << player1.getPoints() << " points." << endl; // print both
   
   // test2
   // expected output:
   // Frankenstein
   // 373.3
   // Frankenstein has 373.3 points.
   Player player2("Frankenstein", 373.3); // test paramaterized constructor
   cout << player2.getName() << endl; // test get name
   cout << player2.getPoints() << endl; // test get points
   cout << player2.getName() << " has " << player2.getPoints() << " points." << endl; // print both
}
