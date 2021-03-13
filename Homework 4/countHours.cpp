// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 4 - Problem 6

/* Algorithm: 
    1) Initialize countHours function above main, with integer vairable "number"
Within function:
    2) Set integer variable "hours" equal to 24
    3) Switch conditional 1 - 12 (representing months in a year), and each equal to hours = hours * [days in month]
*/

#include <iostream> 
using namespace std;

// Initialize "countHours" function withinteger input
int countHours(int number);

int main () {
    // test 1
    // expected output:
    // 744
    int test1 = countHours(3);
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // 672
    int test2 = countHours(2);
    cout << test2 << endl;
    
    // test 3
    // expected output:
    // 720
    int test3 = countHours(6);
    cout << test3 << endl;
}

int countHours(int number)
{
    int hours = 24;
    switch(number)
    {
        case 1: hours = hours * 31; // January - 31 days * 24 hours per day
            break;
        case 2: hours = hours * 28; // February - 28 days * 24 hours per day
            break;
        case 3: hours = hours * 31; // March - 31 days * 24 hours per day
            break;
        case 4: hours = hours * 30; // April - 30 days * 24 hours per day
            break;
        case 5: hours = hours * 31; // May - 31 days * 24 hours per day
            break; 
        case 6: hours = hours * 30; // June - 30 days * 24 hours per day
            break;
        case 7: hours = hours * 31; // July - 31 days * 24 hours per day
            break;
        case 8: hours = hours * 31; // August - 31 days * 24 hours per day
            break;
        case 9: hours = hours * 30; // September - 30 days * 24 hours per day
            break;
        case 10: hours = hours * 31; // October - 31 days * 24 hours per day
            break;
        case 11: hours = hours * 30; // November - 30 days * 24 hours per day
            break;
        case 12: hours = hours * 31; // December - 31 days * 24 hours per day
            break;
        default: cout << "Enter a month 1-12" << endl; // Default need a number 1 - 12 corresponding to months in a year
    }
}