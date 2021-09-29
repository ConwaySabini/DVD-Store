// ------------------------------ history.cpp ---------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/14/2020
// ----------------------------------------------------------------------------
// Purpose - Transaction representing printing the transaction history of
//             a customer.
// ----------------------------------------------------------------------------

#include "history.h"
History::History() {

}

History::~History()
{

}

//-------------------------------- getID() ------------------------------------
// Returns the id of the customer to display history.
// @pre id member is set.
// @post None.
int History::getID() const {
  return this->id;
}

//-------------------------------- setID() ------------------------------------
// Returns true if the id is set and within range and false otherwise.
// @pre newID is within four digit range.
// @post id member is set.
bool History::setID(int newID) {
  if (newID >= 1000 && newID <= 9999)
  {
    this->id = newID;
    return true;
  }
  cout << "Customer ID must be in range between 1000 and 9999: ";
  return false;
}

//------------------------------- display() -----------------------------------
// Displays nothing because there is no need.
// @pre None.
// @post None.

void History::display() const {
}

//------------------------------- getMovie() ----------------------------------
// Returns nullptr meaning that there is not movie for this transaction.
// @pre None.
// @post None.
Movie *History::getMovie() const {
  return nullptr;
}
