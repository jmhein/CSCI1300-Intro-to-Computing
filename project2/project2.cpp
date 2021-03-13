// CS1300 Spring 2019
// Author: my name
// Recitation: 123 – Favorite TA
// Cloud9 Workspace Editor Link: https://ide.c9.io/…
// Project 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Book.h" // Include header file
#include "User.h" // include header file
#include "Library.h" // include header file
using namespace std;


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
	cout << "5. Find number of books user rated" << endl;
	cout << "6. View ratings" << endl;
	cout << "7. Get average rating" << endl;
	cout << "8. Add a user" << endl;
	cout << "9. Checkout a book" << endl;
	cout << "10. Get recommendations" << endl;
	cout << "11. Quit" << endl;
}


int main(int argc, char const *argv[]) {

    // size and counter variables
    const static int sizeBook = 50;
    const static int sizeUser = 100;
    int numBooks = 0;
    int numUsers = 0;
	
	
	// temp variables
    string choice;
    string bookFileName;
    string userFileName;
    string userName, bookTitle;
    string strRating;
    Library L3;

    while (choice != "11") {
        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);

        switch (menuChoice) {

            case 1:
                // Initialize library -- readBooks
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);
                numBooks = L3.readBooks(bookFileName);
                if (numBooks == -1) // check if return value is -1
                {
                    cout << "No books saved to the database." << endl; // Print per directions
                }
                else if (numBooks == -2) // check if return value is -2
                {
                    cout << "Database is already full. No books were added." << endl; // print per directions
                }
                else
                {
                    if (numBooks < sizeBook)
                    {
                        cout << "Total books in the database: " << numBooks << endl; // if numBooks is less than bookArrSize - print number of books
                    }
                    else
                    {
                        cout << "Database is full. Some books may have not been added." << endl; // print database is full
                    }
                }
                cout << endl;
                break;

            case 2:
                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);
                numUsers = L3.readRatings(userFileName);
                if (numUsers == -1) // check if readRatings returns -1
                {
                    cout << "No users saved to the database." << endl; // if so, no users added
                }
                else if (numUsers == -2) // check if readRatings returns -2
                {
                    cout << "Database is already full. No users were added." << endl; // if so, database is full
                }
                else
                {
                    if (numUsers < sizeUser)
                    {
                        cout << "Total users in the database: " << numUsers << endl; // if numUsers is less than array size, print number of users
                    }
                    else
                    {
                        cout << "Database is full. Some users may have not been added." << endl; // print per directions
                    }
                }
                cout << endl;
                break;

            case 3:
                if (numUsers == 0 || numBooks == 0) // If the database has not been initialized
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    L3.printAllBooks(); // print all books
                }
                cout << endl;
                break;

            case 4:
                if (numUsers == 0 || numBooks == 0) // If the database has not been initialized
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter username:" << endl;
                    getline(cin, userName); // take user name
    
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle); // take book title
                    if (L3.getRating(userName, bookTitle) == 0)
                    {
                        cout << userName << " has not rated " << bookTitle << endl; // if rating is 0, user has not rated the book
                    }
                    else if (L3.getRating(userName, bookTitle) == -3)
                    {
                        cout << userName << " or " << bookTitle << " does not exist." << endl; // if rating is -3, either user or title does not exst
                    }
                    else // if get rating does not return 0 or -3
                    {
                        cout << userName << " rated " << bookTitle << " with " << L3.getRating(userName, bookTitle) << endl; // all other options, print username, book title and their rating of the book
                    }
                }
                cout << endl;
                break;

            case 5:
                if (numUsers == 0 || numBooks == 0) // If the database has not been initialized
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter username:" << endl; // take user name
                    getline(cin, userName); 
                    if (L3.getCountReadBooks(userName) == 0) // if read books returns 0
                    {
                        cout << userName << " has not rated any books." << endl;
                    }
                    else if (L3.getCountReadBooks(userName) == -3) // if read books returns -3
                    {
                        cout << userName << " does not exist." << endl;
                    }
                    else // all other options
                    {
                        cout << userName << " rated " << L3.getCountReadBooks(userName) << " books." << endl;
                    }
                }
            	cout << endl;
                break;

            case 6:
                if (numUsers == 0 || numBooks == 0) // If the database has not been initialized
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else // all other options
                {
                    cout << "Enter username:" << endl; // take user name
                    getline(cin, userName);
                    L3.viewRatings(userName); // call viewRatings for userName
                }
            	cout << endl;
                break;

            case 7:
                if (numUsers == 0 || numBooks == 0) // If the database has not been initialized
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter book title:" << endl; // take book title
                    getline(cin, bookTitle); 
                    if (L3.calcAvgRating(bookTitle) == -3) // if calc avg rating returns -3 - book DNE
                    {
                        cout << bookTitle << " does not exist." << endl;
                    }
                    else // if calc avg rating does not return -3
                    {
                        cout << "The average rating for " << bookTitle << " is " << L3.calcAvgRating(bookTitle) << endl;
                    }
                }
            	cout << endl;
                break;
                
            case 8:
                cout << "Enter username:" << endl; // take user name
                getline(cin, userName);
                if (L3.addUser(userName) == 0) // if add user returns 0
                {
                    cout << userName << " already exists in the database." << endl;
                }
                else if (L3.addUser(userName) == -2) // if add user returns -2
                {
                    cout << "Database is already full. " << userName << " was not added." << endl;
                }
                else // all other options
                {
                    cout << "Welcome to the library " << userName << endl;
                    numUsers++; // increment numUsers
                }
            	cout << endl;
                break;
                
            case 9:
                if (numUsers == 0 || numBooks == 0) // If the database has not been initialized
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter username:" << endl; // take user name
                    getline(cin, userName);
    
                    cout << "Enter book title:" << endl; // take book title
                    getline(cin, bookTitle);
    
                    cout<<"Enter rating for the book:"<<endl; // take rating
                    getline(cin, strRating);
                    if (L3.checkOutBook(userName, bookTitle, stoi(strRating)) == -4) // if check out book returns -4
                    {
                        cout << strRating << " is not valid." << endl; 
                    }
                    else if (L3.checkOutBook(userName, bookTitle, stoi(strRating)) == -3) // check out book returns -3
                    {
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }
                    else // all other options
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                    }
                }
            	cout << endl;
                break;
                
            case 10:
                if (numUsers == 0 || numBooks == 0) // If the database has not been initialized
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter username:" << endl; // take user name
                    getline(cin, userName);
                    L3.getRecommendations(userName); // call get recommendations
                }
            	cout << endl;
                break;

            case 11:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
                cout << endl;
        }
    }
    return 0;
}