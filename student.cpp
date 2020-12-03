/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//student.cpp is the implementation of the student class 

#include "student.h"

Student::Student(){
  gpa_ = 0.0;
  advisor_ = -1;
}

Student::~Student(){}

void Student::set_gpa(double gpa){
  gpa_ = gpa;
}

void Student::set_advisor(int advisor){
  advisor_ = advisor;
}

double Student::get_gpa(){
  return gpa_;
}

int Student::get_advisor(){
  return advisor_;
}

ostream& operator<<(ostream& os, const Student& s){
    os << "Name: " << s.name_ << endl;
    os << "ID: " << s.id_ << endl;
    os << "Level: " << s.level_ << endl;
    os << "Major: " << s.area_of_study_ << endl;
    os << "GPA: " << s.gpa_ << endl;
    os << "Advisor: " << s.advisor_ << endl;
    return os;
}
