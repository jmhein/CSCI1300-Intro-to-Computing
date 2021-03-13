// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 9 - Problem 2

/* Algorithm: 
    1) initialize string variable to store remainders [endString]
    2) if input is less than or equal to 1, add the input to the beginning of endString and return endString
    3) otherwise, endString = remainder of a/2 plus endString
    4) c = a / 2
    5) return decimalToBinaryRecursive(c) + endString
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

string decimalToBinaryRecursive(int a);

int main()
{
   // test1
   // expected output:
   // 101
   string output = decimalToBinaryRecursive(5);
   cout << output << endl;
   
   // test2
   // expected output:
   // 101
   string output2 = decimalToBinaryRecursive(26);
   cout << output2 << endl;
   
   // test3
   // expected output:
   // 0
   string output3 = decimalToBinaryRecursive(0);
   cout << output3 << endl;
   
}

string decimalToBinaryRecursive(int a)
{
   string endString; // string variable to return
   if (a <= 1)
   {
      endString = to_string(a) + endString; // add input to beginning of string
      return endString; // return the end string
   }
   else
   {
      endString = to_string(a%2) + endString; // add remainder of a / 2
      int c = a/2; // c = a / 2
      return decimalToBinaryRecursive(c) + endString; // return recursive function + endString
   }
}