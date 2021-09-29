// ------------------------------- hashtable.h --------------------------------
// Created by Ethan Sabini: CSS 343 C
// Creation Date: 2/29/20
// Date of Last Modification: 3/12/20
// ----------------------------------------------------------------------------
// Purpose - Represents the hash table that is used to contain the customers
//              with the 4 digit ID used as the search key and customer object
//              as the value in the hash table. Get, put, and remove operations
//              can be done in O(1) time complexity on average. This hash table
//              uses separate chaining for collision resolution.
// ----------------------------------------------------------------------------

#ifndef CSS343_PROGRAM4__HASHTABLE_H_
#define CSS343_PROGRAM4__HASHTABLE_H_

#include <vector>
#include "customer.h"

const int MAX_TABLE = 10007;

class HashTable
{
 public:
  HashTable();
  ~HashTable();
  // hash algorithm uses the size of the table for mod
  int hash(const int &id);
  bool put(const int &id, Customer *value); // adds the customer to the table
  bool remove(const int &id); // removes the customer from the hash table
  // retrieves the customer and assigns it to value
  bool get(const int &id, Customer *&value);

 private:
  struct HashNode { // Each bucket in table contains linked list
    HashNode(const int &id, Customer *customer) {
      this->key = id; // key value
      this->value = &(*customer); // customer object
    }
    int key = 0;
    Customer* value = nullptr;
    HashNode* next = nullptr; // next customer in bucket
  };
  HashNode* table[MAX_TABLE]; // hash table
};

#endif //CSS343_PROGRAM4__HASHTABLE_H_
