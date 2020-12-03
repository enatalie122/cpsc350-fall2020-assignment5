/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//student.h is the header file for the Student class

#ifndef STUDENT
#define STUDENT

#include "university_affiliate.h"
#include <iostream>
using namespace std;

//The Student class decends from the UniversityAffiliate base class and holds data to represent a student
class Student : public UniversityAffiliate{
public:
  /*Default Constructor: Student
  * Set's the gpa to 0.0 and the advisor to -1
  */
  Student();

  /*Destructor: ~Student
  * Does not delete anything because no pointers are used
  */
  ~Student();

  /*Mutator Function: set_gpa
  * Paramters:
  * gpa: a double representing the student's gpa
  */
  void set_gpa(double gpa);

  /*Mutator Function: set_advisor
  * Paramters:
  * advisor: an int representing the id of the student's advisor
  */
  void set_advisor(int advisor);

  /*Accessor Function: get_gpa
  * Returns: a double representing the student's gpa
  */
  double get_gpa();

  /*Accessor Function: get_advisor
  * Returns an int representing the id of the student's advisor
  */
  int get_advisor();

  /* Operator Overloader: operator<<
  * Overloads the << operator so the student object can be printed with the cout object.
  * Parameters:
  * os: a reference to an ostream object
  * s: a reference to a student object
  * Returns:
  * A reference to the os ostream object.
  */
  friend ostream& operator<<(ostream& os, const Student& s);

private:
  double gpa_;
  int advisor_;

};
#endif
