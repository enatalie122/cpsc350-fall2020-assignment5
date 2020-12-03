/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//tree_node.h is the header file for, and implementation of, the TreeNode class

#ifndef TREENODE
#define TREENODE

#include <iostream>
using namespace std;

//The TreeNode class is a template class for nodes in a BST.
template <class type> class TreeNode{

public:
  /*Default Constructor: TreeNode
  * Set's the node's data and pointers to NULL.
  */
  TreeNode();

  /*Overloaded constructor: TreeNode
  * Sets the node's data to a given value, and sets pointers to NULL.
  * Parameters:
  * d: a variable of a specified type representing data for the node to hold.
  */
  TreeNode(type d);

  /*Destructor: ~TreeNode
  * Deletes left and right pointers.
  */
  ~TreeNode();

  /*Member Variable: data
  * A variable of a given type that is stored in the node.
  */
  type data;

  /*Member variable: *left
  * A pointer to a TreeNode the represts the node's left child in a BST.
  */
  TreeNode *left;

  /*Member variable: *right
  * A pointer to a TreeNode the represts the node's right child in a BST.
  */
  TreeNode *right;

};

template<class type> TreeNode<type>::TreeNode(){
  data = NULL;
  left = NULL;
  right = NULL;
}

template<class type> TreeNode<type>::TreeNode(type d){
  data = d;
  left = NULL;
  right = NULL;
}

template<class type> TreeNode<type>::~TreeNode(){
  delete left;
  delete right;
}
#endif
