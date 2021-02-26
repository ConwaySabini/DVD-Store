// ------------------------------------------------ AVLTreeMovie.h --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Interface of AVLTreeMoive . Storing the movie for customer and store
// -------------------------------------------------------------------------------------------------------------------- 


#include "movie.h"
#include "classicMovie.h"
#ifndef CSS343_PROGRAM4__AVLTREEMOVIE_H_
#define CSS343_PROGRAM4__AVLTREEMOVIE_H_

class AVLTreeMovie {
 public:
  AVLTreeMovie();
  ~AVLTreeMovie();

  bool Insert(Movie* m);
  bool Remove(Movie* m);
  bool retrieve(Movie* m, Movie*& out);
  void Display() const; // inorder traversal
  bool isEmpty() const;
  bool getAlternative(const Movie* m) const; // this is for classical movie only

 private:
  struct Node
  {
    Node* left;
    Node* right;
    Movie* data;
    int height;
  };
  Node *root;

  int balanceFactor(Node* node) const;
  void insertHelper(Node*& node, Movie*& data, bool& status);
  void rightRotation(Node*& node);
  void leftRotation(Node*& node);
  void inOrder(Node* node) const;
  int getHeight(Node* node) const;
  void updateHeight(Node*& node);
  void removeHelper(Node*& node, Movie*& data, bool& status);
  void findAndDeleteMinNode(Node*& node, Movie*& data);
  void balance(Node*& node);
  void emptyHelper(Node* node);
  void preOrderHelper(Node* node, bool& status, const Movie* m) const;
};

#endif //CSS343_PROGRAM4__AVLTREEMOVIE_H_
