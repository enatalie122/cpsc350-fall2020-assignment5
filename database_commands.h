/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//database_commands.h is the header file for the DatabaseCommands class

#ifndef DATABASE_COMMANDS
#define DATABASE_COMMANDS

#include "doubly_linked_list.h"
#include "binary_search_tree.h"
#include "transaction_record.h"
#include "student.h"
#include "gen_stack.h"
#include "faculty.h"
#include "errors.h"
#include "file.h"
#include <iostream>
#include <string>
using namespace std;

//The DatabaseCommands class carries out all the commands in the database of university affiliates
class DatabaseCommands{
public:
  /*Default constructor: DatabaseCommands
  * Instantiates empty BSTs for student's and faculty, an empty stack of TransactionRecords, an Errors object,
  * a File object, and sets the transaction_count_ to 5.
  */
  DatabaseCommands();

  /*Overloaded constructor: DatabaseCommands
  * Populates the student and faculty BSTs with data stored from a file. Instantiates an empty stack of TransactionRecords, an
  * Errors object, a File object, and sets the transaction_count_ to 5.
  * Parameters:
  * *student_data: a pointer to a DoublyLinkedList of strings representing all of the stored data for student objects
  * *faculty_data: a pointer to a DoublyLinkedList of strings representing all of the stored data for faculty objects
  */
  DatabaseCommands(DoublyLinkedList<string> *student_data, DoublyLinkedList<string> *faculty_data);

  /*Destructor: ~DatabaseCommands
  * Deletes transaction_records_, error_checker_, and file_
  */
  ~DatabaseCommands();

  /*Member Function: PrintMenu
  * Prints all of the commands available to the user.
  */
  void PrintMenu();

  /*Member Function: PrintAllStudents
  * Prints out all student's in ascending order.
  */
  void PrintAllStudents();

  /*Member Function: PrintAllFaculty
  * Prints out all faculty member's in ascending order.
  */
  void PrintAllFaculty();

  /*Member Function: DisplayStudent
  * Prints out a student's data based on a user-provided student id.
  */
  void DisplayStudent();

  /*Member Function: DisplayFaculty
  * Prints out a faculty's data based on a user-provided faculty id.
  */
  void DisplayFaculty();

  /*Member Function: PrintAdvisor
  * Prints a student's advisor data based on a user-provided student id.
  */
  void PrintAdvisor();

  /*Member Function: PrintAdvisees
  * Prints out the data of every advisees for a given faculty member.
  */
  void PrintAdvisees();

  /*Member Function: AddStudent
  * Prompts the user for data to create a new student object and adds it to the master_student_ BST
  */
  void AddStudent();

  /*Member Function: AddFaculty
  * Prompts the user for data to create a new faculty object and adds it to the master_faculty_ BST
  */
  void AddFaculty();

  /*Member Function: DeleteStudent
  * Deletes a student from the master_student_ BST based on a user-provided student id
  */
  void DeleteStudent();

  /*Member Function: DeleteFaculty
  * Deletes a faculty member from the master_faculty_ BST based on a user-provided faculty id
  */
  void DeleteFaculty();

  /*Member Function: ChangeAdvisor
  * Changes a student's advisor by prompting the user for a student id and the id of the new advisor
  */
  void ChangeAdvisor();

  /*Helper Method: ChangeAdvisor
  * Change's a student's advisor when the user executes a command that compromises referential integrity
  * Paramters:
  * *student: a pointer to the student object that needs an updated advisor
  */
  void ChangeAdvisor(Student *student);

  /*Member Function: RemoveAdvisee
  * Removes an advisee from a faculty member's list of advisees and prompts the user to update the removed student's advisor
  */
  void RemoveAdvisee();

  /*Member Function: Rollback
  * Allows the user to undo the last 5 commands that added or removed a student or faculty member from their respective trees
  */
  void Rollback();

  /*Member Function: WriteFiles
  * Writes all the data from the master_faculty_ and master_student_ BSTs to their own respective files.
  */
  void WriteFiles();

private:
  /*Helper Method: PopulateStudentBST
  * Creates student objects based on data from a previously stored file and adds them to the master_student_ BST
  * Parameters:
  * *student_data: a pointer to a DoublyLinkedList of strings representing the data from a file
  */
  void PopulateStudentBST(DoublyLinkedList<string> *student_data);

  /*Helper Method: PopulateFacultyBST
  * Creates faculty objects based on data from a previously stored file and adds them to the master_faculty_ BST
  * Parameters:
  * *faculty_data: a pointer to a DoublyLinkedList of strings representing the data from a file
  */
  void PopulateFacultyBST(DoublyLinkedList<string> *faculty_data);

  /*Member Variable: *master_student_
  * A pointer to a BST of Student objects.
  */
  BinarySearchTree<Student> *master_student_;

  /*Member Variable: *master_faculty_
  * A pointer to a BST of Faculty objects.
  */
  BinarySearchTree<Faculty> *master_faculty_;

  /*Member Variable: *transaction_records_
  * A pointer to a stack of TransactionRecord objects
  */
  GenStack<TransactionRecord*> *transaction_records_;

  /*Member Variable: *error_checker_
  * A pointer to an Errors object
  */
  Errors *error_checker_;

  /*Member Variable: *file_
  * A pointer to a File object
  */
  File *file_;

  /*Member Variable: transaction_count_
  * An int representing the amount of transactions the user can rollback. 
  */
  int transaction_count_;

};
#endif
