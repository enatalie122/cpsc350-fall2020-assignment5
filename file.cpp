/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//file.cpp is the implementation of the File class.

#include "file.h"

File::File(){
  string file_name_ = "";
  file_contents_ = new DoublyLinkedList<string>();
}

File::~File(){
  delete file_contents_;
}

DoublyLinkedList<string>* File::get_file_contents(){
  return file_contents_;
}

void File::set_file_name(string file_name){
  file_name_ = file_name;
}

bool File::ReadFile(){
  string line;
  ifstream file;
  while (file.is_open() == false){
    file.open(file_name_);
    if (file.is_open()){                      //proceed if we can open the file
      while (!file.eof()){
        getline(file, line);
        file_contents_->Append(line);   //adds each line to a DoublyLinkedList
      }
      file.close();
      return true;
    } else {
      return false;
    }
  }
}

void File::WriteFile(BinarySearchTree<Student> *student_BST){
  ofstream my_file;
  my_file.open ("studentTable.txt");
  if (my_file.is_open()){
    while(!student_BST->IsEmpty()){              //while there are nodes in the BST
      Student *s = student_BST->GetRoot();       //get the information held at the root
      my_file << s->get_name() << endl;
      my_file << s->get_id() << endl;
      my_file << s->get_level() << endl;
      my_file << s->get_area_of_study() << endl;
      my_file << s->get_gpa() << endl;
      my_file << s->get_advisor() << endl;
      student_BST->DeleteNode(*s);               //delete the root so you can check the next node
    }
    my_file.close();
  } else {
    cout << "Unable to open file.";
  }
}

void File::WriteFile(BinarySearchTree<Faculty> *faculty_BST){
  ofstream my_file;
  my_file.open ("facultyTable.txt");
  if (my_file.is_open()){
    while(!faculty_BST->IsEmpty()){
      Faculty *f = faculty_BST->GetRoot();
      my_file << f->get_name() << endl;
      my_file << f->get_id() << endl;
      my_file << f->get_level() << endl;
      my_file << f->get_area_of_study() << endl;
      for(int i = 0; i < f->get_advisees()->GetLength(); ++i){  //iterate through the faculty's list of advisees and add to file
        my_file << f->get_advisees()->GetDataFromPosition(i) << endl;
      }
      my_file << -1 << endl;         //print a marker representing the end of the list of advisees 
      faculty_BST->DeleteNode(*f);
    }
    my_file.close();
  } else {
    cout << "Unable to open file.";
  }
}
