#include "library.h"

// i AM USING const REFERENCES TO THE BOOK
void Library::addBook(const Book & book) //adds the book to the first free position on the shelve
{
    if (currentAmountOfBooks < maxAmountOfBooks) //check if the maxAmountOfbooks is exceeded
    {
        this->books[currentAmountOfBooks] = book; //adds the book to the first free position
        this->currentAmountOfBooks++;
    }
    else
    {

    }
}
//references to pass the actual book
Book& Library::getBook(int position)
{
    if (position < maxAmountOfBooks) // check if the index of the book doesn't exceed maxAmountOfbooks
    {
        return books[position]; // if the maxAmountOfBooks is exceeded return, first book in the set by default
    }
    else
    {
        return books[0];
    }
}

void Library::showBooks()
{
    for (int i = 0; i < currentAmountOfBooks; i++)
    {
        std::cout << "POSITION IN LIBRARY: " << i << "  ";
        std::cout << "Author: " << getBook(i).getAuthor() << "  ";
        std::cout << "Title: " << getBook(i).getTitle() << "  ";
        std::cout << "Publication Year: " << getBook(i).getPublicationYear() << std::endl;
        std::cout << "Unique ID: " << getBook(i).getBookId() << std::endl;
    }
}

// the constructor
Library::Library(int maxAmountOfBooks)
{
    this->currentAmountOfBooks = 0; // reset the counter to be used by another library
    this->maxAmountOfBooks = maxAmountOfBooks;
    this->books = new Book[maxAmountOfBooks]; // array of Books is created dynamically
}


// the destructor
Library::~Library()
{
    delete [] books;
}
