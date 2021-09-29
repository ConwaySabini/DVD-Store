// ------------------------------------------------ borrow.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface for borrow transaction
// --------------------------------------------------------------------------------------------------------------------

#ifndef CSS343_PROGRAM4__BORROW_H_
#define CSS343_PROGRAM4__BORROW_H_

#include "movie.h"
#include "transaction.h"
class Borrow : public Transaction
{
 public:
  Borrow();
  ~Borrow(); // Destructor
  int getID() const;
  Movie* getMovie() const;
  bool setMediaType(char type);
  char getMediaType();
  bool setID(int newID);
  bool setMovie(Movie* newMovie);
  void display() const;
 private:
  int id; // Customer id
  Movie* movie; // Movie to borrow from store
  char mediaType; // mediaType for movie
};

#endif //CSS343_PROGRAM4__BORROW_H_
