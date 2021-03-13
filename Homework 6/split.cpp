// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 3

/* Algorithm: 
    1) Initialize split function above main, with string and character inputs
Within split:
    2) Initialize count and and word variables (int and string, respectively)
    3) sentence = sentence + deliminator (to pick up remaining characters after last deliminator)
    4) for loop index equal to zero, while i < string length, increment by 1
    5) if count is less than length - do stuff; otherwise return -1
    5) nested if sentence[i] = deliminator - check if (nested if) word length is > 0
    6) if so, print the value of word, and increment count variable
    7) reset word to ""
    8) else (sentence[i] != deliminator) - word = word + sentence[i]
*/

#include <iostream> 
#include <string>
using namespace std;

// Initialize "split" function with string and character inputs
int split(string sentence, char delim, string mySplits[], int length);
int printArray (string mySplits[], int length);

int main () {
    // test 1
    // expected output:
    // 3
    // Strings
    // are
    // fun
    string myarray[6];
    cout << split("Strings are fun", ' ', myarray, 6) << endl;
    printArray(myarray, 6);
    
    // test 2
    // expected output:
    // -1
    // Strings
    // are
    // fun
    // and 
    // this
    // homework
    string myarray2[6];
    cout << split("Strings are fun and this homework is really hard", ' ', myarray2, 6) << endl;
    printArray(myarray2, 6);
   }

int split(string sentence, char delim, string mySplits[], int length) // Write function below
{ 
    int count = 0; // initilize count variable
    string word = ""; // temp string to hold word
    sentence = sentence + delim; // adds delim to end of string in order to pick up last word in sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        if (count < length) // if count is less than length
        {
            if (sentence[i] == delim) // if character at index i = delim
            {
                if (word.length() > 0) // check if word length is greater than 0
                {
                    mySplits[count] = word; // if true, mySplits at index count is equal to word
                    count ++; // count plus 1
                }
                word = ""; // reset word variable
            }
            else
            {
            word = word + sentence[i]; // if character is not = to delim, word = previous characters + character at index #
            }
        }
        else
        {
            return -1; // if count is >= length, return -1
        }
    }
    return count; // return count
}

int printArray (string mySplits[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << mySplits[i] << endl;
    }
}