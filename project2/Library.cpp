// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Project 2

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <fstream>
#include "Book.h" // include header file for Book class
#include "User.h" // include header file for User class
#include "Library.h" // include header file for Library class

using namespace std;

//////////////////////////////////// SPLIT FUNCTION ///////////////////////////////////////////////////////////

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
}

///////////////////////////////////////// DEFAULT CONSTRUCTOR //////////////////////////////////////////////////////

Library::Library()
{
    numBooks = 0; // set numBooks to 0
    numUsers = 0; // set numUsers to 0
}

//////////////////////////////////////// GET SIZE BOOK FUNCTION //////////////////////////////////////////////////////

int Library::getSizeBook()
{
    return sizeBook; // return sizeBook
}

//////////////////////////////////////// GET SIZE USER FUNCTION //////////////////////////////////////////////////////

int Library::getSizeUser()
{
    return sizeUser; // return sizeUser
}

//////////////////////////////////////// GET NUM BOOKS FUNCTION //////////////////////////////////////////////////////

int Library::getNumBooks()
{
    return numBooks; // return numBooks
}

//////////////////////////////////////// GET NUM USERS FUNCTION //////////////////////////////////////////////////////

int Library::getNumUsers()
{
    return numUsers; // return numUsers
}

/////////////////////////////////////////// READ BOOKS FUNCTION /////////////////////////////////////////////////////////

int Library::readBooks(string fileName)
{ 
    string line = ""; // temp string for reading fild
    string temp_array[2]; // temp array to store / pass author names and book titles to array in parameter
    Book temp_book; // temp book varaible
    ifstream myfile; // initialize variable of steam type
    myfile.open(fileName); // open file specified in function parameter
    if (numBooks != sizeBook) // if num books stored does not equal array size - do stuff
    {
        if (myfile.is_open()) // check if file opens sucessfully
        {
            while(getline(myfile, line)) // while there are lines to read, do stuff below
            {
                if (numBooks < sizeBook) // as long as i is less than size of array (avoid seg fault error)
                {
                    if (line != "") // if line is not empty
                    {
                        split (line, ',', temp_array, 2); // split the string with ',' as deliminator
                        temp_book.setAuthor(temp_array[0]); // author is first element in temp array (user set author function)
                        temp_book.setTitle(temp_array[1]); // book title is second element in temp array (use set title function)
                        books[numBooks] = temp_book; // pass temp book variable to bookArray at index i
                        numBooks++; // incriment numBooks
                    }
                }
            }
            return numBooks; // return i (equal to number of elements in array)
        }
        else // if file did not open successfully - return -1 
        {
            return -1;
        }
    }
    else // if numBookStored = size, return - 2
    {
        return -2;
    }
}

//////////////////////////////////////// READ RATINGS FUNCTION //////////////////////////////////////////////////////////

int Library::readRatings(string filename)
{
    string line = ""; // temp variable for input stream
    string temp_array[sizeBook + 1]; // temp array to hold split values
    int temp_ratings[sizeBook]; // temp array to hold integer-type ratings
    User temp_user; // temp User variable to pass into userArray
    string temp_username; // temp string to hold username and pass to temp user
    ifstream myfile; // create input stream
    myfile.open(filename); // open file
    if (numUsers != sizeUser) // check that number of users does not equal max rows
    {
        if (myfile.is_open()) // check if file opened successfully
        {
            while (getline(myfile, line)) // while getline returns true
            {
                if (numUsers < sizeUser) // check if i is less than user array size - if true do stuff
                {
                    if (line != "") // check line is not empty
                    {
                        split(line, ',', temp_array, (sizeBook + 1)); // split line
                        temp_username = temp_array[0]; // username will always be first element
                        for (int j = 0; j < sizeBook; j++)
                        {
                            if (temp_array[j + 1] != "" && j < sizeBook) // check that rating is not blank
                            { 
                                temp_ratings[j] = stoi(temp_array[j + 1]); // convert rating in temp array to type integer
                            }
                            else
                            {
                                temp_ratings[j] = 0;
                            }
                        }
                        temp_user = User(temp_username, temp_ratings, sizeBook); // pass username and ratings to temp user variable
                        users[numUsers] = temp_user; // userArray at index i = temp user
                        numUsers++; // increment numUsers
                    }
                }
            }
            return numUsers; // return numUsers
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

///////////////////////////////// PRINT ALL BOOKS FUNCTION /////////////////////////////////////////////////////////////

void Library::printAllBooks()
{
    if (numBooks <= 0) // if num books less than or equal to zero
    {
        cout << "No books are stored" << endl; // print "No books are stored" per directions
    }
    else
    {
        cout << "Here is a list of books" << endl; // print "Here is a list of books" if there are books stored
        for (int i = 0; i < numBooks; i++) // for loop - index less than books stored
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl; // print getTitle and getAuthor at index i
        }
    }
}

///////////////////////////////// GET COUNT READ BOOKS FUNCTION /////////////////////////////////////////////////////////////

int Library::getCountReadBooks(string username)
{
    string temp_user = ""; // string to store temporary user
    int rowCount = 0; // count rows
    while (username != temp_user && rowCount < numUsers) // while username does not equal temp user AND rowCount is less than number of users
    {
        for (int i = 0; i < username.length(); i++) // for loop - index 0, index less than lenght of username, increment index by 1
        {
            username[i] = tolower(username[i]); // convert username to all lower case chracters
        }
        temp_user = users[rowCount].getUsername(); // temp user equal to getUsername at index rowCount
        for (int i = 0; i < temp_user.length(); i++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
        {
           temp_user[i] = tolower(temp_user[i]); // convert temp user name to all lower case characters
        }
        rowCount++; // increment rowCount
    }
    if (username == temp_user) // if username == temp user
    {
        return users[rowCount - 1].getNumRatings(); // return numRatings at user[index]
    }
    else // if username does not equal temp user
    {
        return -3;
    }
}

/////////////////////////////////// CALC AVERAGE RATING FUNCTION ///////////////////////////////////////////

double Library::calcAvgRating(string title)
{
    string temp_title = ""; // temp variable
    int columnCount = 0; // count for book index
    double ratingsum = 0.0; // sume of ratings
    int ratingcount = 0; // count number of ratings
    double averageRating = 0.0; // average rating
    while (title != temp_title && columnCount < numBooks) // while booktitle does not equal temp title AND columnCount is less than number of books
    {
        for (int i = 0; i < title.length(); i++) // for loop - index 0, index less than lenght of booktitle, increment index by 1
        {
            title[i] = tolower(title[i]); // convert booktitle to all lower case chracters
        }
        temp_title = books[columnCount].getTitle(); // temp title is equal getTitle at index column count
        for (int i = 0; i < temp_title.length(); i++) // for loop - index 0, index less than lenght of temp title, increment index by 1
        {
            temp_title[i] = tolower(temp_title[i]); // convert temp title to all lower case characters
        }
        columnCount++; // increment columnCount
    }
    if (title == temp_title) // if title is found - do stuff
    {
        for (int i = 0; i < numUsers; i++)
        {
            if (users[i].getRatingAt(columnCount - 1) != 0) // check that rating does not equal zero
            {
                ratingsum = ratingsum + users[i].getRatingAt(columnCount - 1); // add rating to sum of ratings
                ratingcount++; // increment number of ratings
                averageRating = ratingsum / ratingcount; // calculate aveage rating for title
            }
        }
        if (ratingcount != 0) // if one or more rating was added
        {
            return averageRating; // return the average rating
        }
        else
        {
            return 0; // otherwise return 0
        }
    }
    else
    {
        return -3; // if title not found, return -3
    }
}

/////////////////////////////////////// ADD USER FUNCTION ///////////////////////////////////////////////////////////////

int Library::addUser(string username)
{
    string temp_user = ""; // string to store temporary user
    int rowCount = 0; // count rows
    User blankUser = User(); // temp variable
    if (numUsers < sizeUser)
    {
        while (username != temp_user && rowCount < numUsers) // while username does not equal temp user AND rowCount is less than number of users
        {
            for (int i = 0; i < username.length(); i++) // for loop - index 0, index less than lenght of username, increment index by 1
            {
                username[i] = tolower(username[i]); // convert username to all lower case chracters
            }
            temp_user = users[rowCount].getUsername(); // temp user equal to getUsername at index rowCount
            for (int i = 0; i < temp_user.length(); i++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
            {
               temp_user[i] = tolower(temp_user[i]); // convert temp user name to all lower case characters
            }
            rowCount++; // increment rowCount
        }
        if (username != temp_user)
        {
            blankUser.setUsername(username); // set username for temp User if username != one already in database
            users[numUsers] = blankUser; // users at index = temp User variable
            numUsers++; // increment numUsers
            return 1; // return 1
        }
        else
        {
            return 0; // return 0 if username is already in system
        }
    }
    else
    {
        return -2; // return -2 if database is full
    }
}

/////////////////////////////////// CHECK OUT BOOK FUNCTION /////////////////////////////////////////////////////

int Library::checkOutBook(string username, string title, int rating)
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
        temp_user = users[rowCount].getUsername(); // temp user equal to getUsername at index rowCount
        for (int i = 0; i < temp_user.length(); i++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
        {
           temp_user[i] = tolower(temp_user[i]); // convert temp user name to all lower case characters
        }
        rowCount++; // increment rowCount
    }
    while (title != temp_title && columnCount < numBooks) // while booktitle does not equal temp title AND columnCount is less than number of books
    {
        for (int i = 0; i < title.length(); i++) // for loop - index 0, index less than lenght of booktitle, increment index by 1
        {
            title[i] = tolower(title[i]); // convert booktitle to all lower case chracters
        }
        temp_title = books[columnCount].getTitle(); // temp title is equal getTitle at index column count
        for (int i = 0; i < temp_title.length(); i++) // for loop - index 0, index less than lenght of temp title, increment index by 1
        {
            temp_title[i] = tolower(temp_title[i]); // convert temp title to all lower case characters
        }
        columnCount++; // increment columnCount
    }
    if (rating >= 0 && rating <= 5) // if booktitle is equal to temp title AND username is equal to temp user
    {
        if (title == temp_title && username == temp_user)
        {
            users[rowCount - 1].setRatingAt(columnCount - 1, rating);
            int numRatings = users[rowCount - 1].getNumRatings() + 1;
            users[rowCount - 1].setNumRatings(numRatings);
            return true;
        }
        else
        {
            return -3;
        }
    }
    else
    {
        return -4;
    }
}

//////////////////////////////// VIEW RATINGS FUNCTION /////////////////////////////////////////////////////

void Library::viewRatings(string username)
{
    string temp_user = ""; // string to store temporary user
    string returnUser = username;
    int rowCount = 0; // count rows
    while (username != temp_user && rowCount < numUsers) // while username does not equal temp user AND rowCount is less than number of users
    {
        for (int i = 0; i < username.length(); i++) // for loop - index 0, index less than lenght of username, increment index by 1
        {
            username[i] = tolower(username[i]); // convert username to all lower case chracters
        }
        temp_user = users[rowCount].getUsername(); // temp user equal to getUsername at index rowCount
        for (int i = 0; i < temp_user.length(); i++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
        {
           temp_user[i] = tolower(temp_user[i]); // convert temp user name to all lower case characters
        }
        rowCount++; // increment rowCount
    }
    if (username == temp_user)
    {
        if (users[rowCount - 1].getNumRatings() != 0)
        {
            cout << "Here are the books that " << returnUser << " rated" << endl;
            for (int i = 0; i < sizeBook; i++)
            {
                if (users[rowCount - 1].getRatingAt(i) != 0)
                {
                    cout << "Title : " << books[i].getTitle() << endl;
                    cout << "Rating : " << users[rowCount - 1].getRatingAt(i) << endl;
                    cout << "-----" << endl;
                }
            }
        }
        else
        {
            cout << returnUser << " has not rated any books yet." << endl;
        }
    }
    else
    {
        cout << returnUser << " does not exist." << endl;
    }
}

//////////////////////////////////////// GET RATING FUNCTION //////////////////////////////////////////////////////

int Library::getRating(string username, string title)
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
        temp_user = users[rowCount].getUsername(); // temp user equal to getUsername at index rowCount
        for (int i = 0; i < temp_user.length(); i++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
        {
           temp_user[i] = tolower(temp_user[i]); // convert temp user name to all lower case characters
        }
        rowCount++; // increment rowCount
    }
    while (title != temp_title && columnCount < numBooks) // while booktitle does not equal temp title AND columnCount is less than number of books
    {
        for (int i = 0; i < title.length(); i++) // for loop - index 0, index less than lenght of booktitle, increment index by 1
        {
            title[i] = tolower(title[i]); // convert booktitle to all lower case chracters
        }
        temp_title = books[columnCount].getTitle(); // temp title is equal getTitle at index column count
        for (int i = 0; i < temp_title.length(); i++) // for loop - index 0, index less than lenght of temp title, increment index by 1
        {
            temp_title[i] = tolower(temp_title[i]); // convert temp title to all lower case characters
        }
        columnCount++; // increment columnCount
    }
    if (title == temp_title && username == temp_user) // if booktitle is equal to temp title AND username is equal to temp user
    {

        return users[rowCount - 1].getRatingAt(columnCount - 1); // return rating
    }
    else
    {
        return -3; // else return -3
    }
}

//////////////////////////////////////// GET RECOMMENDATIONS FUNCTION //////////////////////////////////////////////////////

void Library::getRecommendations(string username)
{
    string temp_user = ""; // string to store temporary user
    string returnUser = username; // ensures case-sensitive output 
    int rowCount = 0; // count rows
    double lowest_SSD = 10000; // set to arbitrairly large number
    double SSD = 0.0; // temp variable
    int userIndex = 0; // temp variable
    int bookCount = 0; // temp variable
    while (username != temp_user && rowCount < numUsers) // while username does not equal temp user AND rowCount is less than number of users
    {
        for (int i = 0; i < username.length(); i++) // for loop - index 0, index less than lenght of username, increment index by 1
        {
            username[i] = tolower(username[i]); // convert username to all lower case chracters
        }
        temp_user = users[rowCount].getUsername(); // temp user equal to getUsername at index rowCount
        for (int i = 0; i < temp_user.length(); i++) // for loop - index 0, index less than lenght of temp user name, increment index by 1
        {
           temp_user[i] = tolower(temp_user[i]); // convert temp user name to all lower case characters
        }
        rowCount++; // increment rowCount
    }
    if (username == temp_user) // if username is fount
    {
        for (int i = 0; i < numUsers; i++)
        {
            SSD = 0; // set sum square differences to 0
            if (i != rowCount - 1) // make sure we are skipping index for user we are getting recommendations for
            {
                for (int j = 0; j < numBooks; j++) // nested for loop
                {
                    double difference = users[rowCount - 1].getRatingAt(j) - users[i].getRatingAt(j); // calculate difference for book at index j
                    SSD = SSD + pow(difference, 2); // add square difference to SSD
     
                }
                if (SSD < lowest_SSD && getCountReadBooks(users[i].getUsername()) != 0) // if SSD is the lowest and user has rated at least one book
                {
                    lowest_SSD = SSD; // reset lowest variable
                    userIndex = i; // set userIndex 
                }
            }
        }
        for (int i = 0; i < numBooks; i++)
        {
            if (bookCount == 0 && users[userIndex].getRatingAt(i) >= 3 && users[rowCount - 1].getRatingAt(i) == 0) // ensure cout statement is only printed once
            {
                cout << "Here is the list of recommendations" << endl;
            }
            if (bookCount < 5 && users[userIndex].getRatingAt(i) >= 3 && users[rowCount - 1].getRatingAt(i) == 0) // if less than 5 books have been printed, and most similar user has rated 3 or higher, and user has not rated book 
            {
                bookCount++; // increment book count
                cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl; // print title and author
            }
        }
        if (bookCount == 0) // if no books have been found for the most similar user - cout below
        {
            cout << "There are no recommendations for " << returnUser << " at present." << endl;
        }
        
    }
    else // if username has not been found
    {
        cout << returnUser << " does not exist." << endl;
    }
}

