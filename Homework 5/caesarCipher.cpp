// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 5 - Problem 4

/* Algorithm: 
    1) Initialize caesarCipher function above main, with string int and bool inputs
Within split:
    2) Initialize string 'final_message' and char cipher variables
    3) if key input is less than 0 or greater than 25 - final message = "ERROR" per directions
    4) else if flag is true ENCODING - else DECODING
    5) for loop - start at index zero and check every character
    6) if message[i] is blank space - keep character as blank space and add to final_message variable
    7) else if message[i] + key is greater than 'Z' - need to move back to 'A' (steps to compute below:)
               - cipher = message[i] + ('Z' - message[i]); // cipher equal to 'Z' after this line
               - cipher = cipher - ('Z' - 'A' + 1); // ciper equal 'A' after this line
               - cipher = cipher + (move - ('Z' - message[i])); // ciper = 'A' + remainder of moves
               - final_message = final_message + cipher; // final message = final message + cipher character
    8) else cipher = message[i] + key
    9) add cipher to final_message
    10) DECODING is inverse of ENCODING
    11) return final message
*/

#include <iostream> 
#include <string>
using namespace std;

// Initialize "split" function with string and character inputs
string caesarCipher(string message, int key, bool flag);

int main () {
    // test 1
    // expected output:
    // CDEF
    string test1 = caesarCipher("ABCD", 2, true); // first function call to test
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // YZAB
    string test2 = caesarCipher("ABCD", 2, false); // first function call to test
    cout << test2 << endl;
    
    // test 3
    // expected output:
    // ERROR
    string test3 = caesarCipher("THE LARGE BUS", 28, false); // first function call to test
    cout << test3 << endl;
   }

string caesarCipher(string message, int key, bool flag) // Write function below
{ 
   string final_message = ""; // variable for message to be returned
   char cipher;
   if (key < 0 || key > 25) // check if key is between zero and 25
   {
       final_message = "ERROR"; // if true, final message = "ERROR"
   }
   else if (flag == 1) // ENCODING
   {
       for (int i = 0; i < message.length(); i ++) // for loop - start at index zero and check every character
       {
           if (message[i] == ' ') // if message[i] is blank space, leave as blank space
           {
               final_message = final_message + message[i];
           }
           else if (message[i] + key > 'Z') // else if message[i] plus key length  is greater than 'Z' - need to move from 'Z' to 'A'
           {
               cipher = message[i] + ('Z' - message[i]); // cipher equal to 'Z' after this line
               cipher = cipher - ('Z' - 'A' + 1); // ciper equal 'A' after this line
               cipher = cipher + (key - ('Z' - message[i])); // cipher equal 'A' + remainder of key
               final_message = final_message + cipher; // final message = final message + cipher
           }
           else // message[i] + key <= 'Z'
           {
               cipher = message[i] + key; // cipher = current character + key
               final_message = final_message + cipher; // final message = final message + current character
           }
       }
   }
   else // DECODING
   {
       for (int i = 0; i < message.length(); i ++) // for loop - start at index zero and check every character
       {
           if (message[i] == ' ') // if message[i] is blank space, leave as blank space
           {
               final_message = final_message + message[i];
           }
           else if (message[i] - key < 'A') // else if message[i] less key length is less than 'A' - need to move from 'A' to 'Z' (inverse of previous section)
           {
               cipher = message[i] - (message[i] - 'A'); // cipher equal to 'A' after this line
               cipher = cipher + ('Z' - 'A' + 1); // ciper equal 'Z' after this line ('Z' - 'A' = 25 +1 = 26)
               cipher = cipher - (key - (message[i] - 'A')); // cipher equal 'Z' - remainder of key
               final_message = final_message + cipher; // final message = final message + cipher
           }
           else // message[i] - key >= 'A'
           {
               cipher = message[i] - key; // cipher = current character + key
               final_message = final_message + cipher; // final message = final message + current character
           }
        }
   }
   return final_message; // return final message
}