// ------------------------------------------------ comedyMovie.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface for comedyMovie
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef CSS343_PROGRAM4__COMEDYMOVIE_H_
#define CSS343_PROGRAM4__COMEDYMOVIE_H_
#include "movie.h"
class ComedyMovie : public Movie
{
 public:
  ComedyMovie();
  ~ComedyMovie();

  bool operator>(const Movie &m);
  bool operator<(const Movie &m);
  bool operator==(const Movie &m);
  bool operator!=(const Movie &m);

 protected:
  void displayInfo(ostream& out) const;
};

#endif //CSS343_PROGRAM4__COMEDYMOVIE_H_
