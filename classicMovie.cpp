// ------------------------------------------------ classicMovie.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation for classicMovie
// --------------------------------------------------------------------------------------------------------------------

#include "classicMovie.h"
ClassicMovie::ClassicMovie()
{

}

ClassicMovie::~ClassicMovie()
{

}

//-------------------------------- operator> ------------------------------------
// Operating Overload for >
// @pre m cannot be nullptr
// @post NONE

bool ClassicMovie::operator>(const Movie &m)
{
  const ClassicMovie &cMovie = static_cast<const ClassicMovie&>(m);
  if (this->getYear() > cMovie.getYear()) {
    return true;
  } else if (this->getYear() == cMovie.getYear())
  {
    if (this->getMonth() > cMovie.getMonth())
    {
      return true;
    } else if (this->getMonth() == cMovie.getMonth())
    {
      return (this->getMajorActor() > cMovie.getMajorActor());
    }
  }
  return false;
}

//-------------------------------- operator< ------------------------------------
// Operating Overload for <
// @pre m cannot be nullptr
// @post NONE

bool ClassicMovie::operator<(const Movie &m)
{
  const ClassicMovie &cMovie = static_cast<const ClassicMovie &>(m);
  if (this->getYear() < cMovie.getYear()) {
    return true;
  } else if (this->getYear()==cMovie.getYear()) {
    if (this->getMonth() < cMovie.getMonth()) {
      return true;
    } else if (this->getMonth()==cMovie.getMonth()) {
      return (this->getMajorActor() < cMovie.getMajorActor());
    }
  }
  return false;
}

//-------------------------------- operator== ------------------------------------
// Operating Overload for ==
// @pre m cannot be nullptr
// @post NONE

bool ClassicMovie::operator==(const Movie &m)
{
  const ClassicMovie &cMovie = static_cast<const ClassicMovie&>(m);
  return ((this->getMajorActor() == cMovie.getMajorActor()) && (this->getMonth() == cMovie.getMonth()) &&
      (this->getYear() == cMovie.getYear()));
}

//-------------------------------- operator!= ------------------------------------
// Operating Overload for !=
// @pre m cannot be nullptr
// @post NONE

bool ClassicMovie::operator!=(const Movie &m)
{
  return !(*this == m);
}

//-------------------------------- setMajorActor ------------------------------------
// setting Major actor name for classic movie
// @pre NONE
// @post NONE

void ClassicMovie::setMajorActor(string name)
{
  this->majorActorName = name;
}

//-------------------------------- setMonth ------------------------------------
// setting release month for classic movie
// @pre NONE
// @post NONE
void ClassicMovie::setMonth(int month)
{
  this->month = month;
}

//-------------------------------- getMajorActor ------------------------------------
// A method for getting major actor name for the classic movie
// @pre NONE
// @post NONE
string ClassicMovie::getMajorActor() const
{
  return majorActorName;
}

//-------------------------------- getMonth ------------------------------------
// A method for getting month for the classic movie
// @pre NONE
// @post NONE
int ClassicMovie::getMonth() const
{
  return month;
}

//-------------------------------- displayInfo ------------------------------------
// Print out the information about the movie
// @pre NONE
// @post NONE
void ClassicMovie::displayInfo(ostream &out) const
{
  out << getType();
  out << ", ";
  out << getStock();
  out << ", ";
  out << getDirectorName();
  out << ", ";
  out << getTitle();
  out << ", ";
  out << getMajorActor();
  out << ", ";
  out << getMonth();
  out << " ";
  out << getYear();
}
