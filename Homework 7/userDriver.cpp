#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "User.h" // include header file
using namespace std;

// Test file

int main()
{
   // test 1
   // expected output:
   // Jeremy Hein
   // 50
   // 0
   // 5
   // 15
   User user1 = User(); // initialize User variable
   user1.setUsername("Jeremy Hein"); // test setusername
   cout << user1.getUsername() << endl; // test get username
   cout << user1.getSize() << endl; // test get size
   cout << user1.getRatingAt(32) << endl; // test get rating at
   user1.setRatingAt(0,5); // test set rating at
   user1.setRatingAt(1,3); // test set rating at
   cout << user1.getRatingAt(0) << endl; // test get rating at
   user1.setNumRatings(15); // test set num ratings
   cout << user1.getNumRatings() << endl; // test get num ratings
   cout << endl;
   
   // test 2
   // expected output
   // 50
   // Hidden Test
   // 4
   // 0
   // 0
   int testRate[] = {3,1,4,2,1,3,5,0,3,4}; // hidden test from codeRunner - check elements past those initialized are 0
   User u2 = User("Hidden Test", testRate, 10);
   cout << u2.getSize() << endl; // get size
   cout << u2.getUsername() << endl; // get username
   cout << u2.getRatingAt(2) << endl; // test initialized elements
   cout << u2.getRatingAt(27) << endl; // test 0
   cout << u2.getRatingAt(48) << endl; // test 0
   cout << endl;

   // test 3
   // expected output
   // 1
   User u1 = User(); // initialize user variable
   int nRating = 45; 
   u1.setNumRatings(nRating); // set number of ratings
   int rating = 3;
   int idx = 40;
   cout << u1.setRatingAt(idx, rating) << endl; // set a rating (expect fucntion to return true)
}
