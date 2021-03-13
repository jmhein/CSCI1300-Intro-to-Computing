// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 5 - Problem 6

/* Algorithm: 
    1) Initialize split function above main, with string and character inputs

*/

#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// Initialize "split" function with string and character inputs
int getRating(string username, string booktitle, string users[], string titles[], int ratings[][50], int numUsers, int numBooks);
int split(string sentence, char delim, string mySplits[], int length);
void printStuff (string users[], int ratings[][3], int maxRows, int maxColumns);

int main () 
{
   //test 1
   // expected output
   // 3
   string users[4] = {"User1", "User2", "User3", "User4"};
   string titles[3] = {"Title1", "Title2", "Title3"};
   int ratings[100][50] = {{1,4,2},{0,5,3}};
   cout << getRating("User2", "Title3", users, titles, ratings, 2, 4) << endl;
   
   //test 2
   // expected output
   // 4
   string users2[2] = {"User1", "User2"};
   string titles2[3] = {"Title1", "Title2", "Title3"};
   int ratings2[2][50] = {{1,4,2},{0,5,3}};
   cout << getRating("User1", "Title2", users2, titles2, ratings2, 1, 2) << endl;
}

int getRating(string username, string booktitle, string users[], string titles[], int ratings[][50], int numUsers, int numBooks)
{
    string temp_user = ""; // string to store temporary user
    string temp_title = ""; // string to store temporary title
    int rowCount = 0; // count rows
    int columnCount = 0; // count columns
    while (username != temp_user && rowCount < numUsers) // while username does not equal temp user AND rowCount is less than number of users
    {
        for (int i = 0; i < username.length(); i++) // for loop - index 0, index less than lenght of username, increment index by 1
        {
            username[i] = tolower(username[i]); // convert username to all lower case chracters
        }
        temp_user = users[rowCount]; // temp user is equal to usersat index rowCount (acess username stored in array)
        for (int k = 0; k < temp_user.length(); k++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
        {
           temp_user[k] = tolower(temp_user[k]); // convert temp user name to all lower case characters
        }
        rowCount++; // increment rowCount
    }
    while (booktitle != temp_title && columnCount < numBooks) // while booktitle does not equal temp title AND columnCount is less than number of books
    {
        for (int j = 0; j < booktitle.length(); j++) // for loop - index 0, index less than lenght of booktitle, increment index by 1
        {
            booktitle[j] = tolower(booktitle[j]); // convert booktitle to all lower case chracters
        }
        temp_title = titles[columnCount]; // temp title is equal to usersat index columnCount (acess title stored in array)
        for (int x = 0; x < temp_title.length(); x++) // for loop - index 0, index less than lenght of temp title, increment index by 1
        {
            temp_title[x] = tolower(temp_title[x]); // convert temp titlee to all lower case characters
        }
        columnCount++; // increment columnCount
    }
    if (booktitle == temp_title && username == temp_user) // if booktitle is equal to temp title AND username is equal to temp user
    {

        return ratings[rowCount - 1][columnCount - 1]; // return rating
    }
    else
    {
        return -3; // else return -3
    }
}