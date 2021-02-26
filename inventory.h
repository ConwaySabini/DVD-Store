// ------------------------------- inventory.h --------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/14/2020
// ----------------------------------------------------------------------------
// Purpose - Transaction representing printing the inventory of the DVD store.
// ----------------------------------------------------------------------------

#ifndef CSS343_PROGRAM4__INVENTORY_H_
#define CSS343_PROGRAM4__INVENTORY_H_

#include "AVLTreeMovie.h"
#include "transaction.h"
class Inventory : public Transaction
{
 public:
  Inventory();
  void printInventory(const AVLTreeMovie& movies, string movieGenre) const; // Prints all DVD's to cout
  int getID() const;
  Movie* getMovie() const;
  void display() const;
};

#endif //CSS343_PROGRAM4__INVENTORY_H_
