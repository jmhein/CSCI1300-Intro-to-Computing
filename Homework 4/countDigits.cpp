// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 4 - Problem 5

/* Algorithm: 
    1) Initialize countDigits function above main, with integer vairable "number"
Within function:
    2) Take absolute value of number (otherwise string will count the negative sign as a digit)
    3) Convert integer "number" to a string (call the string digits)
    4) Define integer variable num_digits equal to the lenght of the string "digits"
    5) Return num_digits integer
*/

#include <iostream> 
#include <string>
#include <math.h>
using namespace std;

// Initialize "countDigits" function withinteger input
int countDigits(int number);

int main () {
    // test 1
    // expected output:
    // 3
    int test1 = countDigits(100);
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // 2
    int test2 = countDigits(-10);
    cout << test2 << endl;
    
    // test 3
    // expected output:
    // 4
    int test3 = countDigits(1000);
    cout << test3 << endl;
}

int countDigits(int number)
{
    number = abs(number); // absolute value of number input
    string digits = to_string(number); // convert integer "number" to a string (called digits)
    int num_digits = digits.length(); // sets number of digits ("num_digits") equal to the length of the digits string
    return num_digits; // returns the number of digits as an integer
}