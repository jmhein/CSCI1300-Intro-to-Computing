// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 6

/* Algorithm: 
    1) Initialize printAllBooks function above main, with string arrays titles and authors, and number of books stored as inputs
    2) If number of books stored is <= 0, print "No books are stored"
    3) Otherwise print "Here is a list of books"
    4) For loop, i = 0, i < numBooks, i++
    5) print titles[i] by authors [i]
*/

#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

// Initialize "split" function with string and character inputs
void printAllBooks (string titles[], string authors[], int numBookStored);

int main () 
{
   // test 1
   // expected output
   // Title 1 by Author A
   // Title 2 by Author B
   string authors[2] = {"Author A", "Author B"};
   string titles[2] = {"Title 1", "Title 2"};
   printAllBooks(titles, authors, 2);
   
   // test 2
   // expected output
   // Title 1 by Author A
   // Title 2 by Author B
   // Title 7 by Author C
   // Title 108 by Author D
   string authors2[4] = {"Author A", "Author B", "Author C", "Author D"};
   string titles2[4] = {"Title 1", "Title 2", "Title 7", "Title 108"};
   printAllBooks(titles2, authors2, 4);
}

/////////////////////////////////// PRINT ALL BOOKS FUNTCION ////////////////////////////////////////////////////

void printAllBooks (string titles[], string authors [], int numBookStored)
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
            cout << titles[i] << " by " << authors[i] << endl; // print titles at i by authors at i
        }
    }
}
