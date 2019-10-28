#include "book.h"
using namespace std;


int Book::numberOfBooks = 0;
// methods for each of the book field, get methods on the book objects
string Book::getTitle() const { return this->booktitle;}

string Book::getAuthor() const { return this->bookauthor;}

int Book::getPublicationYear() const { return this->publicationYear;}

int Book::getBookId() const { return this->bookId; }

//redefine the copy constructor for book class
// use references to pass the actual book
//in order to preserve the UNIQUE ID given during creation.
Book::Book(const Book& bookToCopy)
{
    this->bookauthor = bookToCopy.bookauthor;
    this->booktitle = bookToCopy.booktitle;
    this->publicationYear = bookToCopy.publicationYear;
    this->bookId = Book::numberOfBooks++;
}

// constructor so it initializes the book parameters (title, author, publication year)
Book::Book(string bookauthor, string booktitle, int publicationYear)
{
    this->bookauthor = bookauthor;
    this->booktitle = booktitle;
    this->publicationYear = publicationYear;
    this->bookId = Book::numberOfBooks++; //give each of the book an unique ID number
}


Book::Book() {}

Book::~Book() {}
