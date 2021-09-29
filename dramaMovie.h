// ------------------------------------------------ dramaMovie.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface for dramaMovie
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef CSS343_PROGRAM4__DRAMAMOVIE_H_
#define CSS343_PROGRAM4__DRAMAMOVIE_H_

#include "movie.h"
class DramaMovie : public Movie
{
 public:
  DramaMovie();
  ~DramaMovie();

  bool operator>(const Movie &m);
  bool operator<(const Movie &m);
  bool operator==(const Movie &m);
  bool operator!=(const Movie &m);

 protected:
  void displayInfo(ostream &out) const;

};

#endif //CSS343_PROGRAM4__DRAMAMOVIE_H_
