// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 4 - Problem 7

/* Algorithm: 
    1) Initialize checkLeapYear function above main, as bool operator, with integer vairable "year"
Within function:
    2) Conditional if year greater than 1582 AND divisible by 100 AND not divisible by 400 - return 0 (false)
    3) return true if year is divisble by 4
*/

#include <iostream> 
using namespace std;

// Initialize "checkLeapYear" function with integer input
bool checkLeapYear(int year);

int main () {
    // test 1
    // expected output:
    // 0
    int test1 = checkLeapYear(1900);
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // 1
    int test2 = checkLeapYear(2000);
    cout << test2 << endl;
}

bool checkLeapYear(int year) // bool function
{
    if (year > 1582 && (year % 100) == 0 && (year % 400) != 0) // if year is divisible by 100 and not divisible 400, it is not a leap year
    {
        return 0; // return false
    }
    return (year % 4) == 0; // if divisible by 4 it is a leap year (true)
}