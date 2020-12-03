/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//faculty.cpp is the implementation of the Faculty class 

#include "faculty.h"

Faculty::Faculty(){
  advisees_ = new DoublyLinkedList<int>();
}

Faculty::~Faculty(){}

void Faculty::AddAdvisee(int advisee_id){
  advisees_->Append(advisee_id);
}

void Faculty::RemoveAdvisee(int advisee_id){
  advisees_->RemoveKey(advisee_id);
}

DoublyLinkedList<int>* Faculty::get_advisees(){
  return advisees_;
}

ostream& operator<<(ostream& os, const Faculty& f){
    os << "Name: " << f.name_ << endl;
    os << "ID: " << f.id_ << endl;
    os << "Level: " << f.level_ << endl;
    os << "Department: " << f.area_of_study_ << endl;
    os << "Advisees: ";
    for(int i = 0; i < f.advisees_->GetLength(); ++i){
      os << f.advisees_->GetDataFromPosition(i) << " ";
    }
    os << endl;
    return os;
}
