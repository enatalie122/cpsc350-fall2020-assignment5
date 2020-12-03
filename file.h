/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//file.h is the header file for the File class.

#ifndef FILE_H
#define FILE_H

#include <fstream>
#include <string>
#include <iostream>
#include "doubly_linked_list.h"
#include "binary_search_tree.h"
#include "student.h"
#include "faculty.h"

using namespace std;


//The File class reads, writes, and processes specified files.
class File{

public:

  /* Default constructor: File
  * Sets file_name to an empty string, and instantiates an empty DoublyLinkedList.
  */
  File();

  /* Destructor: ~File
  * Deletes the DoublyLinkedList, file_contents_.
  */
  ~File();

  /* Member function: get_file_contents
  * Returns the contents of a file in list form.
  * Returns:
  * A pointer to a DoublyLinkedList of strings where each node contains a line from a file.
  */
  DoublyLinkedList<string>* get_file_contents();

  /*Member function: set_file_name
  * Allows the user to set the name of a file for the File object to read.
  * Parameters:
  * file_name: a string representing the name of a file.
  */
  void set_file_name(string file_name);

  /* Member function: ReadFile
  * Opens and reads a given file, and copies it's contents to a DoublyLinkedList.
  */
  bool ReadFile();

  /* Member Function: WriteFile
  * Creates a .txt file with the name "studentTable" with the contents of a BST of student objects
  * Parameters:
  * *student_BST: a pointer to a BST of student objects
  */
  void WriteFile(BinarySearchTree<Student> *student_BST);

  /* Member Function: WriteFile
  * Creates a .txt file with the name "facultyTable" with the contents of a BST of faculty objects
  * Parameters:
  * *faculty_BST: a pointer to a BST of faculty objects 
  */
  void WriteFile(BinarySearchTree<Faculty> *faculty_BST);


private:
  /* Member variable: file_name_
  * A string representing the name of a file to be processed.
  */
  string file_name_;

  /* Member variable: file_contents_
  * A DoublyLinkedList of ints where each node represts a line from a file.
  */
  DoublyLinkedList<string> *file_contents_;
};

#endif
