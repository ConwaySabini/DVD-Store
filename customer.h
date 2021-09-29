// ------------------------------------------------ customer.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface for customer
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef CSS343_PROGRAM4__CUSTOMER_H_
#define CSS343_PROGRAM4__CUSTOMER_H_

#include <string>
#include <vector>
#include "movie.h"
#include "transaction.h"
#include "AVLTreeMovie.h"

class Customer
{
 public:
  Customer();
  // Adds the transasction the customer made to the vector
  bool addTrans(string transaction);
  bool setID(const int& newID);
  bool setfName(string newName);
  bool setlName(string newName);
  bool addMovie(Movie* movie); // adds the borrowed movie top the customers list
  int getID() const;
  string getfName() const;
  string getlName() const;
  bool returnMovie(Movie* movie);
  void printHistory() const; // Prints the history of transactions to cout

 private:
  int id; // 4 digit id
  string fName; // First name followed by a space and last name
  string lName;
  vector<string> history; // Transactions made
  AVLTreeMovie comedies; // comedy movie the customer borrowed
  AVLTreeMovie dramas; // drama movie the customer borrowed
  AVLTreeMovie classics; // comedy movie the customer borrowed
};

#endif //CSS343_PROGRAM4__CUSTOMER_H_
