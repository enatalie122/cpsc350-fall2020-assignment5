/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//list_adt.h is the header file for the ListADT interface.

#ifndef LIST_ADT
#define LIST_ADT

using namespace std;

//ListADT is an interface for list data structures.
template <class type> class ListADT{

public:

  /* Member function: Prepend
  * Inserts a new node to the front of the list.
  * Parameters:
  * d: a variable of a specified type representing data for the new node to hold.
  */
  virtual void Prepend(type d) = 0;

  /* Member function: Append
  * Inserts a new node to the back of the list.
  * Parameters:
  * d: a variable of a specified type representing data for the new node to hold.
  */
  virtual void Append(type d) = 0;

  /* Member function: InsertAfter
  * Inserts a new node after a specified node.
  * Parameters:
  * new_data: a variable of a specified type representing data for the new node to hold.
  * previous_data: a variable of a specified type representing the data of a node existing in the list.
  */
  virtual void InsertAfter(type new_data, type previous_data) = 0;

  /* Member function: RemoveFront
  * Removes the first node in the list if it exists.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  virtual type RemoveFront() = 0;

  /* Member function: RemoveBack
  * Removes the last node in the list if it exists.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  virtual type RemoveBack() = 0;

  /* Member function: RemoveKey
  * Removes the first node associated with a given data variable.
  * Parameters:
  * key: a variable of a specified type representing the data of a node to be deleted.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  virtual type RemoveKey(type key) = 0;

  /* Member function: RemoveKey
  * Removes the node at a given position.
  * Parameters:
  * pos: an int representing the position of the node to be deleted.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  virtual type RemovePosition(int position) = 0;

  /* Member function: Search
  * Finds the position of the first node associated with a given data variable.
  * Parameters:
  * key: a variable of a specified type representing the data of a node we are searching for.
  * Returns:
  * An int representing the position of the node we are searching for.
  */
  virtual int Search(type key) = 0;

  /* Member function: Print
  * Prints the entire list in it's current order.
  */
  virtual void Print() = 0;

  /* Member function: PrintReverse
  * Prints the entire list in reverse order.
  */
  virtual void PrintReverse() = 0;

  /* Member function: Sort
  * Sorts the lists items in ascending order.
  */
  virtual void Sort() = 0;

  /* Member function: IsEmpty
  * Indicates whether or not the list contains any nodes.
  * Returns:
  * A bool representing whether or not the list contains any nodes.
  */
  virtual bool IsEmpty() = 0;

  /* Member functions: GetLength
  * Returns the length of the list.
  * Returns:
  * an unsigned int representing the length of the list.
  */
  virtual unsigned int GetLength() = 0;

};
#endif
