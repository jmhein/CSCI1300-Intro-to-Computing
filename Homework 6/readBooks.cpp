// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 5

/* Algorithm: 
    1) Initialize readBooks and split functions above main
Within readBooks
    2) Initialize temp variables type string for line, temp_authors, temp_books, and temp_array size 2
    3) Initialize input stream and open file equal to fileName input parameter
    4) Check if file opened successfully, return -1 if not
    5) Check that number of books stored does not equal array size - return -2 if it does
    6) while getline returns true, check if i is less than size and check that line is not empty (nested if), and set i equal to i + number of books
    7) if i < size and line is not empty, split line using ',' deliminator
    8) temp_authors = temp_array at position 0
    9) temp_books = temp_array at position 1
    10) books and titles at position i will equal temp authors and temp books, respectively
    11) increment i
    12) return i
*/

#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

// Initialize "split" function with string and character inputs
int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size);
int split(string sentence, char delim, string mySplits[], int length);
void printArray (string arr[], int length);

int main () 
{
   // test 1
   // Author A
   // Author B
   // Book 1
   // Book 2
   // 2
   string authors[2];
   string titles[2];
   readBooks("test1_readBooks.txt", titles, authors, 0, 2);
   printArray(authors, 2);
   printArray(titles, 2);
   cout << readBooks("test1_readBooks.txt", titles, authors, 0, 2) << endl;
   
   // test 2
   // Author A
   // Author Z
   // Author Y
   // Author X
   // 
   // Book 1
   // Book 3
   // Book 4
   // Book 5
   //
   // 4
   string authors2[5] = {"Author A"};
   string titles2[5] = {"Book 1"};
   readBooks("test2_readBooks.txt", titles2, authors2, 1, 5);
   printArray(authors2, 5);
   printArray(titles2, 5);
   cout << readBooks("test2_readBooks.txt", titles2, authors2, 1, 5) << endl;
}

int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) // Write function below
{ 
    string line = ""; // temp string for reading fild
    string temp_authors; // temp variable to store author name after split
    string temp_books; // temp variable to store book title after split
    string temp_array[2]; // temp array to store / pass author names and book titles to arrays in parameter
    ifstream myfile; // initialize variable of steam type
    myfile.open(fileName); // open file specified in function parameter
    if (myfile.is_open()) // if file opened successfly - do stuff
    {
        if (numBookStored != size) // when file opens successfully, check if numBookStored = size - if not proceed with code
        {
            int i = 0 + numBookStored; // index = 0 plus whatever is already in array
            while(getline(myfile, line)) // while there are lines to read, do stuff below
            {
                if (i < size) // as long as i is less than size of array (avoid seg fault error)
                {
                    if (line != "") // if line is not empty
                    {
                        split (line, ',', temp_array, 2); // split the string with ',' as deliminator
                        temp_authors = temp_array[0]; // author is first element in temp array
                        temp_books = temp_array[1]; // book title is second element in temp arra
                        authors[i] = temp_authors; // pass author name to the array "authors" in the function parameter (at index i)
                        titles[i] = temp_books; // pass book title to the array "titles" in the parameter (at index i)
                        i++; // increment i
                    }
                }
            }
            return i; // return i (equal to number of elements in array)
        }
        else // if numBookStored = size, return - 2
        {
            return -2;
        }
    }
    else // if file did not open successfully - return -1
    {
        return -1;
    }
}
    
/////////////////////////////////// PRINT ARRAY FUNCTION /////////////////////////////////////////////////////////

void printArray (string arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
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