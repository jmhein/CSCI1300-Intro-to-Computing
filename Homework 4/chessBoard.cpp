// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 4 - Problem 4

/* Algorithm: 
    1) Initialize chessBoard function above main, with character variable "character" and integer vairable "number"
Within function:
    2) Conditional if character > h OR < a OR number > 8 OR number < 1, print "Chessboard squares can only have letters between a-h and numbers between 1-8"
    3) Since char variables are assigned a numberic value, we can check if the letter is even or odd
    4) Check if character is even and number is even - if true print black (this covers half of the "black" options, letters b, d, f, h)
    5) Check if character is odd and number is odd - if true print black (this covers the other half of the "black" options, letters a, c, e g)
    6) Else print white (only other options)
*/

#include <iostream> 
#include <math.h>
using namespace std;

// Initialize "chessBoard" function with character and integer input
void chessBoard (char character, int number);

int main () {
    // test 1
    // expected output:
    // black
    chessBoard('g', 5);
    
    // test 2
    // expected output:
    // Chessboard squares can only have letters between a-h and numbers between 1-8
    chessBoard('z', 7);
    
    // test 3
    // expected output
    // Chessboard squares can only have letters between a-h and numbers between 1-8
    chessBoard('a', 10);
    
    // test 4
    // expected output
    // white
    chessBoard('a', 2);
   }

void chessBoard (char character, int number) // Write function below
{ 
    if (character > 'h' || character < 'a' || number > 8 || number < 1) // Conditional if -  inputs between a & h / 1 & 8
    {
        cout << "Chessboard squares can only have letters between a-h and numbers between 1-8" << endl; // print per directions
    }
    else if (remainder(character,2) == 0 && remainder(number,2) == 0) // check if character AND number are even - if true the square is black
    {
        cout << "black" << endl; // print black
    }
    else if (remainder(character,2) != 0 && remainder(number,2) != 0)// check if character AND number are odd - if true the square is black
    {
        cout << "black" << endl; // print black
    }
    else
    {
        cout << "white" << endl; // all other options are white
    }
}