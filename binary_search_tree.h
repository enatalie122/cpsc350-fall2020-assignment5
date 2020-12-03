/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//binary_search_tree.h is the header file for, and implementation of, the BinarySearchTree class

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "tree_node.h"

//The BinarySearchTree class is a template class for a basic binary search tree.
template <class type> class BinarySearchTree{

public:
  /*Default constructor: BinarySearchTree
  * Sets the root to null and the size to 0.
  */
  BinarySearchTree();

  /*Destructor: ~BinarySearchTree
  * Deletes every node in the tree.
  */
  ~BinarySearchTree();

  /*Member Function: InsertNode
  * Inserts a new node with given data into the tree at the proper location.
  * Parameters:
  * d: a variable of a given type representing the data to be inserted into the tree.
  */
  void InsertNode(type d);

  /*Member Function: SearchNode
  * Returns: a boolean representing whether or not a piece of data is currently in the tree
  * Parameters:
  * d: a variable of a given type representing the data to be found into the tree.
  */
  bool SearchNode(type d);

  /*Member Function: DeleteNode
  * Searches for, and deletes a node with a given piece of data
  * Returns: a boolean representing whether or not the data is in the tree and has been deleted
  * Parameters:
  * d: a variable of a given type representing the data to be deleted from the tree.
  */
  bool DeleteNode(type d);

  /*Member Function: AccessNode
  * Returns: a pointer to the data stored in the tree that the user is searching for
  * Parameters:
  * d: a variable of a given type representing the data to be found into the tree.
  */
  type* AccessNode(type d);

  /*Member Function: IsEmpty
  * Returns: a boolean representing whether or not there are any nodes in the tree
  */
  bool IsEmpty();

  /*Member Function: GetSize
  * Returns: an unsigned int representing how many nodes are currently in the tree
  */
  unsigned int GetSize();

  /*Member Function: GetMin
  * Returns: a pointer to a piece of data of a given type that represents the smallest value stored in the tree
  */
  type* GetMin();

  /*Member Function: GetMax
  * Returns: a pointer to a piece of data of a given type that represents the largest value stored in the tree
  */
  type* GetMax();

  /*Member Function: GetRoot
  * Returns: a pointer to the piece of data of a given type at the root of the tree
  */
  type* GetRoot();

  /*Member Function: RecursivePrint
  * Prints out the all the data in the tree from a given starting point
  * Parameters:
  * *node: a pointer to a node that represents the desired starting point
  */
  void RecursivePrint(TreeNode<type> *node);

  /*Member Function: PrintEntireTree
  * Prints all the data in the tree in ascending order
  */
  void PrintEntireTree(); 

private:
  /*Helper Function: GetSuccessor
  * Helps with the DeleteNode member function by finding a given node's successor
  * Returns: a pointer to a node representing a node's successor.
  * Parameters:
  * d: a pointer to a node representing the node to be deleted
  */
  TreeNode<type>* GetSuccessor(TreeNode<type> *d);

  /*Member Variable: *root
  * A pointer to the root of the tree
  */
  TreeNode<type> *root;

  /*Member Variable: size
  * An unsigned int representing the size of the tree
  */
  unsigned int size;

};

template<class type> BinarySearchTree<type>::BinarySearchTree(){
  root = NULL;
  size = 0;
}

template<class type> BinarySearchTree<type>::~BinarySearchTree(){
  while(size > 0){
    DeleteNode(root->data);
  }
}

template<class type> type* BinarySearchTree<type>::AccessNode(type d){
  TreeNode<type> *curr = root;
  while(curr->data != d){   //while current's data does not match the data we are looking for
    if (d < curr->data)     //if the data we are searching for is less than current's data
      curr = curr->left;    //check current's left child
    else                    //if the data we are searching for is greater than current's data
      curr = curr->right;   //check current's right child
  }
  type *data = &curr->data;//a pointer to the data we wish to access
  return data;
}


template<class type> void BinarySearchTree<type>::InsertNode(type d){
  TreeNode<type> *node = new TreeNode<type>(d);
  size++;

  if(IsEmpty()){
    root = node;
  } else {                              //tree is not empty
    TreeNode<type> *current = root;
    TreeNode<type> *parent = NULL;

    while(true){
      parent = current;

      if(d < current->data){            //if d is less than current's data, move to the left child
        current = current->left;
        if(current == NULL){            //found insertion point
          parent->left = node;
          break;
        }
      } else {                          //if d is greater than current's data, move to the right child
        current = current->right;

        if(current == NULL){            //found insertion point
          parent->right = node;
          break;
        }
      }
    }
  }
}

template<class type> bool BinarySearchTree<type>::SearchNode(type d){
  if(IsEmpty())
    return false;
  else{                               //the tree is not empty
    TreeNode<type> *curr = root;
    while(curr->data != d){           //while current's data does not match the data we are looking for
      if(d < curr->data)              //if the data we are searching for is less than current's data
        curr = curr->left;            //check current's left child
      else                            //if the data we are searching for is greater than current's data
        curr = curr->right;           //check current's right child
      if(curr == NULL)                //we could not find the data we are searching for
        return false;
    }
  }
  return true;
}

template<class type> bool BinarySearchTree<type>::DeleteNode(type d){
  if(IsEmpty())
    return false;

  TreeNode<type> *curr = root;
  TreeNode<type> *parent = root;
  bool isLeftNode = true;

  //usual code to find a node
  while(curr->data != d){
    parent = curr;

    if(d < curr->data){
      //go left
      isLeftNode = true;
      curr = curr->left;
    } else {
      //go right
      isLeftNode = false;
      curr = curr->right;
    }
    if(curr == NULL){
      return false;
    }
  }
  //if we make it this far, we found our key/value
  //we can proceed to delete
  size--;
  //case: node to be deleted has no children, AKA leaf node
  if(curr->left == NULL && curr->right ==NULL){
    if(curr == root){
      root = NULL;
    } else if(isLeftNode){
      parent->left = NULL;
    } else {
      //right child
      parent->right = NULL;
    }
  }
  //case: node to be deleted has one child. Need to determine whether node has left or right child
  else if(curr->right == NULL){
    //node has one child and it's a left child
    if(curr == root){
      root = curr->left;
    } else if(isLeftNode){
      parent->left = curr->left;
    } else {
      parent->right = curr->left;
    }
  }
  else if(curr->left == NULL){
    //node has one child and it's a right child
    if(curr == root){
      root = curr->right;
    } else if(isLeftNode){
      parent->left = curr->right;
    } else {
      parent->right = curr->right;
    }
  }
  else {
    //node to be deleted has two children
    TreeNode<type> *successor = GetSuccessor(curr);

    if(curr == root){
      root = successor;
    }
    else if(isLeftNode){
      parent->left = successor;
    } else {
      parent->right = successor;
    }
    successor->left = curr->left;
  }
  return true;
}


template<class type> bool BinarySearchTree<type>::IsEmpty(){
  if(root == NULL){
    return true;
  }
  return false;
}

template<class type> unsigned int BinarySearchTree<type>::GetSize(){
  return size;
}

template<class type> type* BinarySearchTree<type>::GetRoot(){
  type *data = &root->data;
  return data;
}

template<class type> type* BinarySearchTree<type>::GetMin(){
  TreeNode<type> *current = root;
  if(IsEmpty())
    return NULL;
  while(current->left != NULL){     //returns node that's the furthest to the left
    current = current->left;
  }
  type *data = &current->data;
  return data;
}

template<class type> type* BinarySearchTree<type>::GetMax(){
  TreeNode<type> *current = root;
  if(IsEmpty())
    return NULL;
  while(current->right != NULL){   //returns node that's the furthest to the right
    current = current->right;
  }
  type *data = &current->data;
  return data;
}

template<class type> void BinarySearchTree<type>::RecursivePrint(TreeNode<type> *node){
  if (node != NULL){
    RecursivePrint(node->left);
    cout << node->data << endl;
    RecursivePrint(node->right);
  }
}

template<class type> void BinarySearchTree<type>::PrintEntireTree(){
  RecursivePrint(root);
}


template<class type> TreeNode<type>* BinarySearchTree<type>::GetSuccessor(TreeNode<type> *d){
  TreeNode<type> *sp = d;
  TreeNode<type> *successor = d;
  TreeNode<type> *current = d->right;

  while(current != NULL){
    sp = successor;     //successor parent
    successor = current;
    current = current->left;
  }
  //once we exit the while loop, pointers should be in the correct positions
  //we need to check whether or not successor is descendent of right child
  if(successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

#endif
