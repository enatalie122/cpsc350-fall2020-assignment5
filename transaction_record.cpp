/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//transaction_record.cpp is the implementation of the TransactionRecord class 

#include "transaction_record.h"

TransactionRecord::TransactionRecord(){
  transaction_type_ = -1;
  student_ = new Student();
  faculty_ = new Faculty();
  advisees_ = new DoublyLinkedList<int>();
  advisor_ = -1;
}

TransactionRecord::TransactionRecord(int transaction_type, Student *s){
  transaction_type_ = transaction_type;
  student_ = s;
}

TransactionRecord::TransactionRecord(int transaction_type, Student *s, int advisor){
  transaction_type_ = transaction_type;
  student_ = s;
  advisor_ = advisor;
}

TransactionRecord::TransactionRecord(int transaction_type, Faculty *f){
  transaction_type_ = transaction_type;
  faculty_ = f;
}

TransactionRecord::TransactionRecord(int transaction_type, Faculty *f, DoublyLinkedList<int> *advisees){
  transaction_type_ = transaction_type;
  faculty_ = f;
  advisees_ = advisees;
}

TransactionRecord::~TransactionRecord(){
  delete student_;
  delete faculty_;
}

int TransactionRecord::get_transaction_type(){
  return transaction_type_;
}

Student* TransactionRecord::get_student(){
  return student_;
}

Faculty* TransactionRecord::get_faculty(){
  return faculty_;
}

DoublyLinkedList<int>* TransactionRecord::get_advisees(){
  return advisees_;
}

int TransactionRecord::get_advisor(){
  return advisor_;
}
