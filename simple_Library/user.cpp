#include <iostream>
#include "book.h"
#include "library.h"
#include "user.h"

using namespace std;

//create class User with fields:
// name, lastName and methods getName getLastName,
//the constructor should initialize both fields

// the constructor initializes both fields
User::User(string UserName, string userlastName)
{
    this->UserName = UserName;
    this->userlastName = userlastName;
}
// the destructor
User::~User()
{

}
//methods definition getName getLastName
string User::getName() { return this-> UserName;}
string User::getLastName() { return this->userlastName;}


// for the Borrowers
Borrower::Borrower(string UserName, string userlastName, int maxAmount) : User (UserName, userlastName)
{
    this->ActualAmount = 0;
    this->maxAmount=maxAmount;
    booksInPossession = new Book[maxAmount];
}

Borrower::~Borrower()
{
    delete [] booksInPossession;
}

