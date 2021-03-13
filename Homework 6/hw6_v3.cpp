// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 6 - Problem 8


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// Initialize functions
void displayMenu();
int split(string sentence, char delim, string mySplits[], int length);
int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size);
int readRatings(string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns);
void printAllBooks (string titles[], string authors [], int numBookStored);
int getRating(string username, string booktitle, string users[], string titles[], int ratings[][50], int numUsers, int numBooks);


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
    string titles[bookArrSize];
    string authors[bookArrSize];
    string users[userArrSize];
    int ratings[userArrSize][bookArrSize];


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
                if (readBooks(bookFileName, titles, authors, numBooks, bookArrSize) == -1)
                {
                    cout << "No books saved to the database." << endl;
                }
                else if (readBooks(bookFileName, titles, authors, numBooks, bookArrSize) == -2)
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                else
                {
                    readBooks(bookFileName, titles, authors, numBooks, bookArrSize);
                    numBooks = readBooks(bookFileName, titles, authors, numBooks, bookArrSize);
                    if (numBooks < bookArrSize)
                    {
                        cout << "Total books in the database: " << numBooks << endl;
                    }
                    else
                    {
                        numBooks = bookArrSize;
                        cout << "Database is full. Some books may have not been added." << endl;
                    }
                }
                cout << endl;
                break;

            case 2:
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);
                if (readRatings(userFileName, users, ratings, numUsers, userArrSize, bookArrSize) == -1)
                {
                    cout << "No users saved to the database." << endl;
                }
                else if (readRatings(userFileName, users, ratings, numUsers, userArrSize, bookArrSize) == -2)
                {
                    cout << "Database is already full. No users were added." << endl; 
                }
                else
                {
                    readRatings(userFileName, users, ratings, numUsers, userArrSize, bookArrSize);
                    numUsers = readRatings(userFileName, users, ratings, numUsers, userArrSize, bookArrSize);
                    if (numUsers < userArrSize)
                    {
                        cout << "Total users in the database: " << numUsers << endl;
                    }
                    else
                    {
                        numUsers = userArrSize;
                        cout << "Database is full. Some users may have not been added." << endl;
                    }
                }
                cout << endl;
                break;

            case 3:
                printAllBooks (titles, authors, numBooks);
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
                rate = getRating(userName, bookTitle, users, titles, ratings, numUsers, numBooks);
                if (rate == 0)
                {
                    cout << userName << " has not rated " << bookTitle << endl;
                }
                else if (rate == -3)
                {
                    cout << userName << " or " << bookTitle << " does not exist" << endl;
                }
                else
                {
                    cout << userName << " rated " << bookTitle << " with " << rate << endl;
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
 
int readBooks(string fileName, string titles[], string authors[], int numBookStored, int size) // Write function below
{ 
    string line = ""; // temp string for reading fild
    string temp_authors; // temp variable to store author name after split
    string temp_books; // temp variable to store book title after split
    string temp_array[2]; // temp array to store / pass author names and book titles to arrays in parameter
    ifstream myfile; // initialize variable of steam type
    myfile.open(fileName); // open file specified in function parameter
    if (myfile.is_open()) // if file opened successfly - do stuff
    {
        if (numBookStored != size) // when file opens successfully, check if numBookStored = size - if not proceed with code
        {
            int i = 0 + numBookStored; // index = 0 plus whatever is already in array
            while(getline(myfile, line)) // while there are lines to read, do stuff below
            {
                if (i < size) // as long as i is less than size of array (avoid seg fault error)
                {
                    if (line != "") // if line is not empty
                    {
                        split (line, ',', temp_array, 2); // split the string with ',' as deliminator
                        temp_authors = temp_array[0]; // author is first element in temp array
                        temp_books = temp_array[1]; // book title is second element in temp arra
                        authors[i] = temp_authors; // pass author name to the array "authors" in the function parameter (at index i)
                        titles[i] = temp_books; // pass book title to the array "titles" in the parameter (at index i)
                        i++; // increment i
                    }
                }
            }
            return i; // return i (equal to number of elements in array)
        }
        else // if numBookStored = size, return - 2
        {
            return -2;
        }
    }
    else // if file did not open successfully - return -1
    {
        return -1;
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

int readRatings(string fileName, string users[], int ratings[][50], int numUsers, int maxRows, int maxColumns)
{
    string line = "";
    string temp_array[maxColumns + 1];
    string temp_user;
    int temp_rating;
    ifstream myfile;
    myfile.open(fileName);
    if (numUsers != maxRows)
    {
        if (myfile.is_open())
        {
            int i = 0 + numUsers; // index
            while (getline(myfile, line))
            {
                if (i < maxRows) // probably need to add conditions here
                {
                    if (line != "")
                    {
                        split(line, ',', temp_array, (maxColumns + 1));
                        temp_user = temp_array[0]; // user will always be first element 
                        users[i] = temp_user;
                        for (int j = 1; j < maxColumns + 1; j++) // tem
                        {
                            if (temp_array[j] != "")
                            {
                                temp_rating = stoi(temp_array[j]);
                                ratings[i][j - 1] = temp_rating;
                            }
                        }
                        i++;
                    }
                }
            }
            return i;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -2;
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

void printAllBooks (string titles[], string authors [], int numBookStored)
{
    if (numBookStored <= 0)
    {
        cout << "No books are stored" << endl;
    }
    else
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBookStored; i++)
        {
            cout << titles[i] << " by " << authors[i] << endl;
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

int getRating(string username, string booktitle, string users[], string titles[], int ratings[][50], int numUsers, int numBooks)
{
    string temp_user = "";
    string temp_title = "";
    int rowCount = 0;
    int columnCount = 0;
    while (username != temp_user && rowCount < numUsers)
    {
        for (int i = 0; i < username.length(); i++)
        {
            username[i] = tolower(username[i]);
        }
        temp_user = users[rowCount];
        for (int k = 0; k < temp_user.length(); k++)
        {
           temp_user[k] = tolower(temp_user[k]); 
        }
        rowCount++;
    }
    while (booktitle != temp_title && columnCount < numBooks)
    {
        for (int j = 0; j < booktitle.length(); j++)
        {
            booktitle[j] = tolower(booktitle[j]);
        }
        temp_title = titles[columnCount];
        for (int x = 0; x < temp_title.length(); x++)
        {
            temp_title[x] = tolower(temp_title[x]);
        }
        columnCount++;
    }
    if (booktitle == temp_title && username == temp_user)
    {

        return ratings[rowCount - 1][columnCount - 1];
    }
    else
    {
        return -3;
    }
}



