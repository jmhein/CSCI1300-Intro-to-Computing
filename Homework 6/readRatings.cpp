// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 7

/* Algorithm: 
    1) Initialize readRatings and split functions above main
Within readBooks
    2) Initialize temp variables type string for line, temp_user,and temp_array size 2 and temp variable rating type int
    3) Initialize input stream and open file equal to fileName input parameter
    4) Check if file opened successfully, return -1 if not
    5) Check that number of users stored does not equal max number of rows - return -2 if it does
    6) while getline returns true, check if i is less than max rows and check that line is not empty (nested if), and set i equal to i + number of books
    7) if i < size and line is not empty, split line using ',' deliminator
    8) temp user temp array at position 0
    9) user at index i = temp user
    10) For loop j = 1, j < max columns, j++
    11) Check that line[j] is not empty
    12) temp rating at index j = temp array at index j, converted to integer
    13) ratings[i][j-1] is equal to temp rating
    14) return i
*/
    

#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Initialize "split" function with string and character inputs
int readRatings(string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns);
int split(string sentence, char delim, string mySplits[], int length);
void printStuff (string users[], int ratings[][50], int maxRows, int maxColumns);

int main () 
{
   //test 1
   string users[10] = {};
   int ratings[10][50] = {{0}};
   readRatings("ratings.txt", users, ratings, 0, 10, 50);
   printStuff(users, ratings, 10, 50);
}

int readRatings(string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns)
{
    string line = ""; // temp variable for input stream
    string temp_array[maxColumns + 1]; // temp array to hold split values
    string temp_user; // temp string to hold user name
    int temp_rating; // temp int to hold user rating
    ifstream myfile; // create input stream
    myfile.open(fileName); // open file
    if (numUsers != maxRows) // check that number of users does not equal max rows
    {
        if (myfile.is_open()) // check if file opened successfully
        {
            int i = 0 + numUsers; // index equals 0 plus and users in array
            while (getline(myfile, line)) // while getline returns true
            {
                if (i < maxRows) // probably need to add conditions here
                {
                    if (line != "") // check line is not empty
                    {
                        split(line, ',', temp_array, (maxColumns + 1)); // split line
                        temp_user = temp_array[0]; // user will always be first element 
                        users[i] = temp_user; // user at index i = temp user
                        for (int j = 1; j < maxColumns + 1; j++) 
                        {
                            if (temp_array[j] != "") // if temp array at index j is not blank
                            {
                                temp_rating = stoi(temp_array[j]); // temp rating equal temp array at index j, converted to integer
                                ratings[i][j - 1] = temp_rating; // ratings at index [i][j -1] equals temp rating
                            }
                        }
                        i++; // increment i
                    }
                }
            }
            return i; // return i
        }
        else
        {
            return -1; // return -1 if file did not open successfuclly
        }
    }
    else
    {
        return -2; // return - 2 if number of users equals maximum
    }
}

////////////////////////////// Print Arrays //////////////////////////////////////////////////////

void printStuff (string users[], int ratings[][50], int maxRows, int maxColumns)
{
    for (int i = 0; i < maxRows; i++)
    {
      cout << setw(15) << users[i] << endl;
      // Process the ith row
      for (int j = 0; j < maxColumns; j++)
      {
         cout << setw(2) << ratings[i][j];
      }
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