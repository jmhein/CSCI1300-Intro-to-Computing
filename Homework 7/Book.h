#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

/**
   A book class that tracks titles and authors of books
 */
 
class Book
{
public:
   Book(); // default constructor
   Book(string bookTitle, string bookAuthor); // parameterized constructor
   string getTitle();
   string getAuthor();
   void setTitle(string bookTitle);
   void setAuthor(string bookAuthor);
   
private:
   string title;
   string author;
};

#endif
