#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "book.h"

class Library
{
    private:
        int currentAmountOfBooks;
        int maxAmountOfBooks;
        Book* books; // <-- to create a pointer EVERYTIME WE WANT DYNAMICAL ALLOCATION
    public:
// method which adds an existing book to the array inside the Library object
// USE references to pass the actual book
        void addBook(const Book&);
        Book & getBook(int); //  returns a book requested from the book array inside the Library object
        void showBooks();
        // constructor-distructor
        Library(int);  // THE SIZE OF THE LIBRARY NOW IS A VARIABLE: maxAmountOfBooks
        ~Library();
};


#endif // LIBRARY_H_INCLUDED
