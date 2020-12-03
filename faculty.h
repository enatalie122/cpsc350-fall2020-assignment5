/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//faculty.h is the header file for the Faculty class

#ifndef FACULTY
#define FACULTY

#include "university_affiliate.h"
#include "doubly_linked_list.h"

//The Faculty class descends from the UniversityAffiliate base class and holds data representing a University faculty member
class Faculty : public UniversityAffiliate{
public:
  /*Default Constructor: Faculty
  * Instantiates an empty DoublyLinkedList of ints
  */
  Faculty();

  //Destructor: ~Faculty
  ~Faculty();

  /*Member Function AddAdvisee
  * Adds a new advisee to the Faculty's list of advisees
  * Parameters:
  * advisee_id: an int representing the id of the advisee
  */
  void AddAdvisee(int advisee_id);

  /*Member Function RemoveAdvisee
  * Removes an advisee to the Faculty's list of advisees
  * Parameters:
  * advisee_id: an int representing the id of the advisee
  */
  void RemoveAdvisee(int advisee_id);

  /*Accessor Method: get_advisees
  * Returns: a pointer to a DoublyLinkedList of ints representing the faculty member's advisees
  */
  DoublyLinkedList<int>* get_advisees();

  /* Operator Overloader: operator<<
  * Overloads the << operator so the faculty object can be printed with the cout object.
  * Parameters:
  * os: a reference to an ostream object
  * for: a reference to a faculty object
  * Returns:
  * A reference to the os ostream object.
  */
  friend ostream& operator<<(ostream& os, const Faculty& f);

private:
  /*Member Variable: *advisees_
  * A pointer to a DoublyLinkedList of ints representing the faculty member's advisees 
  */
  DoublyLinkedList<int> *advisees_;

};
#endif
