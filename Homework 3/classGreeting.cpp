// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 3

/* Algorithm: 
    1) Define "classGreeting function" above the main function
    2) Input variable into classGreeting as an integer (call it course_number)
    3) Print Hello, CS [course_number] World!
    4) Main function calls classGreeting(course_number) with two test cases
*/

#include <iostream> 
using namespace std;

// Define classGreeting function
void classGreeting (int course_number) { // Funtion has integer input in parens
    cout << "Hello, CS " << course_number << " World!" << endl; // Prints to screen "Hello, CS **** World!"
}

int main () {
    // test 1
    // expected output:
    // Hello, CS 1300 World!
    classGreeting(1300); // first function call to classGreeting()
    
    // test 2
    // expected output:
    // Hello, CS 1200 World!
    classGreeting(1200); // second funtion call to classGreeting()
}