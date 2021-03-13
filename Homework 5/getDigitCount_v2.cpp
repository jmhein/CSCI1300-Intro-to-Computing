// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 5 - Problem 1

/* Algorithm: 
    1) Initialize getDigitCount function above main, with string input
Within getDigitCount:
    2) initalize count variable
    3) for loop index equal to zero, while i < string length, increment by 1
    4) if str[i] is between '0' and '9', increment count by 1
    5) return count
*/

#include <iostream> 
#include <string>
using namespace std;

// Initialize "getDigitCount" function with three double inputs
int getDigitCount (string str);

int main () {
    // test 1
    // expected output:
    // 3
    int test1 = getDigitCount("sdfa54dsf6"); // first function call to test
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // 8
    int test2 = getDigitCount("!lkj=55dfs66777sdf9"); // first function call to test
    cout << test2 << endl;
   }

int getDigitCount (string str) // Write function below
{ 
    int count = 0; // initalize count variable
    for (int i = 0; i < str.length(); i++) // for loop - while index is less than string lenght - run code and increase index by 1
    {
        if (str[i] >= '0' && str[i] <= '9') // if str[i] (will run 0, 1, 2, 3...etc) is between '0' and '9' 
        {
            count++; // increment count by 1
        }
    }
    return count; // return count
}