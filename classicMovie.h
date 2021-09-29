// ------------------------------------------------ classicMovie.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface for classicMovie
// -------------------------------------------------------------------------------------------------------------------- 

#include "movie.h"

#ifndef CSS343_PROGRAM4__CLASSICMOVIE_H_
#define CSS343_PROGRAM4__CLASSICMOVIE_H_

class ClassicMovie : public Movie {
 public:
  ClassicMovie();
  ~ClassicMovie();

  bool operator>(const Movie &m);
  bool operator<(const Movie &m);
  bool operator==(const Movie &m);
  bool operator!=(const Movie &m);

  void setMajorActor(string name);
  void setMonth(int month);
  string getMajorActor() const;
  int getMonth() const;

 protected:
  void displayInfo(ostream& out) const;

 private:
  string majorActorName;
  int month;
};

#endif //CSS343_PROGRAM4__CLASSICMOVIE_H_
