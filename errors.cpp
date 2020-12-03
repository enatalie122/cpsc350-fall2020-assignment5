/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/


//errors.cpp is the implementation file for the Errors class.

#include "errors.h"

Errors::Errors(){}

int Errors::CheckIntInput(int loop_number, string message){
  string numbers_ = "-0123456789";                     //list of acceptable characters representing digits
  int input = 0;
  if (loop_number != 0){                               //will not print error message if it's the user's first try entering data
    cout << "Invalid input." << endl;
    cout << message;
  }
  string temp;
  getline(cin, temp);
  try{
    for (int i = 0; i < temp.length(); ++i){           //checks that each character the user has entered is a digit or negative sign
      if (numbers_.find(temp.at(i)) == string::npos){
        throw std::exception();
      }
    }
    input = stoi(temp);                                //converts user input to an int
  } catch (std::exception e){
    return -2;                                         //returns a value letting the program know the user did not enter an acceptable int
  }
  return input;
}

double Errors::CheckDoubleInput(int loop_number, string message){
  string numbers_ = "0123456789.";                     //list of acceptable characters representing digits
  double input = 0;
  if (loop_number != 0){                               //will not print error message if it's the user's first try entering data
    cout << "Invalid input." << endl;
    cout << message;
  }
  string temp;
  getline(cin, temp);
  try{
    for (int i = 0; i < temp.length(); ++i){           //checks that each character the user has entered is a digit or a decimal
      if (numbers_.find(temp.at(i)) == string::npos){
        throw std::exception();
      }
    }
    input = stod(temp);                                //converts user input to a double
  } catch (std::exception e){
    return -1;                                         //returns a value letting the program know the user did not enter an acceptable double
  }
  return input;
}
