// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 5 - Problem 2

/* Algorithm: 
    1) Initialize getWordCount function above main, with string input
Within getWordCount:
    2) Initialize count and word variables as integers and set equal to zero
    3) Conditional if first character in string is empty character - return words (assumes an actual sentence doesn't start with an empty space)
    4) else - for loop index equal to zero, while i < string length, increment by 1
    5) if sentence[i] = ' ', count++ and words = count +1
    6) else if count == 0 (no empty characters) words = 1
    7) return words
*/

#include <iostream> 
#include <string>
using namespace std;

// Initialize "getWordCount" function with three double inputs
int getWordCount(string sentence);

int main () {
    // test 1
    // expected output:
    // 0
    int test1 = getWordCount(" "); // first function call to test
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // 5
    int test2 = getWordCount("The big dog ran slowly"); // second function call to test
    cout << test2 << endl;
   }

int getWordCount(string sentence) // Write function below
{ 
    int count = 0; // initilize count variable (count empty characters)
    int words = 0; // initilize words variable
    if (sentence[0] == ' ') // If first character is empty space
    {
        return words; // return words = 0
    }
    else // all other options
    {
        for (int i = 0; i < sentence.length(); i++) // for loop - run iteration equal to lenght of input string
        {
            if (sentence[i] == ' ') // if index i is empty character
            {
                count++; // increment count
                words = count + 1; // words equals number of spaces + 1
            }
            else if (count == 0) // if count is zero
            {
                words = 1; // there is a single word
            }
        }
    }
    return words; // return number of words
}