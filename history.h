// ------------------------------- history.h --------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/1/2020
// ----------------------------------------------------------------------------
// Purpose - Transaction representing printing the transaction history of
//             a customer.
// ----------------------------------------------------------------------------


#ifndef CSS343_PROGRAM4__HISTORY_H_
#define CSS343_PROGRAM4__HISTORY_H_
#include "transaction.h"
class History : public Transaction
{
 public:
  History();
  ~History();
  int getID() const;
  bool setID(int newID);
  void display() const;
  Movie* getMovie() const;
 private:
  int id = 0; // Customer ID to print history
};

#endif //CSS343_PROGRAM4__HISTORY_H_
