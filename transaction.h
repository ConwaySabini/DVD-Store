// ----------------------------- transaction.h --------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/14/20
// ----------------------------------------------------------------------------
// Purpose - Interface of Abstract Transaction class
// ----------------------------------------------------------------------------

#ifndef CSS343_PROGRAM4__TRANSACTION_H_
#define CSS343_PROGRAM4__TRANSACTION_H_
#include <iostream>
#include "movie.h"
class Transaction
{
 public:
  Transaction();
  virtual ~Transaction(); // create abstract class
  char getType() const; // type for transaction
  virtual int getID() const = 0; // get customer ID
  virtual Movie* getMovie() const = 0; // get Movie object
  bool setType(char newType); // Sets instance variable for action taken
  virtual void display() const = 0;
  void setRecord(string line); // set line of transaction
  string getRecord() const;
 private:
  Movie* movie; // movie information for this transaction
  char type; // Action taken by customer
  string record; // line of transaction
};

#endif //CSS343_PROGRAM4__TRANSACTION_H_
