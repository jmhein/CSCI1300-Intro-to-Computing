// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 5

/* Algorithm: 
    1) Initialize readBooks and split functions above main
Within readBooks
    2) Initialize temp variables type string for line, temp_array size 2, and temp book-type variable
    3) Initialize input stream and open file equal to fileName input parameter
    4) Check that number of books stored does not equal array size - return -2 if it does
    5) Check if file opened successfully, return -1 if not
    6) while getline returns true, check if i is less than size and check that line is not empty (nested if), and set i equal to i + number of books
    7) if i < size and line is not empty, split line using ',' deliminator
    8) Use set author function to set author of temp book equal to first element in temp array
    9) Use set title function to set title of temp book equal to second element in temp array
    10) Pass temp_book (with title and author set) too bookArray at index i
    11) increment i
    12) return i
*/

#include <iostream> 
#include <string>
#include <fstream>
#include "Book.h" // include header file

using namespace std;

// Initialize functions above main
int readBooks(string fileName, Book bookArray[], int numBookStored, int size);
int split(string sentence, char delim, string mySplits[], int length);

int main () 
{
    // test 1
    // expected output
    // Book 1 by Author A
    // Book 2 by Author B
    Book books[10] = {};
    readBooks("test1_readBooks.txt", books, 0, 10);
    cout << books[0].getTitle() << " by " << books[0].getAuthor() << endl;
    cout << books[1].getTitle() << " by " << books[1].getAuthor() << endl;
    cout << endl;
    
    // test 2
    // expected output
    // The Hitchhiker's Guide To The Galaxy by Douglas Adams
    // .....
    // The Lord of the Rings by J R R Tolkien
    Book books2[50] = {};
    readBooks("books.txt", books2, 0, 50);
    for (int i = 0; i < 50; i++)
    {
        cout << books2[i].getTitle() << " by " << books2[i].getAuthor() << endl;
    }
}

int readBooks(string fileName, Book bookArray[], int numBookStored, int bookArrSize) // Write function below
{ 
    string line = ""; // temp string for reading fild
    string temp_array[2]; // temp array to store / pass author names and book titles to array in parameter
    Book temp_book; // temp book varaible
    ifstream myfile; // initialize variable of steam type
    myfile.open(fileName); // open file specified in function parameter
    if (numBookStored != bookArrSize) // if num books stored does not equal array size - do stuff
    {
        if (myfile.is_open()) // check if file opens sucessfully
        {
            int i = 0 + numBookStored; // index = 0 plus whatever is already in array
            while(getline(myfile, line)) // while there are lines to read, do stuff below
            {
                if (i < bookArrSize) // as long as i is less than size of array (avoid seg fault error)
                {
                    if (line != "") // if line is not empty
                    {
                        split (line, ',', temp_array, 2); // split the string with ',' as deliminator
                        temp_book.setAuthor(temp_array[0]); // author is first element in temp array (user set author function)
                        temp_book.setTitle(temp_array[1]); // book title is second element in temp array (use set title function)
                        bookArray[i] = temp_book; // pass temp book variable to bookArray at index i
                        i++; // increment i
                    }
                }
            }
            return i; // return i (equal to number of elements in array)
        }
        else // if file did not open successfully - return -1 
        {
            return -1;
        }
    }
    else // if numBookStored = size, return - 2
    {
        return -2;
    }
}

//////////////////////////////////// SPLIT FUNCTION ///////////////////////////////////////////////////////////

int split(string sentence, char delim, string mySplits[], int length) // Write function below
{ 
    int count = 0; // initilize count variable
    string word = ""; // temp string to hold word
    sentence = sentence + delim; // adds delim to end of string in order to pick up last word in sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        if (count < length)
        {
            if (sentence[i] == delim) // if character at index i = delim
            {
                if (word.length() > 0) // check if word length is greater than 0
                {
                    mySplits[count] = word; // if true, print word
                    count ++; // count plus 1
                }
                word = "";
            }
            else
            {
            word = word + sentence[i]; // if character is not = to delim, word = previous characters + character at index #
            }
        }
        else
        {
            return -1;
        }
    }
}