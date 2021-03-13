// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 2

/* Algorithm: 
    1) Prompt user to input a CS course number
    2) Define "course_number" varialbe 
    3) Set user input equal to course_number
    4) Print "Hello, CS [course_number] World!" to screen
*/

#include <iostream> 
using namespace std;

int main () {
    cout << "Enter a CS course number: " << endl; // Prompts user to input the CS course number 
    int course_number; // Defines the variable
    cin >> course_number; // Program waits for user input, and places the input into the course_number variable
    cout << "Hello, CS " << course_number << " World!" << endl; // Prints "Hello, CS [course_number] World!"
}