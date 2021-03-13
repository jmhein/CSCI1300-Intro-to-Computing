// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 9

/* Algorithm: 
    1) Define "celsiusToFahrenheit" function above the main function (use double)
    2) Input variable into celsiusToFahrenheit as an integer (call it celsius)
    3) Calculate fahrenheit = (9/5) * celsius + 32 (call it fahrenheit)
    4) Print "The temperature of [celsius] in Fahrenheit is [fahrenheit]" (make sure to set precision to 2 decimal places)
*/

#include <iostream> 
#include <iomanip> // Needed for formatting decimal places
using namespace std;

// Define celsiusToFahrenheit function
double celsiusToFahrenheit (int celsius) { // Function has integer input "celsius" in parens
    double fahrenheit = (9.0 / 5) * celsius + 32; // calculates fahrenheit based on celsius input
    cout << fixed << setprecision(2); // fixes output decimals to two places
    cout << "The temperature of " << celsius << " in Fahrenheit is " << fahrenheit << endl; // Prints "The temperature of [celsius] in Fahrenheit is [fahrenheit]"
}

int main () {
    // test 1
    // expected output:
    // The temperature of 38 in Fahrenheit is 100.40
    celsiusToFahrenheit(38);
    
    // test 2
    // expected output:
    // The temperature of 0 in Fahrenheit is 32.00
    celsiusToFahrenheit(0);
}