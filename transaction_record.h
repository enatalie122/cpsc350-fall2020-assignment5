/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//transaction_record.h is the header file for the TransactionRecord class

#ifndef TRANSACTION_RECORD
#define TRANSACTION_RECORD

#include "student.h"
#include "faculty.h"
#include "doubly_linked_list.h"
using namespace std;

//The TransactionRecord class tracks when an affiliate is added or removed from the database
class TransactionRecord{
public:
  /*Deafult Constructor: TransactionRecord
  * Sets the transaction_type_ and advisor to -1, instantiates an empty DoublyLinkedList of ints, and creates
  * new student and faculty objects
  */
  TransactionRecord();

  /*Overloaded Constructor: TransactionRecord
  * Parameters:
  * transaction_type: an int representing what type of transaction is being recorded
  * *s: a pointer to a Student object that was added or removed from the database
  */
  TransactionRecord(int transaction_type, Student *s);

  /*Overloaded Constructor: TransactionRecord
  * Parameters:
  * transaction_type: an int representing what type of transaction is being recorded
  * *s: a pointer to a Student object that was added or removed from the database
  * advisor: an int representing the student's advisor
  */
  TransactionRecord(int transaction_type, Student *s, int advisor);

  /*Overloaded Constructor: TransactionRecord
  * Parameters:
  * transaction_type: an int representing what type of transaction is being recorded
  * *f: a pointer to a Faculty object that was added or removed from the database
  */
  TransactionRecord(int transaction_type, Faculty *f);

  /*Overloaded Constructor: TransactionRecord
  * Parameters:
  * transaction_type: an int representing what type of transaction is being recorded
  * *f: a pointer to a Faculty object that was added or removed from the database
  * *advisees: a pointer to a DoublyLinkedList of ints representing the faculty member's advisees
  */
  TransactionRecord(int transaction_type, Faculty *f, DoublyLinkedList<int> *advisees);

  /*Destructor: ~TransactionRecord
  * Deletes student and faculty objects
  */
  ~TransactionRecord();

  /*Accessor Method: get_transaction_type
  * Returns: an int representing what type of transaction was recorded
  */
  int get_transaction_type();

  /*Accessor Method: get_student
  * Returns: a pointer to a student that was added or deleted from the database
  */
  Student* get_student();

  /*Accessor Method: get_faculty
  * Returns: a pointer to a faculty object that was added or removed from the databse
  */
  Faculty* get_faculty();

  /*Accessor Method: get_advisees
  * Returns: a pointer to a DoublyLinkedList of ints representing a faculty member's advisees
  */
  DoublyLinkedList<int>* get_advisees();

  /*Accessor Method: get_advisor
  * Returns: an int representing a student's advisor id
  */
  int get_advisor();

private:
  /*Member Variable: transaction_type_
  * An int representing what type of transaction was recorded (ex: student was added, student was deleted, etc.)
  */
  int transaction_type_;

  /*Member Variable: advisor_
  * an int representing a student's advisor id
  */
  int advisor_;

  /*Member Variable: *advisees_
  * a pointer to a DoublyLinkedList of ints representing a faculty member's advisees
  */
  DoublyLinkedList<int> *advisees_;

  /*Member Variable: *student_
  * a pointer to a student that was added or deleted from the database
  */
  Student *student_;

  /*Member Variable: *faculty_
  * a pointer to a faculty object that was added or removed from the databse 
  */
  Faculty *faculty_;

};
#endif
