#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

/**
   A user class that tracks usernames and integer value ratings 0 - 5
 */

class User
{
public:
   User(); // default constructor
   User(string name, int bookRatings[], int numBooks); // parameterized constructor
   void setUsername(string name);
   void setNumRatings(int numBooks);
   int getRatingAt(int index) ;
   bool setRatingAt(int index, int value);
   int getNumRatings();
   int getSize();
   string getUsername();
   
   
private:
   string username;
   const static int size = 50;
   int ratings[size];
   int numRatings;
};

#endif
