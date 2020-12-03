/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//doubly_linked_list.h is the header file for, and implementation of, the DoublyLinkedList class.

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "list_node.h"
#include "list_adt.h"

using namespace std;

//DoublyLinkedList is a template class for a standard doubly linked list data structure.
template<class type> class DoublyLinkedList : public ListADT<type>{

public:
  /*Default constructor: DoublyLinkedList
  * Sets the front and back pointers to NULL, and the length to 0.
  */
  DoublyLinkedList();

  /*Destructor: ~DoublyLinkedList
  * Deletes all the nodes contained in the linked list.
  */
  ~DoublyLinkedList();


  /* Member function: Prepend
  * Inserts a new node to the front of the linked list.
  * Parameters:
  * d: a variable of a specified type representing data for the new node to hold.
  */
  void Prepend(type d);

  /* Member function: Append
  * Inserts a new node to the back of the linked list.
  * Parameters:
  * d: a variable of a specified type representing data for the new node to hold.
  */
  void Append(type d);

  /* Member function: InsertAfter
  * Inserts a new node after a specified node.
  * Parameters:
  * new_data: a variable of a specified type representing data for the new node to hold.
  * previous_data: a variable of a specified type representing the data of a node existing in the
  *   linked list.
  */
  void InsertAfter(type new_data, type previous_data);

  /* Member function: RemoveFront
  * Removes the first node in the linked list if it exists.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  type RemoveFront();

  /* Member function: RemoveBack
  * Removes the last node in the linked list if it exists.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  type RemoveBack();

  /* Member function: RemoveKey
  * Removes the first node associated with a given data variable.
  * Parameters:
  * key: a variable of a specified type representing the data of a node to be deleted.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  type RemoveKey(type key);

  /* Member function: RemoveKey
  * Removes the node at a given position.
  * Parameters:
  * pos: an int representing the position of the node to be deleted.
  * Returns:
  * A variable of a specified type representing the data removed from the list.
  */
  type RemovePosition(int pos);

  /* Member function: Search
  * Finds the position of the first node associated with a given data variable.
  * Parameters:
  * key: a variable of a specified type representing the data of a node we are searching for.
  * Returns:
  * An int representing the position of the node we are searching for.
  */
  int Search(type key);

  /* Member function: Print
  * Prints the entire list in it's current order.
  */
  void Print();

  /* Member function: PrintReverse
  * Prints the entire list in reverse order.
  */
  void PrintReverse();

  /* Member function: Sort
  * Sorts the lists items in ascending order.
  */
  void Sort();

  /* Member function: IsEmpty
  * Indicates whether or not the list contains any nodes.
  * Returns:
  * A bool representing whether or not the list contains any nodes.
  */
  bool IsEmpty();

  /* Member functions: GetLength
  * Returns the length of the list.
  * Returns:
  * an unsigned int representing the length of the list.
  */
  unsigned int GetLength();

  /* Member functions: GetNode
  * Returns the first node that contains given variable without removing it from the list.
  * Parameters:
  * key: a variable of a given type representing a node's data
  * Returns:
  * a ListNode of a given type whose data matches the key.
  */
  ListNode<type>* GetNode(type key);

  /* Member function: GetNodeFromPosition
  * Returns the node at a given position without removing it from the list.
  * Parameters:
  * position: an int representing the position of the node to be returned.
  * Returns:
  * a ListNode of a given type who is at the specified position.
  */
  ListNode<type>* GetNodeFromPosition(int position);

  /* Member function: GetDataFromPosition
  * Returns the data of the node at a specified position.
  * Parameters:
  * position: an int representing the position of the node we are looking for.
  * Returns:
  * a variable of a given type representing the data found at a given position.
  */
  type GetDataFromPosition(int position);

private:

  /* Member variable: front
  * A pointer to the first ListNode in the linked list.
  */
  ListNode<type> *front;

  /* Member variable: back
  * A pointer to the last ListNode in the linked list.
  */
  ListNode<type> *back;

  /* Member variable: length
  * An unsigned int representing the number of nodes in the list.
  */
  unsigned int length;

};


template<class type> DoublyLinkedList<type>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  length = 0;
}

template<class type> DoublyLinkedList<type>::~DoublyLinkedList(){
  while(!IsEmpty()){
    RemoveFront();
  }
}

template<class type> void DoublyLinkedList<type>::Prepend(type d){
  ListNode<type> *node = new ListNode<type>(d);
  if (length == 0){                           //if the list is empty
    back = node;                              //the new node is both the front and back
  } else {
    node->next = front;                       //the new node's next is the current front
    front->prev = node;                       //and the current front's previous points to the new node
  }
  front = node;                               //the new node is now the front
  ++length;
}

template<class type> void DoublyLinkedList<type>::Append(type d){
  ListNode<type> *node = new ListNode<type>(d);
  if(length == 0){                            //if the list is empty
    front = node;                             //the new node is the front and the back
  } else {
    back->next = node;                        //the new node's previous is the current back
    node->prev = back;                        //the current back's next is the new node
  }
  back = node;                                //the new node is now the back
  ++length;
}

template<class type> void DoublyLinkedList<type>::InsertAfter(type NewData, type PreviousData){
  ListNode<type> *previous_node = GetNode(PreviousData);  //grabs the node with the data we are searching for so we can update it's pointer's
  ListNode<type> *new_node = new ListNode<type>(NewData);
  if(previous_node != NULL){                              //if we cannot find a node with the data we are searching for we won't make any changes
    if(previous_node == back){                            //if the node we found is the back, we need to update out new node to become the new back
      new_node->prev = previous_node;
      previous_node->next = new_node;
      back = new_node;
    } else {
      new_node->next = previous_node->next;               //the new node's next is set to previous_node's next
      new_node->next->prev = new_node;                    //we set the prev pointer of the node after previous_node to point to the new node
      new_node->prev = previous_node;                     //the new node's prev points to previous_node
      previous_node->next = new_node;                     //and previous_node's next points to the new node
    }
    length++;
  }
}

template<class type> type DoublyLinkedList<type>::RemoveFront(){
  ListNode<type> *node = front;         //retrieve the front so we can update pointers
  type temp;                            //a variable that will hold front's data
  if(!IsEmpty()){                       //we won't make any changes if the list is empty
    if (front->next == NULL){           //if there is only one node in the list
      back = NULL;                      //we set the back pointer to NULL because it is currently pointing to the front
    } else {
      front->next->prev = NULL;         //set the previous pointer of the node after the front to NULL
    }
    front = front->next;                //front now points to the second node in the list
    --length;
    node->next = NULL;                  //all pointers from the old front are now NULL
    temp = node->data;                  //retrieve the old front's data so we can return it

    delete node;
  }
  return temp;
}

template<class type> type DoublyLinkedList<type>::RemoveBack(){
  ListNode<type> *node = back;    //retrieve the back so we can update pointers
  type temp;                      //a variable that will hold the back's data
  if(!IsEmpty()){                 //we won't make any changes if the list is empty
    if(back->prev == NULL){       //if there is only one node in the list
      front = NULL;               //we set the front pointer to NULL because it is currently pointing to the back
    } else {
      back->prev->next = NULL;    //set the next pointer of the node before the back to NULL
    }
    back = back->prev;            //back now points to the second to last node in the list
    --length;
    node->prev = NULL;            //all pointers from the old back are now NULL
    temp = node->data;            //retrieve the old back's data so we can return it
    delete node;
  }
  return temp;
}

template<class type> type DoublyLinkedList<type>::RemoveKey(type key){
  type temp;                              //a variable that will hold the node to remove's data
  if(!IsEmpty()){                         //if the list is empty we won't make any changes
    if(key == front->data){               //if the front's data matches the key
      temp = RemoveFront();               //we already have code for removing the front
    } else if (key == back->data){        //if the back's data matches the key
      temp = RemoveBack();                //we already have code for removing the back
    } else {
      int position = Search(key);         //finds the position of the first node with data that matches the key
      temp = RemovePosition(position);    //RemovePosition removes a node at a given position and returns it's data
    }
  }
  return temp;
}

template<class type> type DoublyLinkedList<type>::RemovePosition(int pos){
  type temp;                              //a variable that will hold the node to remove's data
  if(!IsEmpty()){                         //if the list is empty we won't make any changes
    if(pos >= length){                    //if the given position doesn't exist we won't make any changes
      return temp;
    } else if (pos == 0) {                //if we are removing the front
      temp = RemoveFront();               //we can reuse our RemoveFront code
    } else if (pos == length - 1){        //if we are removing the back
      temp = RemoveBack();                //we can reuse our RemoveBack code
    } else {
      int p = 0;
      ListNode<type> *curr = front;
      while(p != pos){                    //iterate through each node until we reach our desired position
        curr = curr->next;
        p++;
      }
      curr->prev->next = curr->next;      //update the next pointer of the node before curr to point to the node after curr
      curr->next->prev = curr->prev;      //update the prev pointer of the node after curr to point to the node before curr
      curr->next = NULL;                  //set curr's pointers to NULL
      curr->prev = NULL;
      temp = curr->data;                  //retrieve curr's data so we can return it
      length--;
      delete curr;
    }
  }
  return temp;
}

template<class type> int DoublyLinkedList<type>::Search(type key){
  int position = -1;
  ListNode<type> *curr = front;
  while(curr != NULL){            //iterate through every node in the list until we find the desired node
    ++position;
    if(curr->data == key){
      break;
    }
    curr = curr->next;
  }
  if(curr == NULL)                //if we didn't find a node with data that matches the key
    position = -1;                //reset the position to -1 to indicate the node was not found

  return position;
}

template<class type> void DoublyLinkedList<type>::Print(){
  ListNode<type> *curr = front;
  if(IsEmpty()){
    cout << "Empty" << endl;
  } else {
    for(int i = 0; i < length; ++i){
      cout << curr->data << " ";
      curr = curr->next;
    }
  }
  cout << endl;
}

template<class type> void DoublyLinkedList<type>::PrintReverse(){
  ListNode<type> *curr = back;

  while(curr != NULL){
    cout << curr->data << " ";
    curr = curr->prev;
  }
  cout << endl;
}

template<class type> void DoublyLinkedList<type>::Sort(){
  if(IsEmpty() == false && length > 1){              //if the list is empty or only has one node we don't have to do anything
    ListNode<type> *curr = front;
    bool has_shifted = true;                         //the while loop will iterate through the entire list multiple times
    while(has_shifted == true){                      //until it iterates through the list and no changes have been made, i.e. the list is in order
      has_shifted = false;
      ListNode<type> *current_next = curr->next;
      ListNode<type> *current_previous = curr->prev;
      if(length == 2) {                              //if there are only two nodes in the list
        if(front->data > back->data){                //check if it's not already in ascending order
          ListNode<type> *temp = curr->next;         //curr is the front and temp is the back, but we want the opposite
          back = curr;
          front = temp;
          curr->next = NULL;                         //update curr's prev to be the front and it's next to NULL
          curr->prev = temp;
          temp->next = curr;                         //update temp's next to curr and it's prev to NULL
          temp->prev = NULL;
        }
      } else {
        for(int i = 0; i < length - 1; ++i) {
          curr = GetNodeFromPosition(i);             //evaluates each node in the list
          if(curr->prev != NULL)                     //if curr isn't the front we want to access the node before it
            current_previous = curr->prev;
          current_next = curr->next;

          if(curr->data > current_next->data){       //if we need to swap the position of curr and it's successor
            if(curr->prev == NULL){                  //if curr is front
              curr->next = current_next->next;       //curr's next now points to the node after current_next
              current_next->next->prev = curr;       //the previous pointer of the node after current_next now points to curr
              curr->prev = current_next;
              current_next->next = curr;
              current_next->prev = NULL;
              front = current_next;                  //current_next is now the front
            } else if (current_next->next == NULL) { //if curr will become back
              current_next->next = curr;
              current_next->prev = curr->prev;       //current_next's prev points to the node before curr
              curr->prev->next = current_next;       //the next pointer of the node before curr points to current_next
              curr->next = NULL;
              curr->prev = current_next;
              back = curr;                           //curr is now the back
            } else {                                 //if curr is a node somewhere in the middle of the list
              current_previous->next = current_next;
              current_next->prev = current_previous;
              curr->next = current_next->next;       //curr's next points to the node after current_next
              current_next->next->prev = curr;       //the prev pointer of the node after current_next points to curr
              current_next->next = curr;
              curr->prev = current_next;
            }
            has_shifted = true;                      //indicates that changes have been made, and we need to iterate through the list again
          }
        }
      }
    }
  }
}


template<class type> bool DoublyLinkedList<type>::IsEmpty(){
  if(length == 0){
    return true;
  } else {
    return false;
  }
}

template<class type> unsigned int DoublyLinkedList<type>::GetLength(){
  return length;
}

template<class type> ListNode<type>* DoublyLinkedList<type>::GetNode(type key){
  int position = Search(key);          //find the position of the node we are looking for
  ListNode<type> *curr = front;
  if(position == -1){                  //if the node doesn't exist we don't need to continue
    return NULL;
  } else {
    int p = 0;
    while(p != position){
      curr = curr->next;
      p++;
    }
  }
  return curr;
}

template<class type> ListNode<type>* DoublyLinkedList<type>::GetNodeFromPosition(int position){
  int p = 0;
  ListNode<type> *curr = front;
  if(position >= length || position < 0){    //if the position is invalid we don't need to continue
    return NULL;
  } else {
    while(p != position){
      curr = curr->next;
      p++;
    }
  }
  return curr;
}

template<class type> type DoublyLinkedList<type>::GetDataFromPosition(int position){
  ListNode<type> *node = GetNodeFromPosition(position);
  return node->data;
}

#endif
