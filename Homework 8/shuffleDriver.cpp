// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 8 - Problem 1

/* Algorithm: 
    1) initilized newVector to be returned
    2) check which vector is largest and alternate passing values to newVector, starting with the largerst vector, to the new vector using a for loop
    3) once there are no more elements in the smallest vector, pass the remaning elements in the larger one to the new vector
    4) return the new vector
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <fstream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int> v1, vector<int> v2);

int main()
{
    // test 1
    // expected output:
    // 2 1 4 3 6 5 8 9 10
    vector<int> v1{1,3,5,9};
    vector<int> v2{2,4,6,8,10};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) 
    {
     cout << v3[i] << " ";
    }
    
    // test 1
    // expected output:
    // 
    vector<int> v4;
    vector<int> v5;
    vector<int> v6 = shuffle(v4,v5); // test return value for empty vectors
    for (int i=0; i < v6.size(); i++) 
    {
     cout << v6[i] << " ";
    }
}

vector<int> shuffle(vector<int> v1, vector<int> v2)
{
    vector<int> newVector; // vector to be returned by function
    if (v1.size() >= v2.size()) // check which vector is the largest
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (i < v2.size()) // if i is less than the smallest vector
            {
                newVector.push_back(v1[i]); // add v1 at index i to newVector
                newVector.push_back(v2[i]); // add v2 at index i to newVector
            }
            else // once i is greater than the smallest vector
            {
                newVector.push_back(v1[i]); // add remaining elements of larger vector to newVector
            }
        }
    }
    else // inverse of if v1 > v2
    {
        for (int i = 0; i < v2.size(); i++)
        {
            if (i < v1.size())
            {
                newVector.push_back(v2[i]);
                newVector.push_back(v1[i]);
            }
            else
            {
                newVector.push_back(v2[i]);
            }
        }
    }
    return newVector; // return the new vector
}