// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 1

/* Algorithm: 
    1) Initialize temps array, type double, size 9
    2) For loop, while index < 10, temps[i] = -459.67, increment i by 1 and print temps[i]
    3) Initialize colors array, type string to {"Red, "Blue", "Green", "Cyan", "Magenta"}
    4) for index < 5 - print colors[i]
    5) Initialize sequence array, type double, size 100
    6) for index < 100, sequence[i] = i + 1; increment i - print sequence[i]
    7) Initialize letters array, type character
    8) For loop - i < 26, icrement i
    9) letters[i] = 'A' + i; letters[i + 1] = 'a' + i
    10) Print letters[i] and letters[i + 1]
*/

#include <iostream> 
#include <string>
using namespace std;

int main () {
    double temps [9]; // Initialize temps array, type double
    for (int i = 0; i < 10; i++) // for loop while i < 10
    {
        temps[i] = -459.67; // temps at position i = -459367
        cout << temps[i] << endl; // print temps at position i
    }
    cout << endl; // empty line, per format provided
    string colors [5] = {"Red", "Blue", "Green", "Cyan", "Magenta"}; // initialize colors array, type string and populate with colors provided
    for (int i = 0; i < 5; i++) // for loop, i < 5
    {
        cout << colors[i] << endl; // print the color at position i
    }
    cout << endl; // empty line per format provided
    int sequence [100]; // initialize sequence array, type integer
    for (int i = 0; i < 100; i++) // for loop while i is less than 100
    {
        sequence[i] = i + 1; // sequence at position i is equal to i + 1
        cout << sequence[i] << endl; // print sequence at position i
    }
    cout << endl; // empty line per format provided
    char letters [26]; // initialize letters array, type character
    for (int i = 0; i < 26; i++) // for loop while i is less than 26 (26 letter in alphabet)
    {
        letters [i] = 'A' + i; // letters at position i is euqal to 'A' + i (will increment 26 times, starting at 'A' + 0)
        letters [i + 1] = 'a' + i; // letters at position i + 1 is equal to 'a' + i (will increment 26 times, starting at 'a' + 0)
        cout << letters[i] << " " << letters[i + 1] << endl; // print letters at i and i +1
    }
}