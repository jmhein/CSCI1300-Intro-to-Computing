// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 4

/* Algorithm: 
    1) Initialize getLinesFromFile function with string fileName, int arr[], and int length parameters
Within getLinesFromFile
    2) Initialize "line" variable type string
    3) Create input stream variable and open file = fileName input variable
    4) Check if file opens successfully - return -1 if not
    5) While getline function returns true, check if index i is less than length
    6) nested if the line is not empty - arr at index i is equal to the line converted to integer
    7) Return i
*/

#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

// Initialize functions with string int array and int length variables
int getLinesFromFile(string fileName, int arr[], int length);
int printArray (int arr[], int length);

int main () 
{
    // test1
    int arr[5];
    cout << getLinesFromFile("test1.txt", arr, 5) << endl;
    printArray(arr, 5);
    
    // test2
    int arr2[10];
    cout << getLinesFromFile("test2.txt", arr2, 10) << endl;
    printArray(arr2, 10);
}

int getLinesFromFile(string fileName, int arr[], int length) // Write function below
{ 
    string line = ""; // initializ line variable
    ifstream myfile; // create input stream
    myfile.open(fileName); //open my file
    if (myfile.is_open()) // check if file opened successfully
    {
       int i = 0; // initialize variable i (to count)
       while(getline(myfile, line)) // while getline function returns true
       {
           if (i < length) // if i is less than length - do stuff
           {
               if (line != "") // if line is not empty
               {
                   arr[i] = stoi(line); // array at position i = line
                   i++; // increment i
               }
           }
       }
       return i; // return i
    }
    else
    {
        return -1; // return -1 if file does not open successfully
    }
}
    

int printArray (int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
}