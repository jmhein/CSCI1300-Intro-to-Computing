// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Project 1 - Problem 1

/* Algorithm: 
    1) Initialize printOddNums function above main, with integer vairable "number"
Within function:
    2) Conditional if number is less than 1 - print nothing (only want positive numbers)
    3) Initialize variable for the start of odd number sequence and set equal to 1 (call it odd_num)
    4) While odd_num <= number - print odd number
    5) odd_num is equal to (odd_num + 2) - the next odd number in the sequence
    6) Loop will repeat until odd_num is greater than number
*/

#include <iostream> 
using namespace std;

// Initialize "printOddNums" function with integer input
int printOddNums(int number);

int main () {
    // test 1
    // expected output:
    // 1
    // 3
    // 5
    // 7
    printOddNums(7); // first function call to test function
    
    // test 2
    // expected output:
    // 
    printOddNums(-10); // second function call to test function
}

int printOddNums(int number)
{
    int odd_num = 1; // start of odd number sequence
    if (number < 1) // conditional for any arguements entered less than 1 (only want positive numbers)
    {
        cout << " " << endl; // print nothing
    }
    else // all other options
    {
        while (odd_num <= number) // while odd_num is less than or equal to input arguement "number"
        {
            cout << odd_num << endl; // print odd_num
            odd_num = (odd_num + 2); // odd number = previous value + 2
        }
    }
}