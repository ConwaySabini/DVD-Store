// ----------------------------- inventory.cpp --------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/14/2020
// ----------------------------------------------------------------------------
// Purpose - Transaction representing printing the inventory of the DVD store.
// ----------------------------------------------------------------------------

#include "inventory.h"
Inventory::Inventory()
{

}

//---------------------------- printInventory() -------------------------------
// Prints every movie in the DVD store and the stock of each movie to cout.
// @param movies: tree containing movies to display
// @param movieGenre: genre for formatting the movies correctly.
// @pre Movies have been added to the DVD store.
// @post All movies are displayed to cout.
void Inventory::printInventory(const AVLTreeMovie &movies, string movieGenre) const
{
  cout << "-------" << movieGenre << " " << "Movies" << "--------" << endl;
  if (movies.isEmpty())
  {
    cout << "There is any movies" << endl;
    return ;
  }
  movies.Display();
}

//-------------------------------- getID() ------------------------------------
// Returns 0 because there is no customer involved with this transaction.
// @pre id member is set.
// @post None.
int Inventory::getID() const
{
  return 0;
}

//------------------------------- getMovie() ----------------------------------
// Returns nullptr meaning that there is not movie for this transaction.
// @pre None.
// @post None.
Movie *Inventory::getMovie() const
{
  return nullptr;
}

//------------------------------- display() -----------------------------------
// Displays nothing because there is no need.
// @pre None.
// @post None.

void Inventory::display() const
{

}
