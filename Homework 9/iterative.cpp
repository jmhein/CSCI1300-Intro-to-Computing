// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 9 - Problem 1

/* Algorithm: 
    1) initialize a vector to store the binary remainders, a string to be returned, and a temp string to pass the remainders into the vector
    2) check if input is 0 - if so return string 0
    3) otherwise - check if input is positive, enter while loop while input >= 1
    4) set temp == remainder of input divided by 2
    5) store remainder in vector
    6) set input = input / 2
    7) set the string to be returned equal to [endString] + vector at index i (for loop starting at the end of the vector and working towards the first)
    8) return endString
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

string decimalToBinaryIterative(int a);

int main()
{
   // test1
   // expected output:
   // 101
   string output = decimalToBinaryIterative(5);
   cout << output << endl;
   
   // test2
   // expected output:
   // 11010
   string output2 = decimalToBinaryIterative(26);
   cout << output2 << endl;
   
   // test3
   // expected output:
   // 0
   string output3 = decimalToBinaryIterative(0);
   cout << output3 << endl;
   
}

string decimalToBinaryIterative(int a)
{
   vector<string> binary; // vector to store each binary string
   string endString; // variable to return from function
   string temp = ""; // temp variable to store remainder
   if (a == 0) // check if input is 0
   {
      endString = "0"; // if so return 0 as a string
   }
   else if (a >= 1) // otherwise if a is a positive integer
   {
      while (a >= 1) // while a is greater than or equal to 1
      {
         temp = to_string(a%2); // temp = remainder of a / 2 - converted to string
         binary.push_back(temp); // add string to vector
         a = a/2; // recalculate a
      }
      for (int i = (binary.size() - 1); i >= 0; i--)
      {
         endString = endString + binary[i]; // endString = the reverse of the variables stored in the vector
      }
   }
   return endString; // return the ending string
}