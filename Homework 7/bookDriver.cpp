#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include "Book.h" // include header file
using namespace std;

// Test file

int main()
{
   // test1
   // expected output:
   // Red Rising by Pierce Brown
   Book book1; // initialize book type variable
   book1.setTitle("Red Rising"); // test set title
   book1.setAuthor("Pierce Brown"); // test set author
   cout << book1.getTitle() << " by " << book1.getAuthor() << endl; // test get title / get author
   
   // test2
   // expected output:
   // Red Rising by Pierce Brown
   Book book2 = Book("Red Rising", "Pierce Brown"); // test parameterized constructor
   cout << book2.getTitle() << " by " << book2.getAuthor() << endl; //
}
