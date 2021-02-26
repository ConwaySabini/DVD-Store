// ------------------------------------------------ movieFactory.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/13/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - For processing movie input for transaction and movie data
// -------------------------------------------------------------------------------------------------------------------- 

#ifndef CSS343_PROGRAM4__MOVIEFACTORY_H_
#define CSS343_PROGRAM4__MOVIEFACTORY_H_

#include "movie.h"
#include <sstream>
#include "classicMovie.h"
#include "comedyMovie.h"
#include "dramaMovie.h"
#include <string>

class movieFactory
{
 public:
  movieFactory();
  Movie*  processTransMovie(stringstream &input); // input process movie for transaction
  Movie*  processMovie(stringstream &input); // input process for movie
};

#endif //CSS343_PROGRAM4__MOVIEFACTORY_H_
