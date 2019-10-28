#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "book.h"
#include "library.h"

//create class User with fields:
// name, lastName and methods getName getLastName,
//the constructor should initialize both fields

class User
{
    protected:
        std::string UserName;
        std::string userlastName;
    public:
        User(std::string="",std::string=""); // constructor initializes both fields
        ~User(); // destructor
        // methods declarations, in user.cpp we have definition
        std::string getName();
        std::string getLastName();
};

// create class Borrower that will inherit from the User,
// the Borrower needs member fields to store the books in his possesion
// aswell as maxAmount he can posses and the amount he already has.

class Borrower : public User
{
    protected:
        friend class Librarian;
        Book* booksInPossession;  //  store the books in his possesion
        int maxAmount; // books maxAmount he can posses
        int ActualAmount; // the amount he already has
    public:
        Borrower(std::string="",std::string="",int=0);
        ~Borrower();
        //eliminate the copy constructor and the convert consstructor for '=' operator of the borrower class
        Borrower(const Borrower&) = delete;
        Borrower& operator= (const Borrower&) = delete;

    //borrower methods:
        void returenBook(Library&, int); //return books
        Book& getBook(int id); // take book
        void showBooks(); //show all of the books in his possesion

};

#endif // USER_H_INCLUDED
