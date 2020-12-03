/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/


//errors.h is the header file for the Errors class.


#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <string>
#include <iostream>

using namespace std;

//The Errors class checks for errors in user input
class Errors{

public:
  /*Default constructor: Errors
  Sets string numbers to contain all 10 digits and a decimal
  */
  Errors();

  /*CheckIntInput
  Parameters:
    loop_number: an int representing the number of iterations in a loop
    message: a string representing instructions for the user to proceed after an error
  Throws std::exception if the user does not enter an integer
  */
  int CheckIntInput(int loop_number, string message);
  /*CheckDoubleInput
  Parameters:
    loop_number: an int representing the number of iterations in a loop
    message: a string representing instructions for the user to proceed after an error
  Throws std::exception if the user does not enter a double
  */
  double CheckDoubleInput(int loop_number, string message);
};
#endif
