// ------------------------------------------------ movie.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface for movie
// -------------------------------------------------------------------------------------------------------------------- 

#include <string>
#include <iostream>

#ifndef CSS343_PROGRAM4__MOVIE_H_
#define CSS343_PROGRAM4__MOVIE_H_

using namespace std;

class Movie
{
 public:
  Movie();
  virtual ~Movie(); // Make this class Abstract
  string getTitle() const;
  char getType() const;
  string getDirectorName() const;
  int getYear() const;
  int getStock() const;

  // TODO: Error handling for the each input
  // ex) what if the user put stock as negative integer?
  void setTitle(string title);
  void setDirectorName(string name);
  void setType(char type);
  void setYear(int year);
  void setStock(int stock);

  // Operator overload for sort and save in tree
  virtual bool operator>(const Movie &m) = 0;
  virtual bool operator<(const Movie &m) = 0;
  virtual bool operator==(const Movie &m) = 0;
  virtual bool operator!=(const Movie &m) = 0;

  //show movie
  friend ostream& operator<<(ostream& out, Movie &m)
  {
    m.displayInfo(out);
    return out;
  }

 protected:
  virtual void displayInfo(ostream& out) const = 0; // show info of the movie

 private:
  string title;
  char type;
  string directorName;
  int stock;
  int year;
};

#endif //CSS343_PROGRAM4__MOVIE_H_
