// ----------------------------- hashtable.cpp --------------------------------
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

#include "hashtable.h"

//------------------------------- HashTable() ---------------------------------
// Initialized all array values to nullptr.
// @pre Default constructor called.
// @post Hash Table created.
HashTable::HashTable() {
  for (int i = 0; i < MAX_TABLE; ++i) {
    table[i] = nullptr;
  }
}

//------------------------------ ~HashTable() ---------------------------------
// Deletes all nodes in the hash table when destructor is called.
// @pre Destructor is called.
// @post Hash Table is deleted.
HashTable::~HashTable() {
  HashNode* next;
  HashNode* current;
  for (int i = 0; i < MAX_TABLE; ++i) {
    current = table[i];
    while (current != nullptr) {
      next = current->next;
      delete current->value;
      delete current;
      current = next;
    }
    table[i] = nullptr;
  }
}

//--------------------------------- hash() ------------------------------------
// Hashes the id and returns the index to insert.
// @param id of customer.
// @pre id is within the correct range.
// @post hash index is returned for insertion.
int HashTable::hash(const int &id) {
  return id % MAX_TABLE;
}

//--------------------------------- put() -------------------------------------
// Inserts the customer into the hash table with the param id.
// @param id of customer.
// @param value customer object to insert.
// @pre id is within the correct range and not duplicate.
// @post customer is inserted in hash table.
bool HashTable::put(const int &id, Customer *value) {
  if (!(id >= 1000 && id <= 9999)) {
    cout << "Id is not within range: ";
    return false;
  }
  int index = hash(id);
  if (table[index] == nullptr) {
    table[index] = new HashNode(id, value);
  }
  else {
    HashNode* current = table[index];
    if (current->key == id) {
      cout << "No duplicate customer ID: ";
      return false;
    }
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new HashNode(id, value);
  }
  return true;
}

//--------------------------------- remove() ----------------------------------
// Removes the customer from the hashtable with the id.
// Returns true if customer is removed, and false otherwise.
// @param id of customer to remove.
// @pre id is within the correct range and customer is in hash table.
// @post customer is inserted in hash table.
bool HashTable::remove(const int &id) {
  if (!(id >= 1000 && id <= 9999)) {
    cout << "Id is not within range" << endl;
    return false;
  }
  int index = hash(id);
  HashNode* prev = nullptr;
  HashNode* current = table[index];

  while (current != nullptr && current->key != id) {
    prev = current;
    current = current->next;
  }
  if (current == nullptr) {
    return false;
  }
  else {
    if (prev == nullptr) {
      table[index] = current->next;
    }
    else {
      prev->next = current->next;
    }
    delete current;
    current = nullptr;
  }
  return true;
}

//--------------------------------- get() -------------------------------------
// Retrieves the customer with id and assigns the customer to value.
// Returns true if the customer is assigned and false otherwise.
// @param id of customer to retrieve.
// @param value customer object to assign.
// @pre id is within the correct range and customer is in table.
// @post customer is assigned to the value.
bool HashTable::get(const int &id, Customer *&value) {
  int index = hash(id);
  HashNode* current = table[index];
  while (current != nullptr) {
    if (current->key == id) {
      value = current->value;
      return true;
    }
    current = current->next;
  }
  return false;
}
