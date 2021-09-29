// ------------------------------------------------ AVLTreeMovie.cpp --------------------------------------------------------
// Created by Henry Park from CSS 343 C 
// Creation Date: 3/12/20
// Date of Last Modification: 3/14/20
// --------------------------------------------------------------------------------------------------------------------
// Purpose - a brief statement of
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions. 
// --------------------------------------------------------------------------------------------------------------------
//

#include "AVLTreeMovie.h"

//------------------------------ AVLTreeMovie --------------------------------
// Contructor for AVLTreeMovie
// @pre NONE
// @post NONE

AVLTreeMovie::AVLTreeMovie()
{
  root = nullptr;
}

//------------------------------ ~AVLTreeMovie --------------------------------
// Destructor for AVLTreeMovie
// @pre NONE
// @post all nodes in the tree will be freed

AVLTreeMovie::~AVLTreeMovie()
{
  emptyHelper(root);
}

//------------------------------ isEmpty --------------------------------
// Check Empty for the tree
// @pre NONE
// @post NONE

bool AVLTreeMovie::isEmpty() const
{
  return root == nullptr;
}


//------------------------------ Insert --------------------------------
// Insert method for the tree.
// @pre Movie should not be null
// @post It will place the m in the tree.

bool AVLTreeMovie::Insert(Movie* m)
{
  bool isInserted = false;
  insertHelper(root, m, isInserted);
  return isInserted;
}

//------------------------------ balanceFactor --------------------------------
// Check balanceFactor of the node and returns the height difference from left and right subtree of the node
// @pre node should not be nullptr
// @post NONE

int AVLTreeMovie::balanceFactor(Node* node) const
{
  return getHeight(node->right) - getHeight(node->left);
}


//------------------------------ insertHelper --------------------------------
// Check balanceFactor of the node and returns the height difference from left and right subtree of the node
// @pre node should not be nullptr
// @post NONE

void AVLTreeMovie::insertHelper(Node*& node, Movie*& data, bool& status)
{
  if (node == nullptr)
  {
    node = new Node();
    node->data = data;
    node->height = 1;
    node->right = nullptr;
    node->left = nullptr;
    status = true;
  } else if (*node->data < *data)
  {
    insertHelper(node->right, data, status);
  } else if (*node->data > *data)
  {
    insertHelper(node->left, data, status);
  } else if (*node->data == *data)
  {
    return ;
  }

  updateHeight(node);
  balance(node);
}

//------------------------------ Display --------------------------------
// Display all the movies in inorder
// @pre NONE
// @post NONE

void AVLTreeMovie::Display() const
{
  inOrder(root);
}

//------------------------------ inOrder --------------------------------
// Helper function for Display to print out the movie in order
// @pre node should not be nullptr
// @post NONE

void AVLTreeMovie::inOrder(Node* node) const
{
  if (node != nullptr)
  {
    if (node->left != nullptr) inOrder(node->left);
    cout << *node->data << endl;
    if (node->right != nullptr) inOrder(node->right);
  }
}

//------------------------------ rightRotation --------------------------------
// Perform rightRotation on the node to balance the tree
// @pre node should not be nullptr
// @post node will be balanced

void AVLTreeMovie::rightRotation(Node*& node)
{
  Node* temp = node->left;
  node->left = temp->right;
  temp->right = node;
  updateHeight(node);
  node = temp;
  updateHeight(temp);
}

//------------------------------ leftRotation --------------------------------
// Perform leftRotation on the node to balance the tree
// @pre node should not be nullptr
// @post node will be balanced

void AVLTreeMovie::leftRotation(Node *&node)
{
  Node* temp = node->right;
  node->right = temp->left;
  temp->left = node;
  updateHeight(node);
  node = temp;
  updateHeight(temp);
}

//------------------------------ getHeight --------------------------------
// Gets a height of the current node
// @pre NONE
// @post NONE

int AVLTreeMovie::getHeight(Node* node) const
{
  if (node != nullptr) return node->height;
  else return 0;
}

//------------------------------ updateHeight --------------------------------
// Recursevely check the height of subtree and then update the node for new height
// @pre NONE
// @post change the height of the node

void AVLTreeMovie::updateHeight(Node*& node)
{
  if (node == nullptr) return ;
  node->height = max(getHeight(node->right), getHeight(node->left)) + 1;
}

//------------------------------ removeHelper --------------------------------
// Helper function for remove
// @pre data can't be nullptr
// @post NONE

void AVLTreeMovie::removeHelper(Node*& node, Movie*& data, bool& status)
{
  if (node == nullptr)
  {
    return ;
  } else if (*node->data == *data)
  {
    if (node->right == nullptr)
    {
      Node* temp = node;
      node = node->left;
      delete temp->data;
      delete temp;
    } else
    {
      findAndDeleteMinNode(node->right, node->data);
    }
    status = true;
  } else if (*node->data < *data)
  {
    removeHelper(node->right, data, status);
  } else if (*node->data > *data)
  {
    removeHelper(node->left, data, status);
  }

  updateHeight(node);
  balance(node);
}

//------------------------------ findAndDeleteMintNode --------------------------------
// Helper function for Remove to find the smallest node from left subtree
// @pre  node should not be nullptr;
// @post delete the current node

void AVLTreeMovie::findAndDeleteMinNode(Node*& node, Movie*& data)
{
  if (node->left == nullptr)
  {
    Node* temp = node;
    node = node->right;
    data = temp->data;
    delete temp->data;
    delete temp;
  } else
  {
    findAndDeleteMinNode(node->left, data);
  }
  updateHeight(node);
  balance(node);
}

//------------------------------ Remove --------------------------------
// A method to remove given the movie in the tree
// @pre m should not be nullptr
// @post removes the given movie if it's found in the tree

bool AVLTreeMovie::Remove(Movie* m)
{
  bool isRemoved = false;
  removeHelper(root, m, isRemoved);
  return isRemoved;
}

//------------------------------ balance --------------------------------
// A method to balance the AVL tree
// @pre node should not be nullptr
// @post balance the tree

void AVLTreeMovie::balance(Node*& node)
{
  if (balanceFactor(node) == 2)
  {
    //If right subtree is left-heavy, then perform right-left rotation.
    if (balanceFactor(node->right) < 0) rightRotation(node->right);
    leftRotation(node);
  }

  if (balanceFactor(node) == -2)
  {
    //If left subtree is right-heavy, then perform left-right rotation.
    if (balanceFactor(node->left) > 0) leftRotation(node->left);
    rightRotation(node);
  }
}

//------------------------------ retrieve --------------------------------
// Search the given movie in the tree, it's found then return the pointer.
// @pre NONE
// @post NONE

bool AVLTreeMovie::retrieve(Movie* m, Movie*& out)
{
  Node *ptr = root;
  while (ptr != nullptr)
  {
    if (*ptr->data == *m)
    {
      out = ptr->data;
      return true;
    }
    if (*ptr->data > *m) ptr = ptr->left;
    else if (*ptr->data < *m) ptr = ptr->right;
  }
  return false;
}

//------------------------------ emptyHelper --------------------------------
// helper function to destructor the tree
// @pre NONE
// @post delete all nodes in the tree

void AVLTreeMovie::emptyHelper(AVLTreeMovie::Node *node)
{
  if (node != nullptr)
  {
    Node* temp_left = node->left;
    Node* temp_right = node->right;
    delete node->data;
    delete node;
    emptyHelper(temp_left);
    emptyHelper(temp_right);
  }
}

//------------------------------ getAlternative --------------------------------
// function to find alternative classic movie if it's found then returns true
// @pre NONE
// @post NONE

bool AVLTreeMovie::getAlternative(const Movie *m) const
{
  bool isThereAlternative = false;
  preOrderHelper(root, isThereAlternative, m);
  return isThereAlternative;
}

//------------------------------ preOrderHelper --------------------------------
// Helper function for search alternative classic movie
// @pre NONE
// @post NONE

void AVLTreeMovie::preOrderHelper(Node* node, bool& status, const Movie* m) const
{
  if (node == nullptr)
  {
    return ;
  }
  const ClassicMovie &cMovie = static_cast<const ClassicMovie &>(*node->data);
  const ClassicMovie *movie = static_cast<const ClassicMovie *>(m);
  if (cMovie.getTitle()==movie->getTitle() && cMovie.getDirectorName()==movie->getDirectorName()
      && cMovie.getStock()!=0 && cMovie.getMajorActor()!=movie->getMajorActor()) {
    cout << *node->data;
    status = true;
    return ;
  }
  preOrderHelper(node->left, status, m);
  preOrderHelper(node->right, status, m);
}
