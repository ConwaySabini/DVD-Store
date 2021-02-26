// -------------------------------- return.cpp ----------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/27/20
// Date of Last Modification: 3/14/2020
// ----------------------------------------------------------------------------
// Purpose - Transaction representing returning a movie from a customer to
//              the DVD store.
// ----------------------------------------------------------------------------

#include "return.h"

Return::Return()
{

}

//------------------------------- ~Return() -----------------------------------
// Frees all allocated variables.
// @pre destructor is called.
// @post movie member is deleted.
Return::~Return() {
  delete this->movie;
  this->movie = nullptr;
}

//-------------------------------- getID() ------------------------------------
// Returns the id of the customer to display return movie.
// @pre id member is set.
// @post None.
int Return::getID() const {
  return this->id;
}

//------------------------------ getMovie() -----------------------------------
// Returns pointer to movie being borrowed.
// @pre movie member is assigned.
// @post movie pointer is returned.
Movie* Return::getMovie() const {
  return this->movie;
}

//-------------------------------- setID() ------------------------------------
// Returns true and sets the id if the id is in range and returns false
//      if the id is not in range.
// @pre None.
// @post id member is set.
bool Return::setID(int newID) {
  if (newID >= 1000 && newID <= 9999) {
    this->id = newID;
    return true;
  }
  return false;
}

//------------------------------ setMovie() -----------------------------------
// Returns true and sets the movie being borrowed.
// @pre None.
// @post Movie member is set.
bool Return::setMovie(Movie* newMovie)
{
  this->movie = newMovie;
  return true;
}

//------------------------------ display() ----------------------------------
// Displays the return transaction information to cout.
// @pre record of transction is set.
// @post transaction information is displayed to cout.
void Return::display() const
{
  cout << getRecord() << endl;
}

//----------------------------- setMediaType() --------------------------------
// Sets type of media to borrow with the only current option being D for DVD.
// @pre None.
// @post mediaType member is set to type ('D').
bool Return::setMediaType(char type)
{
  if (type != 'D')
  {
    cout << "Not a right mediaType ";
    return false;
  }
  else return true;
}

//----------------------------- getMediaType() --------------------------------
// Sets type of media to borrow with the only current option being D for DVD.
// @pre None.
// @post mediaType member is set to type ('D').
char Return::getMediaType()
{
  return this->mediaType;
}
