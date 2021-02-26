// ------------------------------------------------ customer.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation for customer
// -------------------------------------------------------------------------------------------------------------------- 

#include "customer.h"
#include "customer.h"

Customer::Customer()
{

}

//------------------------------- addTrans() ----------------------------------
// Add a transaction to the vector and returns true.
// @param transaction string representing the action taken by the customer.
// @pre Transaction object is created.
// @post String of transaction is inserted in the vector.
bool Customer::addTrans(string transaction) {
  history.push_back(transaction);
  return true;
}

//----------------------------- printHistory() --------------------------------
// Prints the history of transactions to cout.
// @pre Transaction records are inserted.
// @post History of transactions for customer are printed to cout.
void Customer::printHistory() const
{
  cout << "History for Customer: " << getID() << endl;
  if (history.size() == 0)
  {
    cout << "Empty History for " << getID() << endl;
    return ;
  }
  for (int i = history.size() - 1; i >= 0; i--)
  {
    cout << history[i];
    cout << endl;
  }
  cout << endl;
}

//--------------------------------- setID() -----------------------------------
// Sets the ID of the customer if it is a four digit number and returns true.
// Returns false otherwise.
// @param newID of customer.
// @pre None.
// @post ID member is set.
bool Customer::setID(const int& newID)
{
  if (newID >= 1000 && newID <= 9999)
  {
    id = newID;
    return true;
  } else
  {
    cout << "Customer ID must be in range between 1000 and 9999: ";
    return false;
  }
}

//------------------------------- setfName() ----------------------------------
// Sets the first name of the customer and returns true.
// @param newName: First name of customer.
// @pre None.
// @post fName member is set.
bool Customer::setfName(string newName) {
  this->fName = newName;
  return true;
}

//------------------------------- setlName() ----------------------------------
// Sets the last name of the customer and returns true.
// @param newName: Last name of customer.
// @pre None.
// @post lName member is set.
bool Customer::setlName(string newName) {
  this->lName = newName;
  return true;
}

//------------------------------- addMovie() ----------------------------------
// Adds movie to the list of movies the customer has borrowed. Increases stock
//    by one and returns true if successful and false otherwise.
// @param movie: movie that the customer has borrowed.
// @pre Customer has borrowed movie.
// @post movie is added to the list of borrowed movies and amount is increased.
bool Customer::addMovie(Movie* movie)
{
  char type = movie->getType();
  Movie* foundMovie = nullptr;
  if (type == 'D')
  {
   if (dramas.retrieve(movie, foundMovie))
   {
     int amount = foundMovie->getStock();
     amount++;
     foundMovie->setStock(amount);
   } else
   {
     movie->setStock(1);
     dramas.Insert(movie);
   }
  } else if (type == 'F')
  {
    if (comedies.retrieve(movie, foundMovie))
    {
      int amount = foundMovie->getStock();
      amount++;
      foundMovie->setStock(amount);
    } else
    {
      movie->setStock(1);
      comedies.Insert(movie);
    }
  } else if (type == 'C')
  {
    if (classics.retrieve(movie, foundMovie))
    {
      int amount = foundMovie->getStock();
      amount++;
      foundMovie->setStock(amount);
    } else
    {
      movie->setStock(1);
      classics.Insert(movie);
    }
  }
  return true;
}

//------------------------------ returnMovie() --------------------------------
// Decreases the stock of the movie borrowed by one.
// Returns true if the return was successful and false otherwise.
//    otherwise.
// @param movie: movie to return.
// @pre Customer has borrowed movie.
// @post Customer tree is updated.
bool Customer::returnMovie(Movie *movie)
{
  char type = movie->getType();
  Movie* foundMovie = nullptr;
  if (type == 'D')
  {
    if (dramas.retrieve(movie, foundMovie))
    {
      int amount = foundMovie->getStock();
      if (amount == 0) return false;
      amount--;
      foundMovie->setStock(amount);
    } else
    {
      return false;
    }
  } else if (type == 'F')
  {
    if (comedies.retrieve(movie, foundMovie))
    {
      int amount = foundMovie->getStock();
      if (amount == 0) return false;
      amount--;
      foundMovie->setStock(amount);
    } else
    {
      return false;
    }
  } else if (type == 'C')
  {
    if (classics.retrieve(movie, foundMovie))
    {
      int amount = foundMovie->getStock();
      if (amount == 0) return false;
      amount--;
      foundMovie->setStock(amount);
    } else
    {
      return false;
    }
  }
  return true;
}

//------------------------------- getfName() ----------------------------------
// Returns first name of customer.
// @pre fName member has been set.
// @post None.
string Customer::getfName() const {
  return this->fName;
}

//------------------------------- getlName() ----------------------------------
// Returns last name of customer.
// @pre lName member has been set.
// @post None.
string Customer::getlName() const {
  return this->lName;
}

//-------------------------------- getID() ------------------------------------
// Returns the id of customer.
// @pre id member has been set.
// @post None.
int Customer::getID() const {
  return this->id;
}
