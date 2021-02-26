// ------------------------------------------------ dramaMovie.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation for dramaMovie
// -------------------------------------------------------------------------------------------------------------------- 

#include "dramaMovie.h"
DramaMovie::DramaMovie()
{

}

DramaMovie::~DramaMovie()
{

}

//-------------------------------- operator> ------------------------------------
// Operating Overload for >
// @pre m cannot be nullptr
// @post NONE
bool DramaMovie::operator>(const Movie &m)
{
  if (this->getDirectorName() > m.getDirectorName())
  {
    return true;
  } else if (this->getDirectorName() == m.getDirectorName())
  {
    return (this->getTitle() > m.getTitle());
  } else
    return false;
}
//-------------------------------- operator< ------------------------------------
// Operating Overload for <
// @pre m cannot be nullptr
// @post NONE
bool DramaMovie::operator<(const Movie &m)
{
  if (this->getDirectorName() < m.getDirectorName())
  {
    return true;
  } else if (this->getDirectorName() == m.getDirectorName())
  {
    return (this->getTitle() < m.getTitle());
  } else
    return false;
}
//-------------------------------- operator== ------------------------------------
// Operating Overload for ==
// @pre m cannot be nullptr
// @post NONE
bool DramaMovie::operator==(const Movie &m)
{
  return ((this->getTitle() == m.getTitle()) && (this->getDirectorName() == m.getDirectorName()));
}
//-------------------------------- operator!= ------------------------------------
// Operating Overload for !=
// @pre m cannot be nullptr
// @post NONE
bool DramaMovie::operator!=(const Movie &m)
{
  return !(*this == m);
}
//-------------------------------- displayInfo ------------------------------------
// Print out the information about the movie
// @pre NONE
// @post NONE
void DramaMovie::displayInfo(ostream &out) const
{
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
