// CS1300 Spring 2019
// Author: Jeremy Hein
// Recitation: 204 – Telly Umada
// Cloud9 Workspace Editor Link: https://ide.c9.io/jmhein/csci1300_jmhein
// Homework 7 - Problem 3

/* Algorithm: 
    1) Implementation file - default constructor sets title to "" and author to ""; include "Book.h" header file
    2) Paramaterized constructor - sets title equal to input string bookTitle and author equal to input string bookAuthor
    3) setTitle function - sets title equal to input string
    4) setAuthor function - sets author equal to input string
    5) getTitle function - returns title
    6) get Author function - returns author
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Book.h" // include header file
using namespace std;

// Implementation file
Book::Book()
{
    title = ""; // title blank
    author = ""; // authro blank
}

Book::Book(string bookTitle, string bookAuthor)
{
    title = bookTitle; // title equals input bookTitle
    author = bookAuthor; // authro equals input bookAuthor
}

void Book::setTitle(string bookTitle)
{
    title = bookTitle; // set title equal to input string
}

void Book::setAuthor(string bookAuthor) 
{
    author = bookAuthor; // set author equal to input string
}

string Book::getTitle()
{
    return title; // return title
}

string Book::getAuthor()
{
    return author; // return author
}
