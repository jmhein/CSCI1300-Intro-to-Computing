// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 5 - Problem 3

/* Algorithm: 
    1) Initialize split function above main, with string and character inputs
Within split:
    2) Initialize count and and word variables (int and string, respectively)
    3) sentence = sentence + deliminator (to pick up remaining characters after last deliminator)
    4) for loop index equal to zero, while i < string length, increment by 1
    5) if sentence[i] = deliminator - check if (nested if) word length is > 0
    6) if so, print the value of word, and increment count variable
    7) reset word to ""
    8) else (sentence[i] != deliminator) - word = word + sentence[i]
*/

#include <iostream> 
#include <string>
using namespace std;

// Initialize "split" function with string and character inputs
int split(string sentence, char delim);

int main () {
    // test 1
    // expected output:
    // Strings
    // are
    // fun
    // 3
    int test1 = split("Strings are fun", ' '); // first function call to test
    cout << test1 << endl;
    
    // test 
    // expected output:
    // u
    // i
    // te
    // tio
    // ally
    // 5
    int test2 = split("unintentionally", 'n'); // first function call to test
    cout << test2 << endl;
   }

int split(string sentence, char delim) // Write function below
{ 
    int count = 0; // initilize count variable
    string word = ""; // temp string to hold word
    sentence = sentence + delim; // adds delim to end of string in order to pick up last word in sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == delim) // if character at index i = delim
        {
            if (word.length() > 0) // check if word length is greater than 0
            {
                cout << word << endl; // if true, print word
                count ++; // count plus 1
            }
            word = ""; // reset word
        }
        else
        {
        word = word + sentence[i]; // if character is not = to delim, word = previous characters + character at index #
        }
    }
    return count; // return the count
}