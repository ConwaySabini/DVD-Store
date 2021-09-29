// ------------------------------------------------ borrow.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation for borrow
// -------------------------------------------------------------------------------------------------------------------- 

#include "borrow.h"

Borrow::Borrow()
{

}

//------------------------------- ~Borrow() -----------------------------------
// Frees all allocated variables.
// @pre destructor is called.
// @post movie member is deleted.
Borrow::~Borrow() {
  delete this->movie;
  this->movie = nullptr;
}

//-------------------------------- getID() ------------------------------------
// Returns integer of id.
// @pre ID is set.
// @post ID of customer in transaction is returned.
int Borrow::getID() const {
  return this->id;
}

//------------------------------ getMovie() -----------------------------------
// Returns pointer to movie being borrowed.
// @pre movie member is assigned.
// @post movie pointer is returned.
Movie* Borrow::getMovie() const {
  return this->movie;
}

//-------------------------------- setID() ------------------------------------
// Returns true and sets the id if the id is in range and returns false
//      if the id is not in range.
// @pre None.
// @post id member is set.
bool Borrow::setID(int newID) {
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
bool Borrow::setMovie(Movie* newMovie) {
  this->movie = newMovie;
  return true;
}

//------------------------------ display() ----------------------------------
// Displays the borrow transaction information to cout.
// @pre record of transction is set.
// @post transaction information is displayed to cout.
void Borrow::display() const
{
  cout << getRecord() << endl;
}

//----------------------------- setMediaType() --------------------------------
// Sets type of media to borrow with the only current option being D for DVD.
// @pre None.
// @post mediaType member is set to type ('D').

bool Borrow::setMediaType(char type) {
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
char Borrow::getMediaType()
{
  return this->mediaType;
}

