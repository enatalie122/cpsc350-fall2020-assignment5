/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//university_affiliate.cpp is the implementation of the UniversityAffiliate class 

#include "university_affiliate.h"

UniversityAffiliate::UniversityAffiliate(){
  id_ = -1;
  name_ = "";
  level_ = "";
  area_of_study_ = "";
}

UniversityAffiliate::~UniversityAffiliate(){}

string UniversityAffiliate::get_name(){
  return name_;
}

int UniversityAffiliate::get_id(){
  return id_;
}

string UniversityAffiliate::get_level(){
  return level_;
}

string UniversityAffiliate::get_area_of_study(){
  return area_of_study_;
}

void UniversityAffiliate::set_id(int id){
  id_ = id;
}

void UniversityAffiliate::set_name(string name){
  name_ = name;
}

void UniversityAffiliate::set_level(string level){
  level_ = level;
}

void UniversityAffiliate::set_area_of_study(string area_of_study){
  area_of_study_ = area_of_study;
}

bool UniversityAffiliate::operator==(UniversityAffiliate ua){
  return(ua.get_id() == id_);
}

bool UniversityAffiliate::operator!=(UniversityAffiliate ua){
  return(ua.get_id() != id_);
}

bool UniversityAffiliate::operator<(UniversityAffiliate ua){
  return(id_ < ua.get_id());
}

bool UniversityAffiliate::operator>(UniversityAffiliate ua){
  return(id_ > ua.get_id());
}
