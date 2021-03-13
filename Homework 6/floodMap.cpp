// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 2

/* Algorithm: 
    1) Initialize floodMap function above main, with type double 2D array, int, and double parameters
Within floodMap:
    1) For loop int i = 0, i < rows, i ++
    2) Nested for loop j = 0, j < 4 (number of columns), j++
    3) if map at index [i][j] is less than or equal to the water level, print "*", otherwise print "_"
*/

#include <iostream> 
#include <string>
using namespace std;

// Initialize function above main
double floodMap(double map [][4], int rows, double waterLevel);


int main () {
    // test 1
    // expected output
    // ____
    double map[1][4] = {7, 8, 10, 15};
    floodMap(map, 1, 5);
    
    // test 2
    // expected output
    // ***_
    double map2[2][4] = {{0.0, 1.0, 2.0, 3.0}, {4.0, 3.0, 2.0, 1.0}};
    floodMap(map2, 1, 2.0);
}

double floodMap(double map [][4], int rows, double waterLevel)
{
    for (int i = 0; i < rows; i++) // for loop index 0, i < rows, i++
    {
        for (int j = 0; j < 4; j++) // for loop index = 0, j < 4 (columns), j++
        {
            if (map[i][j] <= waterLevel) // if map at [i][j] is less than or equal to the water level
            {
            cout << "*"; // print *
            }
            else
            {
                cout << "_"; // print _ if greater than water level
            }
        }
    cout << endl; // next line
    }
}

