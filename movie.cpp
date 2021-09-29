// ------------------------------------------------ movie.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation for movie
// -------------------------------------------------------------------------------------------------------------------- 

#include "movie.h"
Movie::Movie()
{

}

Movie::~Movie()
{

}

//-------------------------------- getTitle ------------------------------------
// A method for getting title of the movie
// @pre NONE
// @post NONE
string Movie::getTitle() const
{
  return title;
}

//-------------------------------- getType ------------------------------------
// A method for getting type for the movie
// @pre NONE
// @post NONE
char Movie::getType() const
{
  return type;
}
//-------------------------------- getDirectorName ------------------------------------
// A method for getting director name for the movie
// @pre NONE
// @post NONE
string Movie::getDirectorName() const
{
  return directorName;
}
//-------------------------------- getYear ------------------------------------
// A method for getting year of the movie
// @pre NONE
// @post NONE
int Movie::getYear() const
{
  return year;
}
//-------------------------------- getStock ------------------------------------
// A method for get stock of the movie
// @pre NONE
// @post NONE
int Movie::getStock() const
{
  return stock;
}
//-------------------------------- setTitle ------------------------------------
// set the title for the movie
// @pre NONE
// @post NONE
void Movie::setTitle(string title)
{
  this->title = title;
}
//-------------------------------- setDirectorName ------------------------------------
// Set director name for the movie
// @pre NONE
// @post NONE
void Movie::setDirectorName(string name)
{
  this->directorName = name;
}
//-------------------------------- setType ------------------------------------
// Set movie type for the movie
// @pre NONE
// @post NONE
void Movie::setType(char type)
{
  this->type = type;
}
//-------------------------------- setYear ------------------------------------
// set year for the movie
// @pre NONE
// @post NONE
void Movie::setYear(int year)
{
  this->year = year;
}
//-------------------------------- setStock ------------------------------------
// set stock for the movie
// @pre NONE
// @post NONE
void Movie::setStock(int stock)
{
  this->stock = stock;
}
