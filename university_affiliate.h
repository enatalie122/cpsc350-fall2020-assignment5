/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//university_affiliate.h is the header file for the abstract UniversityAffiliate class

#ifndef UNIVERSITY_AFFILIATE
#define UNIVERSITY_AFFILIATE

#include <string>
using namespace std;

//The UniversityAffiliate class is an abstract class for students and faculty
class UniversityAffiliate{
public:
  /*Default Constructor: UniversityAffiliate
  * Sets the id to -1 and all string values to empty strings
  */
  UniversityAffiliate();

  /*Destructor: ~UniversityAffiliate
  * Does not delete anything because no pointers are used in the class
  */
  ~UniversityAffiliate();

  /*Accessor Method: get_name
  * Returns: a string representing the affiliate's name
  */
  string get_name();

  /*Accessor Method: get_id
  * Returns: an int representing the affiliate's id
  */
  int get_id();

  /*Accessor Method: get_level
  * Returns: a string representing the affiliate's level
  */
  string get_level();

  /*Accessor Method: get_area_of_study
  * Returns: a string representing the affiliate's major or department
  */
  string get_area_of_study();

  /*Mutator Method: set_id
  * Parameters:
  * id: an int representing the id of the affiliate
  */
  void set_id(int id);

  /*Mutator Method: set_name
  * Parameters:
  * name: a string representing the name of the affiliate
  */
  void set_name(string name);

  /*Mutator Method: set_level
  * Parameters:
  * level: a string representing the affiliate's level
  */
  void set_level(string level);

  /*Mutator Method: set_area_of_study
  * Parameters:
  * area_of_study: a string representing the affiliate's major or department
  */
  void set_area_of_study(string area_of_study);

  /*Operator Overloader: ==
  * Returns: a bool representing whether or not two university affiliate's are equal based on their id's
  * Parameters:
  * ua: a UniversityAffiliate representing the object to compare to
  */
  bool operator==(UniversityAffiliate ua);

  /*Operator Overloader: !=
  * Returns: a bool representing whether or not two university affiliate's are equal based on their id's
  * Parameters:
  * ua: a UniversityAffiliate representing the object to compare to
  */
  bool operator!=(UniversityAffiliate ua);

  /*Operator Overloader: <
  * Returns: a bool representing which of two UniversityAffiliate's are lesser in value based in their id's
  * Parameters:
  * ua: a UniversityAffiliate representing the object to compare to
  */
  bool operator<(UniversityAffiliate ua);

  /*Operator Overloader: >
  * Returns: a bool representing which of two UniversityAffiliate's are greater in value based in their id's
  * Parameters:
  * ua: a UniversityAffiliate representing the object to compare to
  */
  bool operator>(UniversityAffiliate ua);

protected:
  /*Member Variable: id_
  * An int representing the affiliate's id
  */
  int id_;

  /*Member Variable: name_
  * A string representing the affiliate's name
  */
  string name_;

  /*Member Variable: level_
  * A string representing the affiliate's level
  */
  string level_;

  /*Member Variable: area_of_study_
  * A string representing the affiliate's department or major 
  */
  string area_of_study_;
};
#endif
