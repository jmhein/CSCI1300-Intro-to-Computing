#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "Book.h"
#include "User.h"
using namespace std;

// header file
 
class Library
{
public:
   Library(); // default constructor
   int getSizeBook();
   int getSizeUser();
   int getNumBooks();
   int getNumUsers();
   int readBooks(string filename);
   int readRatings(string filename);
   void printAllBooks();
   int getCountReadBooks(string username);
   double calcAvgRating(string title);
   int addUser(string username);
   int checkOutBook(string username, string title, int rating);
   void viewRatings(string username);
   int getRating(string username, string title);
   void getRecommendations(string username);
   
private:
   const static int sizeBook = 50;
   const static int sizeUser = 100;
   Book books[sizeBook];
   User users[sizeUser];
   int numBooks;
   int numUsers;
};

#endif
