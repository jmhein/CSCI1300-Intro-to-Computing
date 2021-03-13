// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 5 - Problem 5

/* Algorithm: 
    1) Initialize vigenereCipher function above main, with string and character inputs
Within split:
    2) Initialize final message, cipher, move, and int k = 0 variables (string, char, int, int type respectively)
    3) if flag is true - ENCODING, else DECODING
    4) for loop index equal to zero, while i < sentence length, increment by 1
    5) move = key[k % key.length] (k = remainder of k / key length - ensures cipher will repeat at start of key word once it reaches end)
    6) if message[i] = ' ' - keep the character as a blank space and decrease k by one (or else the program will skip a letter in the key word)
    7) if message[i] + move is greater than 'Z' - need to move back to 'A' (steps to compute below:)
               - cipher = message[i] + ('Z' - message[i]); // cipher equal to 'Z' after this line
               - cipher = cipher - ('Z' - 'A' + 1); // ciper equal 'A' after this line
               - cipher = cipher + (move - ('Z' - message[i])); // ciper = 'A' + remainder of moves
                - final_message = final_message + cipher; // final message = final message + cipher character
    8) if message[i] + move is not greater than 'Z' - chiper = character at message[i] + move number
    9) final_message - final_message + cipher
    10) ELSE - move calculation for DECODING is inverse of ENCODING - rest is the same
*/

#include <iostream> 
#include <string>
using namespace std;

// Initialize "vigenereCipher" function with string, string, and bool inputs
string vigenereCipher(string message, string key, bool flag);

int main () {
    // test 1
    // expected output:
    // NVOGFKVY
    string test1 = vigenereCipher("UNICORNS", "TIGER", true); // first function call to test
    cout << test1 << endl;
    
    // test 2
    // expected output:
    // UNICORNS
    string test2 = vigenereCipher("NVOGFKVY", "TIGER", false); // first function call to test
    cout << test2 << endl;
    
    // test 3
    // expected output:
    // B TOOV VPUGFEIZI
    string test3 = vigenereCipher("I LIKE CHOCOLATE", "TIGER", true); // first function call to test
    cout << test3 << endl;
    
   }

string vigenereCipher(string message, string key, bool flag) // Write function below
{ 
   string final_message = ""; // initialize output string and set equal to nothing to start
   char cipher; // initialize cipher character
   int move; // initialize move (will be used in conditionals to direct whether moving up or down alphabet)
   int k = 0;
   if (flag == 1) // ENCODING
   {
       for (int i = 0; i < message.length(); i++) // for loop - start at index zero and check every character
       {
           move = key[k % key.length()] - 'A'; // calculates number of spaces on alphabet to move
           k++; // k + 1
           if (message[i] == ' ') // if character at [i] is blank space
           {
               final_message = final_message + message[i]; // final message = final message + empty character
               k--; // k - 1 (can't skip a letter on the key word)
           }
           else if (message[i] + move > 'Z') // if original position + move is greater than 'Z' - Need to start back at 'A'
           {
               cipher = message[i] + ('Z' - message[i]); // cipher equal to 'Z' after this line
               cipher = cipher - ('Z' - 'A' + 1); // ciper equal 'A' after this line
               cipher = cipher + (move - ('Z' - message[i])); // ciper = 'A' + remainder of moves
               final_message = final_message + cipher; // final message = final message + cipher character
           }
           else // if message[i] + move !> Z
           {
               cipher = message[i] + move; // cipher = character at [i] + spaces moved
               final_message = final_message + cipher;   // final message = final message + cipher character
           }
       }
   }
   else // DECODING
   {
       for (int i = 0; i < message.length(); i++)
       {
           move = 'Z' - key[k % key.length()] + 1; // calculates number of spaces moved
           k++; // k + 1
           if (message[i] == ' ')
           {
               final_message = final_message + message[i]; // final message = final message + empty character
               k--; // k - 1 (can't skip a letter on the key word)
           }
           else if (message[i] + move > 'Z') // if original position + move is greater than 'Z' - Need to start back at 'A'
           {
               cipher = message[i] + ('Z' - message[i]); // cipher equal to 'Z' after this line
               cipher = cipher - ('Z' - 'A' + 1); // ciper equal 'A' after this line
               cipher = cipher + (move - ('Z' - message[i])); // ciper = 'A' + remainder of moves
               final_message = final_message + cipher; // final message = final message + cipher character
           }
           else
           {
               cipher = message[i] + move; // cipher = character at [i] + spaces moved
               final_message = final_message + cipher; // final message = final message + cipher character
           }
       }
   }
   return final_message; // return final message
}