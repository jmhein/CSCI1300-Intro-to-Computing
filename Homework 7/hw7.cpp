// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 9


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Book.h" // Include header file
#include "User.h" // include header file
using namespace std;

// Initialize functions
void displayMenu();
int split(string sentence, char delim, string mySplits[], int length);
int readBooks(string fileName, Book bookArray[], int numBookStored, int bookArrSize);
int readRatings(string fileName, User userArray[], int numUsersStored, int userArraySize, int maxCol);
void printAllBooks (Book bookArray[], int numBookStored);
int getRating(string name, string booktitle, User userArray[], Book bookArray[], int numUsers, int numBooks);

int main(int argc, char const *argv[]) {

    // taking menu choice 
    string choice;

    // number of books and users stored in the arrays
    int numBooks = 0;
    int numUsers = 0;
    int rate;

    // Use the these values to declare your
    // titles, authors, users and ratings arrays
    const static int  userArrSize = 100;
    const static int  bookArrSize = 50;
    Book bookArray[bookArrSize];
    User userArray[userArrSize];

    // variables to store user inputs 
    string bookFileName;
    string userFileName;
    string userName, bookTitle;    

    while (choice != "5") {
        displayMenu();

        // take an opton (1, 2, 3, or 4)
        getline(cin, choice);

        // convert the `choice` to an integer 
        int menuChoice = stoi(choice); 
        switch (menuChoice) {
            case 1:
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);
                if (readBooks(bookFileName, bookArray, numBooks, bookArrSize) == -1) // check if return value is -1
                {
                    cout << "No books saved to the database." << endl; // Print per directions
                }
                else if (readBooks(bookFileName, bookArray, numBooks, bookArrSize) == -2) // check if return value is -2
                {
                    cout << "Database is already full. No books were added." << endl; // print per directions
                }
                else
                {
                    readBooks(bookFileName, bookArray, numBooks, bookArrSize); // return value not -1 or -2, read the books
                    numBooks = readBooks(bookFileName, bookArray, numBooks, bookArrSize); // number of books stored is equal to return value of readBooks function
                    if (numBooks < bookArrSize)
                    {
                        cout << "Total books in the database: " << numBooks << endl; // if numBooks is less than bookArrSize - print number of books
                    }
                    else
                    {
                        numBooks = bookArrSize; // numBooks is equal to 50
                        cout << "Database is full. Some books may have not been added." << endl; // print database is full
                    }
                }
                cout << endl;
                break;

            case 2:
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);
                if (readRatings(userFileName, userArray, numUsers, userArrSize, bookArrSize) == -1) // check if readRatings returns -1
                {
                    cout << "No users saved to the database." << endl; // if so, no users added
                }
                else if (readRatings(userFileName, userArray, numUsers, userArrSize, bookArrSize) == -2) // check if readRatings returns -2
                {
                    cout << "Database is already full. No users were added." << endl; // if so, database is full
                }
                else
                {
                    readRatings(userFileName, userArray, numUsers, userArrSize, bookArrSize); // if readRatings does not return -1 or -2, readRatings
                    numUsers = readRatings(userFileName, userArray, numUsers, userArrSize, bookArrSize); // numUsers = return value for readRatings
                    if (numUsers < userArrSize)
                    {
                        cout << "Total users in the database: " << numUsers << endl; // if numUsers is less than array size, print number of users
                    }
                    else
                    {
                        numUsers = userArrSize; // else, numUsers = array size
                        cout << "Database is full. Some users may have not been added." << endl; // print per directions
                    }
                }
                cout << endl;
                break;

            case 3:
                printAllBooks (bookArray, numBooks); // call printAllBooks function
                cout << endl;
                break;

            case 4:
                // get user's rating 
                // take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);

                // take book title 
                cout << "Enter book title:" << endl;
                getline(cin, bookTitle);
                rate = getRating(userName, bookTitle, userArray, bookArray, numUsers, numBooks); // set rate equal to return value for getRating function
                if (rate == 0)
                {
                    cout << userName << " has not rated " << bookTitle << endl; // if rating is 0, user has not rated the book
                }
                else if (rate == -3)
                {
                    cout << userName << " or " << bookTitle << " does not exist" << endl; // if rating is -3, either user or title does not exst
                }
                else
                {
                    cout << userName << " rated " << bookTitle << " with " << rate << endl; // all other options, print username, book title and their rating of the book
                }
                cout << endl;
                break;
            case 5:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
        }
    }

    return 0;
}

/////////////////////////////////// DISPLAY MENU FUNCTION ////////////////////////////////////////////////////////////////////

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */

void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Get rating" << endl;
  cout << "5. Quit" << endl;
}

//////////////////////////////////////// SPLIT FUNCTION /////////////////////////////////////////////////////////////////////

int split(string sentence, char delim, string mySplits[], int length) // Write function below
{ 
    int count = 0; // initilize count variable
    string word = ""; // temp string to hold word
    sentence = sentence + delim; // adds delim to end of string in order to pick up last word in sentence
    for (int i = 0; i < sentence.length(); i++)
    {
        if (count < length)
        {
            if (sentence[i] == delim) // if character at index i = delim
            {
                if (word.length() > 0) // check if word length is greater than 0
                {
                    mySplits[count] = word; // if true, print word
                    count ++; // count plus 1
                }
                word = "";
            }
            else
            {
            word = word + sentence[i]; // if character is not = to delim, word = previous characters + character at index #
            }
        }
        else
        {
            return -1;
        }
    }
    return count;
}

//////////////////////////////////////// READBOOKS FUNCTION ///////////////////////////////////////////////////////

/* readBooks function
 * the function reads a book file from the text into book and author arrays
 *
 * @param: fileName, string, name of the book file
 * @param: titles, string array, titles of the books are stored
 * @param: authors, string array, authors of the books are stored
 * @param: numBookStored, int, the number of books currently stored in the arrays
 * @param: size, int, the size of the arrays (titles and authors)
 * @return: the number of books read into the array (number of lines in the file)
 *          or appropriate return code
 */
 
int readBooks(string fileName, Book bookArray[], int numBookStored, int bookArrSize) // Write function below
{ 
    string line = ""; // temp string for reading fild
    string temp_array[2]; // temp array to store / pass author names and book titles to arrays in parameter
    Book temp_book;
    ifstream myfile; // initialize variable of steam type
    myfile.open(fileName); // open file specified in function parameter
    if (numBookStored != bookArrSize) // if file opened successfly - do stuff
    {
        if (myfile.is_open()) // when file opens successfully, check if numBookStored = size - if not proceed with code
        {
            int i = 0 + numBookStored; // index = 0 plus whatever is already in array
            while(getline(myfile, line)) // while there are lines to read, do stuff below
            {
                if (i < bookArrSize) // as long as i is less than size of array (avoid seg fault error)
                {
                    if (line != "") // if line is not empty
                    {
                        split (line, ',', temp_array, 2); // split the string with ',' as deliminator
                        temp_book.setAuthor(temp_array[0]); // author is first element in temp array
                        temp_book.setTitle(temp_array[1]); // book title is second element in temp arra
                        bookArray[i] = temp_book; // pass author name to the array "authors" in the function parameter (at index i)
                        i++; // increment i
                    }
                }
            }
            return i; // return i (equal to number of elements in array)
        }
        else // if numBookStored = size, return - 2
        {
            return -1;
        }
    }
    else // if file did not open successfully - return -1
    {
        return -2;
    }
}

//////////////////////////////////////////// READRATINGS FUNCTION /////////////////////////////////////////////////////

/* readRatings function
 * Read the user ratings from the file and store them
 * into users array and ratings array
 *
 * @param: fileName, string, the name of user rating file
 * @param: users, string array, the array of users
 * @param: ratings, int 2D array, the ratings of each user
 *         row i is user, and column j is a book.
 *         ratings[i][j] is the user_i rated book_j
 * @param: numUsers, int, the number of users currently stored in the array
 * @param: sizeRow, int, the number of rows in the 2D array (capacity)
 * @param: sizeCol, int, the number of column in the 2D array (capacity)
 * @return: the number of users in total or appropriate return code
 */

int readRatings(string fileName, User userArray[], int numUsersStored, int userArraySize, int maxCol)
{
    string line = ""; // temp variable for input stream
    string temp_array[maxCol + 1]; // temp array to hold split values
    int temp_ratings[maxCol]; // temp array to hold integer-type ratings
    User temp_user; // temp User variable to pass into userArray
    string temp_username; // temp string to hold username and pass to temp user
    ifstream myfile; // create input stream
    myfile.open(fileName); // open file
    if (numUsersStored != userArraySize) // check that number of users does not equal max rows
    {
        if (myfile.is_open()) // check if file opened successfully
        {
            int i = 0 + numUsersStored; // index equals 0 plus and users in array
            while (getline(myfile, line)) // while getline returns true
            {
                if (i < userArraySize) // check if i is less than user array size - if true do stuff
                {
                    if (line != "") // check line is not empty
                    {
                        split(line, ',', temp_array, (maxCol + 1)); // split line
                        temp_username = temp_array[0]; // username will always be first element
                        for (int j = 0; j < maxCol; j++)
                        {
                            if (temp_array[j + 1] != "") // check that rating is not blank
                            {
                                temp_ratings[j] = stoi(temp_array[j + 1]); // convert rating in temp array to type integer
                            }
                        }
                        temp_user = User(temp_username, temp_ratings, maxCol); // pass username and ratings to temp user variable
                        userArray[i] = temp_user; // userArray at index i = temp user
                        i++; // increment i
                    }
                }
            }
            return i; // return i
        }
        else
        {
            return -1; // return -1 if file did not open successfuclly
        }
    }
    else
    {
        return -2; // return - 2 if number of users equals maximum
    }
}

///////////////////////////////////// PRINT BOOK LIST FUNCTION ///////////////////////////////////////////////////////

/* printBookList function (helper function)
 * print the list of books in the array
 *
 * @param: titles, string, the title of books
 * @param: authors, string, the author of books
 * @param: numBooks, int, the number of books
 * @return: void
 */

void printAllBooks (Book bookArray[], int numBookStored)
{
    if (numBookStored <= 0) // if num books less than or equal to zero
    {
        cout << "No books are stored" << endl; // print "No books are stored" per directions
    }
    else
    {
        cout << "Here is a list of books" << endl; // print "Here is a list of books" if there are books stored
        for (int i = 0; i < numBookStored; i++) // for loop - index less than books stored
        {
            cout << bookArray[i].getTitle() << " by " << bookArray[i].getAuthor() << endl; // print titles at i by authors at i
        }
    }
}

///////////////////////////////////// GET RATING FUNCTION ///////////////////////////////////////////////////////////////

/* getRating function 
 * Search for a rating given the user's name and 
 * book's title and return that value
 *
 * @param: string, username 
 * @param: string, title of the book 
 * @param: string, array, user names
 * @param: string, array, titles
 * @param: 2D int array, list of ratings for each user
 * @param: int, number of users whose names/ratings are currently 
 *         stored in the string array/2D array respectively
 * @param: int, number of books whose titles/ratings are currently 
 *         stored in the string array/2D array respectively
 * @return: int, users's rating value or appropriate return code
 */

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
        temp_user = userArray[rowCount].getUsername(); // temp user is equal to usersat index rowCount (acess username stored in array)
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
        temp_title = bookArray[columnCount].getTitle(); // temp title is equal to usersat index columnCount (acess title stored in array)
        for (int i = 0; i < temp_title.length(); i++) // for loop - index 0, index less than lenght of temp title, increment index by 1
        {
            temp_title[i] = tolower(temp_title[i]); // convert temp titlee to all lower case characters
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