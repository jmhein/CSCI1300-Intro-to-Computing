// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 6

/* Algorithm: 
    1) Initialize printAllBooks function above main
    2) If number of books stored is <= 0, print "No books are stored"
    3) Otherwise print "Here is a list of books"
    4) For loop, i = 0, i < numBooksStored, i++
    5) print bookArray[i].getTitle " by " bookArray[i].getAuthor
*/

#include <iostream> 
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;

// Initialize function
void printAllBooks (Book bookArray[], int numBookStored);

int main () 
{
   // test 1
   // expected output
   // Here is a list of books
   // Red Rising by Pierce Brown
   // The Fifth Season by N K Jemisin
   // Circe by Madeline Miller
   Book book1 = Book("Red Rising", "Pierce Brown"); // initialize book variable 1
   Book book2 = Book("The Fifth Season", "N K Jemisin"); // initialize book variable 2
   Book book3 = Book("Circe", "Madeline Miller"); // initialize book variable 3
   Book bookArray[3] = {book1, book2, book3}; // initialize book-type array
   printAllBooks(bookArray, 3); // call function
   cout << endl;
   
   // test 2
   // expected output
   // No books are stored
   Book bookArray2[3] = {}; // test no books stored
   printAllBooks(bookArray2, 0); // call function
}

/////////////////////////////////// PRINT ALL BOOKS FUNTCION ////////////////////////////////////////////////////

void printAllBooks (Book bookArray[], int numBookStored)
{
    if (numBookStored <= 0) // if num books less than or equal to zero
    {
        cout << "No books are stored" << endl; // print "No books are stored" per directions
    }
    else
    {
        cout << "Here is a list of books" << endl; // print "Here is a list of books" if there are books stored
        for (int i = 0; i < numBookStored; i++) // for loop - index less than books stored
        {
            cout << bookArray[i].getTitle() << " by " << bookArray[i].getAuthor() << endl; // print getTitle and getAuthor at index i
        }
    }
}
