// -------------------------------- return.h ----------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/14/2020
// ----------------------------------------------------------------------------
// Purpose - Transaction representing returning a movie from a customer to
//              the DVD store.
// ----------------------------------------------------------------------------

#ifndef CSS343_PROGRAM4__RETURN_H_
#define CSS343_PROGRAM4__RETURN_H_

#include "movie.h"
#include "transaction.h"
class Return : public Transaction
{
 public:
  Return();
  ~Return(); // Destructor
  int getID() const; // get customer ID
  Movie* getMovie() const;
  bool setID(int newID); // set customer ID
  bool setMovie(Movie* newMovie);
  void display() const;
  bool setMediaType(char type);
  char getMediaType();
 private:
  int id; // Customer id
  Movie* movie; // Movie to return to store
  char mediaType; // mediaType for movie
};

#endif //CSS343_PROGRAM4__RETURN_H_
