/**********************************
*
* Federico Panichi
*
* federico.panichi@studio.unibo.it
* federico.panichi@avid.com
*
* Simple Library management.
*
* Structure: Main
*             |
*             |___ library class --> book class
*             |
*             |___ user library --> library class; book class
*
*
***********************************/

#include <iostream>
#include "library.h"
#include "book.h"
#include "user.h"
using namespace std;


int main()
{
    //initializes the book parameters,  all of the book objects should be constant
    const Book book1("F. Rossi", "C++ course", 2009);
    const Book book2("Wioletta Kozik", "JAVA course", 2016);
    const Book book3("Adrian Szuszkiewicz", "C# course", 2002);
    //create another three books same as book3 using copy constructor
    const Book book4 = book3;
    const Book book5 = book3;
    const Book book6 = book3;

    Library library(10);  // I create a library with a finite size of 5 books, if size is lower then
                         // # books, print as much as the size of library can have

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    //add the three copied book into the library
    library.addBook(book4); // they have the same unique id because I am copying the object book3 (authors,..., and ID !!!)
    library.addBook(book5); // NOW THAT I MODIFY THE ADDBOOK FUNCTION AND HOW I PASS THE BOOKS (BY REFERENCES)
    library.addBook(book6); // I REALLY HAVE UNIQUE ID also for books that are copied by copy constructor

    library.showBooks();


    return 0;
}
