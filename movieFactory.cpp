// ------------------------------------------------ movieFactory.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/13/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - implementation for movieFactory
// -------------------------------------------------------------------------------------------------------------------- 

#include "movieFactory.h"
movieFactory::movieFactory()
{

}

Movie *movieFactory::processTransMovie(stringstream &input)
{
 string readInput;
 getline(input, readInput, ' ');
 char genre = readInput[0];
  if (genre == 'C') {
    string actor, actorL = "";
    getline(input, readInput, ' ');
    int month = stoi(readInput);
    getline(input, readInput, ' ');
    int year = stoi(readInput);
    getline(input, readInput, ' ');
    actor = readInput;
    getline(input, readInput, '\r');
    actorL = readInput;
    actor.append(" " + actorL);
    ClassicMovie* classic = new ClassicMovie();
    classic->setType(genre);
    classic->setMonth(month);
    classic->setYear(year);
    classic->setMajorActor(actor);
    return classic;
  }
  else if (genre == 'F') {
    string title = "";
    int year;
    Movie* comedy = new ComedyMovie();
    getline(input, readInput, ',');
    title = readInput;
    getline(input, readInput);
    year = stoi(readInput);
    comedy->setType(genre);
    comedy->setTitle(title);
    comedy->setYear(year);
    return comedy;
  }
  else if (genre == 'D') {
    string director = "", title = "";
    Movie* drama = new DramaMovie();
    getline(input, readInput, ',');
    director = readInput;
    input.ignore(); // skip white space
    getline(input, readInput, ',');
    title = readInput;
    drama->setType(genre);
    drama->setTitle(title);
    drama->setDirectorName(director);
    return drama;
  }
  else
  {
    cout << "Invalid movie type: ";
    return nullptr;
  }
}

Movie *movieFactory::processMovie(stringstream &input)
{
  string readInput;
  getline(input, readInput, ',');
  char genre = readInput[0];
  getline(input, readInput, ',');
  int stock = stoi(readInput);
  if (genre == 'C') {
    input.ignore(); // skip white space
    getline(input, readInput, ',');
    string director = readInput;
    input.ignore(); // skip white space
    getline(input, readInput, ',');
    string title = readInput;
    string actor, actorL = "";
    input.ignore(); // skip white space
    getline(input, readInput, ' ');
    actor = readInput;
    getline(input, readInput, ' ');
    actorL = readInput;
    actor.append(" " + actorL);
    getline(input, readInput, ' ');
    int month = stoi(readInput);
    getline(input, readInput);
    int year = stoi(readInput);
    ClassicMovie* classic = new ClassicMovie();
    classic->setType(genre);
    classic->setStock(stock);
    classic->setDirectorName(director);
    classic->setTitle(title);
    classic->setMajorActor(actor);
    classic->setMonth(month);
    classic->setYear(year);
    return classic;
  }
  else if (genre == 'F') {
    input.ignore(); // skip white space
    getline(input, readInput, ',');
    string director = readInput;
    string title = "";
    int year;
    Movie* comedy = new ComedyMovie();
    input.ignore(); // skip white space
    getline(input, readInput, ',');
    title = readInput;
    getline(input, readInput);
    year = stoi(readInput);
    comedy->setType(genre);
    comedy->setStock(stock);
    comedy->setDirectorName(director);
    comedy->setTitle(title);
    comedy->setYear(year);
    return comedy;
  }
  else if (genre == 'D') {
    string director = "", title = "";
    Movie* drama = new DramaMovie();
    input.ignore(); // skip white space
    getline(input, readInput, ',');
    director = readInput;
    input.ignore(); // skip white space
    getline(input, readInput, ',');
    title = readInput;
    getline(input, readInput);
    int year = stoi(readInput);
    drama->setType(genre);
    drama->setStock(stock);
    drama->setTitle(title);
    drama->setDirectorName(director);
    drama->setYear(year);
    return drama;
  }
  else
  {
    cout << "Invalid movie type: ";
    return nullptr;
  }
}

