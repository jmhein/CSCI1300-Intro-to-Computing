// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 8

/* Algorithm: 
    1) Initialize function above main
    2) Initialize temp user and temp title variables - type string - set to blank
    3) Initialize counts for rows and columns - set equal to 0
    4) While input string "name" does not equal temp user AND while rowCount is less than input number of users
    5) Convert input string "name" to all lowercase characters using "tolower" function
    6) Use "getUsername" funtion to set temp username = to username at userArray index rowCount
    7) user "tolower" function to convert temp username to all lowercase characters
    8) Repeat steps 5 - 7, but for book title instead of username
    9) If booktitle = temp title AND name = temp username, return rating using syntax userArray[rowCount -1].getRatingAt(columnCount - 1)
    10) Else return -3
*/

#include <iostream> 
#include <string>
#include <fstream>
#include <iomanip>
#include "Book.h"
#include "User.h"
using namespace std;

// Initialize function above main
int getRating(string username, string booktitle, User userArray[], Book bookArray[], int numUsers, int numBooks);

int main () 
{
    // test 1
    // expected output
    // 4
    // 3
    Book books[3];
    books[0].setTitle("Title1");
    books[0].setAuthor("Author1");
    books[1].setTitle("Title2");
    books[1].setAuthor("Author2");
    books[2].setTitle("Title3");
    books[2].setAuthor("Author3");
    User users[2];
    users[0].setUsername("User1");
    users[0].setNumRatings(3);
    users[0].setRatingAt(0,1);
    users[0].setRatingAt(1,4);
    users[0].setRatingAt(2,2);
    users[1].setUsername("User2");
    users[1].setNumRatings(3);
    users[1].setRatingAt(0,0);
    users[1].setRatingAt(1,5);
    users[1].setRatingAt(2,3);
    cout << getRating("User1", "Title2", users, books, 2, 3) << endl; // first function call to test
    cout << getRating("User2", "Title3", users, books, 2, 3) << endl; // second function call to test
    cout << endl;
    
    // test 2
    // expected output
    // -3
    cout << getRating("User3", "Title1", users, books, 2, 3) << endl; // test -3 return value 
}

int getRating(string name, string booktitle, User userArray[], Book bookArray[], int numUsers, int numBooks)
{
    string temp_user = ""; // string to store temporary user
    string temp_title = ""; // string to store temporary title
    int rowCount = 0; // count rows
    int columnCount = 0; // count columns
    while (name != temp_user && rowCount < numUsers) // while username does not equal temp user AND rowCount is less than number of users
    {
        for (int i = 0; i < name.length(); i++) // for loop - index 0, index less than lenght of username, increment index by 1
        {
            name[i] = tolower(name[i]); // convert username to all lower case chracters
        }
        temp_user = userArray[rowCount].getUsername(); // temp user equal to getUsername at index rowCount
        for (int i = 0; i < temp_user.length(); i++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
        {
           temp_user[i] = tolower(temp_user[i]); // convert temp user name to all lower case characters
        }
        rowCount++; // increment rowCount
    }
    while (booktitle != temp_title && columnCount < numBooks) // while booktitle does not equal temp title AND columnCount is less than number of books
    {
        for (int i = 0; i < booktitle.length(); i++) // for loop - index 0, index less than lenght of booktitle, increment index by 1
        {
            booktitle[i] = tolower(booktitle[i]); // convert booktitle to all lower case chracters
        }
        temp_title = bookArray[columnCount].getTitle(); // temp title is equal getTitle at index column count
        for (int i = 0; i < temp_title.length(); i++) // for loop - index 0, index less than lenght of temp title, increment index by 1
        {
            temp_title[i] = tolower(temp_title[i]); // convert temp title to all lower case characters
        }
        columnCount++; // increment columnCount
    }
    if (booktitle == temp_title && name == temp_user) // if booktitle is equal to temp title AND username is equal to temp user
    {

        return userArray[rowCount - 1].getRatingAt(columnCount - 1); // return rating
    }
    else
    {
        return -3; // else return -3
    }
}