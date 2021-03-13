// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 3 - Problem 8

/* Algorithm: 
    1) Define "population" function above the main function
    2) Input variable into population as an integer (call it initial_population)
    3) Calculate births per year as 1 birth per 8 seconds * 60 seconds per minute * 60 minutes per hour * 24 hours per day * 365 days per year (call it births)
    4) Calculate deaths per year as 1 death per 12 seconds * 60 seconds per minute * 60 minutes per hour * 24 hours per day * 365 days per year (call it deaths)
    5) Calculate immigrants per year as 1 immigrant per 27 seconds * 60 seconds per minute * 60 minutes per hour * 24 hours per day * 365 days per year (call it immigrants)
    6) Calculate U.S. Population after one year as population + births + immigrants - deaths (call it ending_population)
    7) Return integer value for ending_population
*/

#include <iostream> 
using namespace std;

// Define population function
int population (int initial_population) { // Function has integer input "population" in parens
    int births = ((1.0 / 8) * 60 * 60 * 24 * 365); // calculates number of births per year
    int deaths = ((1.0 / 12) * 60 * 60 * 24 * 365); // calculates number of deaths per year
    int immigrants = ((1.0 / 27) * 60 * 60 * 24 * 365); // calculates number of immigrants per year
    int ending_population = initial_population + births - deaths + immigrants;
    return ending_population;
}

int main () {
    // test 1
    // expected output:
    // population is: 3482000
    int test1 = population(1000000);
    cout << "population is: " << test1 << endl;
    
    // test 2
    // expected output:
    // population is: 2482000
    int test2 = population(0);
    cout << "population is: " << test2 << endl;
}