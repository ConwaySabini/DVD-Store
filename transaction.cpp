// --------------------------- transaction.cpp --------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/14/20
// ----------------------------------------------------------------------------
// Purpose - Interface of Abstract Transaction class
// ----------------------------------------------------------------------------

#include "transaction.h"
Transaction::Transaction() {

}

Transaction::~Transaction() {

}

//------------------------------ getType() -----------------------------------
// Returns type of the tansaction.
// @pre NONE
// @post NONE
char Transaction::getType() const {
  return this->type;
}

//------------------------------ setType() -----------------------------------
// Sets the type of the transaction.
// @param newType: type of transaction must be one of four valid characters.
// @pre None.
// @post type member is set.
bool Transaction::setType(char newType) {
  if (newType == 'B' || newType == 'R' || newType == 'H' || newType == 'I') {
    this->type = newType;
    return true;
  }
  return false;
}

//------------------------------ getMovie() -----------------------------------
// Returns pointer to movie being borrowed.
// @pre movie member is assigned.
// @post movie pointer is returned.
Movie *Transaction::getMovie() const
{
  return this->movie;
}

//------------------------------ getRecord() ----------------------------------
// Returns a string containing the record of information for the transaction.
// @pre record of transction is set.
// @post None.
string Transaction::getRecord() const
{
  return this->record;
}

//------------------------------ setRecord() ----------------------------------
// Sets the record for the transaction
// @param line: contains the information for the transaction.
// @pre None.
// @post record member is set.
void Transaction::setRecord(string line)
{
  this->record = line;
}
