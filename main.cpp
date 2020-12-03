/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

#include "binary_search_tree.h"
#include "student.h"
#include "faculty.h"
#include "file.h"
#include "errors.h"
#include "database_commands.h"

int main(int argc, char** argv){

  Errors *error_checker = new Errors();
  DatabaseCommands *command;
  File *student_file = new File();
  student_file->set_file_name("studentTable.txt");
  File *faculty_file = new File();
  faculty_file->set_file_name("facultyTable.txt");

  if(student_file->ReadFile()){  //if "studentTable.txt" exists
    faculty_file->ReadFile();
    command = new DatabaseCommands(student_file->get_file_contents(), faculty_file->get_file_contents());
  } else if (faculty_file->ReadFile()) {   //if "facultyTable.txt" exists, but "studentTable.txt" does not
    command = new DatabaseCommands(student_file->get_file_contents(), faculty_file->get_file_contents());
  } else {
    command = new DatabaseCommands();
  }

  cout << endl;
  while(true){

    command->PrintMenu();
    int user_choice = -1;
    int loop_counter = 0;

    while(user_choice < 1 || user_choice > 14){
      //prompts the user to enter a command until an int between 1 and 14 is entered 
      user_choice = error_checker->CheckIntInput(loop_counter, "Choose a command (Enter a number between 1-14): ");
      loop_counter ++;
    }
    cout << endl;

    if(user_choice == 1){
      command->PrintAllStudents();
      cout << endl;
    } else if (user_choice == 2){
      command->PrintAllFaculty();
      cout << endl;
    } else if (user_choice == 3){
      command->DisplayStudent();
      cout << endl;
    } else if (user_choice == 4){
      command->DisplayFaculty();
      cout << endl;
    } else if (user_choice == 5){
      command->PrintAdvisor();
      cout << endl;
    } else if (user_choice == 6){
      command->PrintAdvisees();
    } else if (user_choice == 7){
      command->AddStudent();
      cout << endl;
    } else if (user_choice == 8){
      command->DeleteStudent();
      cout << endl;
    } else if (user_choice == 9){
      command->AddFaculty();
      cout << endl;
    } else if (user_choice == 10){
      command->DeleteFaculty();
      cout << endl;
    } else if (user_choice == 11){
      command->ChangeAdvisor();
      cout << endl;
    } else if (user_choice == 12){
      command->RemoveAdvisee();
      cout << endl;
    } else if (user_choice == 13){
      command->Rollback();
      cout << endl;
    } else if (user_choice == 14){
      command->WriteFiles();
      break;
    }
  }
  delete error_checker;
  delete command;
  delete student_file;
  delete faculty_file;

  return 0;
}
