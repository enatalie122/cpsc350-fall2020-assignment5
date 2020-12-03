/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//list_node.h is the header file for, and implementation of, the ListNode class

#ifndef LIST_NODE
#define LIST_NODE

#include <iostream>
using namespace std;

//The ListNode class is a template class for nodes in a doubly linked list.
template <class type> class ListNode{

public:
  /*Default constructor: ListNode
  * Sets the node's data and pointers to NULL.
  */
  ListNode();

  /*Overloaded constructor: ListNode
  * Sets the node's data to a given value, and sets pointers to NULL.
  * Parameters:
  * d: a variable of a specified type representing data for the node to hold.
  */
  ListNode(type d);

  /*Destructor: ~ListNode
  * Deletes next and prev pointers.
  */
  ~ListNode();

  /*Member Variable: data
  * A variable of a given type that is stored in the node.
  */
  type data;

  /*Member Variable: *next
  * A pointer to a ListNode that represts the node's successor in a doubly linked list.
  */
  ListNode *next;

  /*Member Variable: *prev
  * A pointer to a ListNode that represts the node's predecessor in a doubly linked list.
  */
  ListNode *prev;
};

template<class type> ListNode<type>::ListNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}

template<class type> ListNode<type>::ListNode(type d){
  data = d;
  next = NULL;
  prev = NULL;
}

template<class type> ListNode<type>::~ListNode(){
  delete next;
  delete prev;
}
#endif
