// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 7

/* Algorithm: 
    1) Initialize readRatings and split functions above main
Within readBooks
    2) Initialize temp variables type string for line, temp_array size maxCol + 1, temp ratings array type int, temp user type User, and temp string for username
    3) Initialize input stream and open file equal to fileName input parameter
    4) Check that number of users stored does not equal max number of rows - return -2 if it does
    5) Check if file opened successfully, return -1 if not
    6) while getline returns true, check if i is less than max rows and check that line is not empty (nested if), and set i equal to i + number of books
    7) if i < size and line is not empty, split line using ',' deliminator
    8) temp username is equal to first elememt in temp array
    9) use for loop to convert ratings in temp array to integers, and pass to temp ratings array (type int)
    10) use parameterized "User" type to set temp_user = (temp username, temp ratings array, max columns)
    11) Pass temp_user to userArray at index i 
    12) increment i
    13) return i
*/
    
#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>
#include "User.h" // include header file
using namespace std;

// Initialize functions above main
int readRatings(string fileName, User userArray[], int numUsersStored, int userArraySize, int maxCol);
int split(string sentence, char delim, string mySplits[], int length);

int main () 
{
   // test 1
   // expected output
   // see ratings.txt file
   User ratings[100];
   readRatings("ratings.txt", ratings, 0, 100, 50);
   for (int i = 0; i < 100; i++)
   {
       cout << ratings[i].getUsername();
       for (int j = 0; j < 50; j++)
       {
           cout << ratings[i].getRatingAt(j);
       }
       cout << endl;
   }
   
   // test 2
   // expected output
   // -2
   cout << readRatings("ratings.txt", ratings, 100, 100, 50) << endl; // function call - test -2 return value
}

int readRatings(string fileName, User userArray[], int numUsersStored, int userArraySize, int maxCol)
{
    string line = ""; // temp variable for input stream
    string temp_array[maxCol + 1]; // temp array to hold split values
    int temp_ratings[maxCol]; // temp array to hold integer-type ratings
    User temp_user; // temp User variable to pass into userArray
    string temp_username; // temp string to hold username and pass to temp user
    ifstream myfile; // create input stream
    myfile.open(fileName); // open file
    if (numUsersStored != userArraySize) // check that number of users does not equal max rows
    {
        if (myfile.is_open()) // check if file opened successfully
        {
            int i = 0 + numUsersStored; // index equals 0 plus and users in array
            while (getline(myfile, line)) // while getline returns true
            {
                if (i < userArraySize) // check if i is less than user array size - if true do stuff
                {
                    if (line != "") // check line is not empty
                    {
                        split(line, ',', temp_array, (maxCol + 1)); // split line
                        temp_username = temp_array[0]; // username will always be first element
                        for (int j = 0; j < maxCol; j++)
                        {
                            if (temp_array[j + 1] != "") // check that rating is not blank
                            {
                                temp_ratings[j] = stoi(temp_array[j + 1]); // convert rating in temp array to type integer
                            }
                        }
                        temp_user = User(temp_username, temp_ratings, maxCol); // pass username and ratings to temp user variable
                        userArray[i] = temp_user; // userArray at index i = temp user
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