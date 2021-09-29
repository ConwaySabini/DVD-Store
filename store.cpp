// ------------------------------------------------ store.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Implementation for Store
// --------------------------------------------------------------------------------------------------------------------

#include "store.h"
Store::Store() {

}

//------------------------------ addMovies() ----------------------------------
// Opens the file given from the string reads from the file to add movies to
//      any one of the three movie trees, one for each genre.
// @param fileName is the name of the file to open.
// @pre File is in directory and formatted.
// @post movies are created and inserted into the three trees.
void Store::addMovies(string fileName) {
  ifstream file;
  file.open(fileName);
  if (!file.is_open())
  {
    cout << "File could not be opened" << endl;
    file.close();
    return ;
  }
  string line;
  movieFactory factory;
  while (getline(file, line))
  {
    stringstream input(line);
    char type = line[0];
    if (type == 'F')
    {
      Movie* comedy = factory.processMovie(input);
      if (comedy == nullptr)
      {
        cout << input.str() << endl;
        continue;
      }
      Movie* foundMovie = nullptr;
      if (comedies.retrieve(comedy, foundMovie))
      {
        int stock = comedy->getStock();
        int existing = foundMovie->getStock();
        foundMovie->setStock(stock + existing);
        continue;
      }
      comedies.Insert(comedy);
    }
    else if (type == 'C')
    {
      Movie* classic = factory.processMovie(input);
      if (classic == nullptr)
      {
        cout << input.str() << endl;
        continue;
      }
      Movie* foundMovie = nullptr;
      if (classics.retrieve(classic, foundMovie))
      {
        int stock = classic->getStock();
        int existing = foundMovie->getStock();
        foundMovie->setStock(stock + existing);
        continue;
      }
      classics.Insert(classic);
    }
    else if (type == 'D')
    {
      Movie* drama = factory.processMovie(input);
      if (drama == nullptr)
      {
        cout << input.str() << endl;
        continue;
      }
      Movie* foundMovie = nullptr;
      if (dramas.retrieve(drama, foundMovie))
      {
        int stock = drama->getStock();
        int existing = foundMovie->getStock();
        foundMovie->setStock(stock + existing);
        continue;
      }
      dramas.Insert(drama);
    }
    else cout << "Invalid movie input: " << input.str() << endl;
  }
  file.close();
}

//----------------------------- addCustomers() --------------------------------
// Opens the file given from the string reads from the file to add customers to
//      the hash table database.
// @param fileName is the name of the file to open.
// @pre File is in directory and formatted.
// @post customers are created and inserted in the hashtable.
void Store::addCustomers(string fileName) {
  ifstream file;
  file.open(fileName);
  if (!file.is_open())
  {
    cout << "file could not be opened" << endl;
    file.close();
    return ;
  }
  string line;
  while (getline(file, line))
  {
    int id = 0;
    string fName = "";
    string lName = "";
    istringstream token(line);
    token >> id >> fName >> lName;
    Customer* cstr = new Customer();
    if(!cstr->setID(id))
    {
      delete cstr;
      cout << line << endl;
    }
    cstr->setfName(fName);
    cstr->setlName(lName);
    if(!customers.put(id, cstr))
    {
      delete cstr;
      cout << line << endl;
    }
  }
  file.close();
}

//---------------------------- addTransactions() ------------------------------
// Opens the file given from the string reads from the file to create and add
//      transactions to the queue to be processed. Returns true if the file is
//         opened and transactions are added and false otherwise.
// @param fileName is the name of the file to open.
// @pre File is in directory and formatted.
// @post transactions are created and stored in the queue.
void Store::addTransactions(string fileName) {
  ifstream file;
  file.open(fileName);
  if (!file.is_open())
  {
    cout << "file could not be opened" << endl;
    file.close();
    return ;
  }
  string line;
  while (getline(file, line))
  {
    stringstream input(line);
    char type;
    type = input.get();
    if (type == 'I') {
      Transaction* inv = new Inventory();
      inv->setType('I');
      commands.push(inv);
    }
    else if (type == 'H') {
      input.get(); // skip the white space
      getline(input, line); // parse the customer id
      int id;
      id = stoi(line); // convert id in string form to int
      History* hist = new History();
      hist->setType('H');
      if(!hist->setID(id))
      {
        delete hist;
        cout << "Customer ID is not in range: " << id << endl;
        continue;
      }
      commands.push(hist);
    }
    else if (type == 'B') {
      input.ignore(); // skip white space
      addBorrow(input);
    }
    else if (type == 'R') {
      input.ignore(); // skip white space
      addReturn(input);
    }
    else cout << "Invalid transaction type: " << input.str() << endl;
  }
  file.close();
}

//------------------------------ processTrans() -------------------------------
// Process each transaction in the queue and make changes accordingly to the
//      movie trees and customer databases.
// @pre Transactions are in the queue and are valid.
// @post Queue is emptied. Errors are printed to cout as well as any history or
//          inventory, or other transactions requested.
void Store::processTrans() {
  while (!commands.empty()) {
    Transaction *curr;
    curr = commands.front();
    char type = curr->getType();
    if (type=='B') {
      Customer *client;
      if (!customers.get(curr->getID(), client)) {
        cout << "Customer not found: " << curr->getID() << endl;
        commands.pop();
        continue;
      };
      Movie *movie = curr->getMovie();
      char movieType = movie->getType();
      Movie *foundMovie = nullptr;
      if (movieType=='D') {
        if (!dramas.retrieve(movie, foundMovie)) {
          cout << "Movie was not found: " << curr->getRecord() << endl;
          commands.pop();
          continue; // continue the transaction
        } else {
          int amount = foundMovie->getStock();
          if (amount==0) {
            cout << "Not enough Movie to borrow: " << *foundMovie << endl;
            commands.pop();
            continue;
          } else {
            amount--;
            foundMovie->setStock(amount);
            client->addMovie(movie);
            client->addTrans(curr->getRecord());
          }
        }
      } else if (movieType=='F') {
        if (!comedies.retrieve(movie, foundMovie)) {
          cout << "Movie was not found: " << curr->getRecord() << endl;
          commands.pop();
          continue; // continue the transaction
        } else {
          int amount = foundMovie->getStock();
          if (amount==0) {
            cout << "Not enough Movie to borrow: " << *foundMovie << endl;
            commands.pop();
            continue;
          } else {
            amount--;
            foundMovie->setStock(amount);
            client->addMovie(movie);
            client->addTrans(curr->getRecord());
          }
        }
      } else if (movieType=='C') {
        if (!classics.retrieve(movie, foundMovie)) {
          cout << "Movie was not found: " << curr->getRecord() << endl;
          commands.pop();
          continue; // continue the transaction
        } else {
          int amount = foundMovie->getStock();
          if (amount==0) {
            cout << "Not enough Movie to borrow: " << *foundMovie << endl;
            if (classics.getAlternative(foundMovie))
            {
              cout << " <- you can try to rent this movie instead" << endl;
            }
            commands.pop();
            continue;
          } else {
            amount--;
            foundMovie->setStock(amount);
            client->addMovie(movie);
            client->addTrans(curr->getRecord());
          }
        }
      }
    } else if (curr->getType()=='R') {
      Customer *client;
      if (!customers.get(curr->getID(), client)) {
        cout << "Customer not found: " << curr->getID() << endl;
        commands.pop();
        continue;
      }
      Movie *movie = curr->getMovie();
      char movieType = movie->getType();
      Movie *foundMovie = nullptr;
      if (movieType=='D') {
        if (!dramas.retrieve(movie, foundMovie)) {
          cout << "Movie was not found: " << curr->getRecord() << endl;
          commands.pop();
          continue; // continue the transaction
        } else {
          int amount = foundMovie->getStock();
          {
            if (client->returnMovie(movie)) {
              amount++;
              foundMovie->setStock(amount);
              client->addTrans(curr->getRecord());
            } else {
              cout << "You haven't rented this movie yet: " << curr->getRecord() << endl;
              commands.pop();
              continue;
            }
          }
        }
      } else if (movieType=='F') {
        if (!comedies.retrieve(movie, foundMovie)) {
          cout << "Movie was not found: " << curr->getRecord() << endl;
          commands.pop();
          continue; // continue the transaction
        } else {
          int amount = foundMovie->getStock();
          {
            if (client->returnMovie(movie)) {
              amount++;
              foundMovie->setStock(amount);
              client->addTrans(curr->getRecord());
            } else {
              cout << "You haven't rented this movie yet: " << curr->getRecord() << endl;
              commands.pop();
              continue;
            }
          }
        }
      } else if (movieType=='C') {
        if (!classics.retrieve(movie, foundMovie)) {
          cout << "Movie was not found: " << curr->getRecord() << endl;
          commands.pop();
          continue; // continue the transaction
        } else {
          int amount = foundMovie->getStock();
          {
            if (client->returnMovie(movie)) {
              amount++;
              foundMovie->setStock(amount);
              client->addTrans(curr->getRecord());
            } else {
              cout << "You haven't rented this movie yet: " << curr->getRecord() << endl;
              commands.pop();
              continue;
            }
          }
        }
      }
    } else if (curr->getType()=='H') {
        int id = curr->getID();
        Customer *person;
        if (!customers.get(id, person)) {
          cout << "Customer not found: " << id << endl;
          commands.pop();
          continue;
        }
        person->printHistory();
      } else if (curr->getType()=='I') {
        const Inventory *inventory = static_cast< const Inventory *>(curr);
        inventory->printInventory(comedies, "Commedy");
        inventory->printInventory(dramas, "Drama");
        inventory->printInventory(classics, "Classic");
      }
      commands.pop();
    }
  }

//------------------------------- addReturn() ---------------------------------
// Add a return transaction to the queue by reading the information from the
//      file and creating the return object.
// @pre file input is valid.
// @post return transaction is created and added to the queue.
//     The file input will move to the next line. Errors are printed to cout.
void Store::addReturn(stringstream &input) {
  string readInput;
  int id = 0;
  char mediaType = ' ';
  Return* ret = new Return();
  ret->setType('R');
  getline(input, readInput, ' ');
  id = stoi(readInput);
  if (!ret->setID(id)) {
    delete ret;
    cout << "Customer ID is not in the range between 1000 and 9999: " << id << endl;
    return;
  }
  getline(input, readInput, ' ');
  mediaType = readInput[0];
  if (!ret->setMediaType(mediaType))
  {
    delete ret;
    cout << input.str() << endl;
    return ;
  }
  Movie* movie = nullptr;
  movieFactory factory;
  movie = factory.processTransMovie(input);
  if (movie == nullptr) // error
  {
    delete ret;
    cout << input.str() << endl;
    return ;
  }
  ret->setMovie(movie);
  ret->setRecord(input.str());
  commands.push(ret);
}

//------------------------------- addBorrow() ---------------------------------
// Add a borrow transaction to the queue by reading the information from the
//      file and creating the borrow object.
// @pre file input is valid.
// @post borrow transaction is created and added to the queue.
//      The file input will move to the next line. Errors are printed to cout.
void Store::addBorrow(stringstream &input) {
  string readInput;
  int id = 0;
  char mediaType = ' ';
  Borrow* borrow = new Borrow();
  borrow->setType('B');
  getline(input, readInput, ' ');
  id = stoi(readInput);
  getline(input, readInput, ' ');
  mediaType = readInput[0];
  if (!borrow->setMediaType(mediaType))
  {
    delete borrow;
    cout << input.str() << endl;
    return ;
  }
  if (!borrow->setID(id))
  {
    delete borrow;
    cout << "Customer ID is not in the range between 1000 and 9999: " << id << endl;
    return ;
  }
  movieFactory factory;
  Movie* movie = factory.processTransMovie(input);
  if (movie == nullptr) // error
  {
    delete borrow;
    cout << input.str() << endl;
    return ;
  }
  borrow->setMovie(movie);
  borrow->setRecord(input.str());
  commands.push(borrow);
}
