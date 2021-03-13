// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 7

/* Algorithm: 
    1) Define "convertSeconds" function above the main function
    2) Input seconds into convertSeconds as an integer (call it seconds)
    3) Calculate hours as an integer equal to seconds / 60 seconds per minute / 60 minutes per hour (call it hours)
    4) Calculate minutes as an integer equal to (seconds / 60 seconds per minutes) - (hours * 60 minutes per hour) (call it minutes)
    5) Calculate seconds as an integer equal to (seconds) - (minutes * 60 seconds per minute) - (hours * 60 * 60) (seconds already defined as a variable)
    6) Print string as **hour(s) **minutes(s) **second(s)
    7) Main function calls convertSeconds(seconds) with two test cases
*/

#include <iostream> 
using namespace std;

// Define convertSeconds function
void convertSeconds (int seconds) { // Function has integer input "seconds" in parens
    int hours = seconds / 60 / 60; // calculates number of hours based on seconds input
    int minutes = (seconds / 60) - (hours * 60); // calculates number of minutes less number of hours
    seconds = (seconds) - (minutes * 60) - (hours * 60 * 60); // calculates number of seconds less minutes and hours
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s)" << endl; // Prints to screen "**hour(s) **minutes(s) **second(s)"
}

int main () {
    // test 1
    // expected output:
    // 1 hour(s) 1 minute(s) 1 second(s)
    convertSeconds(3661); // first function to call convertSeconds()
    
    // test 2
    // expected output:
    // 146 hour(s) 0 minute(s) 0 second(s)
    convertSeconds(525600); // second funtion to call convertSeconds()
}