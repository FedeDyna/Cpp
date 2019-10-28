#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
using namespace std;

class Book
{
    private:
        string booktitle;
        string bookauthor;
        short publicationYear; // give each of the book an unique ID number
        int bookId;
    public:
        static int numberOfBooks;  // number of books that were already created
        string getTitle() const;  // because the objects are constant, also the methods must be
        string getAuthor() const;
        int getPublicationYear() const;
        int getBookId() const;

        //use references to pass the actual book (not a copy) in order to preserve the UNIQUE ID given during creation.
        Book(const Book&);
        Book(string, string, int); // constructor so it initializes the book parameters (title, author, publication y
        Book(); // overload the constructor
        ~Book();
};


#endif // BOOK_H_INCLUDED
