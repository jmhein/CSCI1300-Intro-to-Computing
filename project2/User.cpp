// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Project 2

/* Algorithm: 
    1) Implementation file - default constructor sets username to "", numRatings to 0, size to 50, and each element in ratings array to 0
    2) Paramaterized constructor
        - set username equal to input string name
        - set size equal to 50
        - if number of books (ie number of ratings) is less than the size, numRatings = numBooks
        - for index = 0, if index is less than numRatings ratings at index i is equal to input array at index i
        - if index is >= numRatings - rest of elements equal zero
        - else (numRatings >= size), numRatings = size and each element in ratins array equal to elements in input array at index i
    3) setUsername = username equal to input string
    4) setRatingAt - if index is less than size of array, and rating is between 0 and 5, ratings at index = value, return true, else return false
    5) setNumRatings - if input number is less than size, numRatings = input value
    6) getRatingAt - if index is less than size - return rating at index, else return -1
    7) getNumRatings - return numRatings
    8) getUsername - return username
    9) getSize - return size
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "User.h" // include header file
using namespace std;

// Implementation file

User::User()
{
    username = ""; // username to empty
    numRatings = 0; // numRatings to 0
    for (int i = 0; i < size; i++)
    {
        ratings[i] = 0; // rating at index i = 0
    }
}

User::User(string name, int bookRatings[], int numBooks)
{
    username = name; // username equal to name
    numRatings = 0;
    if (numBooks < size) // if numBooks is less than size
    {
        for (int i = 0; i < size; i++)
        {
           if (i < numBooks)
           {
               ratings[i] = bookRatings[i]; // ratings at i = input array at i while i is less than number of ratings
           }
           else
           {
               ratings[i] = 0; // all other values are zero
           }
           if (ratings[i] != 0)
           {
               numRatings++; // count ratings that do not equal 0
           }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            ratings[i] = bookRatings[i]; // ratings at index j = bookRatings at index j
            if (ratings[i] != 0)
            {
                numRatings++; // count ratings that do not equal 0
            }
        }
    }
}

void User::setUsername(string name)
{
    username = name; // username = name
}

void User::setNumRatings(int numBooks)
{
    if (numBooks < size) // if numBooks < size
    {
        numRatings = numBooks; // numRatins = numBooks
    }
}

bool User::setRatingAt(int index, int value) // return true / false
{
    if (index < size && value >= 0 && value <= 5)
    {
        ratings[index] = value; // if index is less than size and value between 0 and 5 - set ratings at index equal to value
        return true; // return true
    }
    else
    {
        return false; // return false if above parameters are not met
    }
}

int User::getRatingAt(int index)
{
    if (index < size)
    {
        return ratings[index]; // if index is within bounds of array - return value at index number
    }
    else
    {
        return -1; // otherwise return -1
    }
}

int User::getNumRatings()
{
    return numRatings; // return numRatings
}

string User::getUsername()
{
    return username; // return username
}

int User::getSize() 
{
    return size; // return size
}

