// ------------------------------------------------ store.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface for Store. Process transaction and read all files
// --------------------------------------------------------------------------------------------------------------------

#ifndef CSS343_PROGRAM4__STORE_H_
#define CSS343_PROGRAM4__STORE_H_
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "comedyMovie.h"
#include "dramaMovie.h"
#include "classicMovie.h"
#include "AVLTreeMovie.h"
#include "hashtable.h"
#include "transaction.h"
#include "return.h"
#include "borrow.h"
#include "history.h"
#include "inventory.h"
#include "movieFactory.h"
using namespace std;
class Store
{
 public:
  Store();
  // Check for valid input and add movies to the AVL tree
  void addMovies(string fileName);
  // Check for valid input and add customers to the hash table
  void addCustomers(string fileName);
  // Check for valid input and add transactions to the queue to process
  void addTransactions(string fileName);
  // Process the transactions in order of the queue and ouput all errors
  void processTrans();

 private:
  queue<Transaction*> commands;
  HashTable customers;
  AVLTreeMovie comedies;
  AVLTreeMovie classics;
  AVLTreeMovie dramas;

  void addBorrow(stringstream &input);
  void addReturn(stringstream &input);
};

#endif //CSS343_PROGRAM4__STORE_H_
