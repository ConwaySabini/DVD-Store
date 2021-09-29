// ------------------------------------------------ main.cpp --------------------------------------------------------
// Created by Henry Park & Ethan Sabini from CSS 343 C
// Creation Date: 3/2/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Main program
// --------------------------------------------------------------------------------------------------------------------
#include "store.h"

int main()
{
  Store s1;
  s1.addMovies("data4movies.txt"); // add movie
  s1.addCustomers("data4customers.txt"); // add customer
  s1.addTransactions("data4commands.txt"); // add transaction
  s1.processTrans(); // process the transaction
  return 0;
}