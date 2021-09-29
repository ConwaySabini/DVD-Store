// ------------------------------------------------ comedyMovie.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation for ComedyMovie
// -------------------------------------------------------------------------------------------------------------------- 

#include "comedyMovie.h"
ComedyMovie::ComedyMovie() {

}

ComedyMovie::~ComedyMovie() {

}

//-------------------------------- operator> ------------------------------------
// Operating Overload for >
// @pre m cannot be nullptr
// @post NONE

bool ComedyMovie::operator>(const Movie &m) {
  if (this->getTitle() > m.getTitle())
  {
    return true;
  } else if (this->getTitle() == m.getTitle())
  {
    return (this->getYear() > m.getYear());
  } else
    return false;
}

//-------------------------------- operator< ------------------------------------
// Operating Overload for <
// @pre m cannot be nullptr
// @post NONE
bool ComedyMovie::operator<(const Movie &m) {
  if (this->getTitle() < m.getTitle())
  {
    return true;
  } else if (this->getTitle() == m.getTitle())
  {
    return (this->getYear() < m.getYear());
  } else
    return false;
}

//-------------------------------- operator== ------------------------------------
// Operating Overload for ==
// @pre m cannot be nullptr
// @post NONE
bool ComedyMovie::operator==(const Movie &m) {
  return ((this->getTitle() == m.getTitle()) && (this->getYear() == m.getYear()));
}

//-------------------------------- operator!= ------------------------------------
// Operating Overload for !=
// @pre m cannot be nullptr
// @post NONE
bool ComedyMovie::operator!=(const Movie &m) {
  return !(*this != m);
}

//-------------------------------- displayInfo ------------------------------------
// Print out the information about the movie
// @pre NONE
// @post NONE
void ComedyMovie::displayInfo(ostream &out) const {
  out << getType();
  out << ", ";
  out << getStock();
  out << ", ";
  out << getDirectorName();
  out << ", ";
  out << getTitle();
  out << ", ";
  out << getYear();
}
