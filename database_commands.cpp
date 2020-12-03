#include "database_commands.h"

DatabaseCommands::DatabaseCommands(){
  master_student_ = new BinarySearchTree<Student>();
  master_faculty_ = new BinarySearchTree<Faculty>();
  transaction_records_ = new GenStack<TransactionRecord*>();
  error_checker_ = new Errors();
  file_ = new File();
  transaction_count_ = 5;
}

DatabaseCommands::DatabaseCommands(DoublyLinkedList<string> *student_data, DoublyLinkedList<string> *faculty_data){
  master_student_ = new BinarySearchTree<Student>();
  PopulateStudentBST(student_data);
  master_faculty_ = new BinarySearchTree<Faculty>();
  PopulateFacultyBST(faculty_data);
  transaction_records_ = new GenStack<TransactionRecord*>();
  error_checker_ = new Errors();
  file_ = new File();
  transaction_count_ = 5;
}

DatabaseCommands::~DatabaseCommands(){
  delete transaction_records_;
  delete error_checker_;
  delete file_;
}

void DatabaseCommands::PrintMenu(){
  cout << "1. Display all students and their data" << endl;
  cout << "2. Display all faculty and their data" << endl;
  cout << "3. Display a student's data" << endl;
  cout << "4. Display a faculty member's data" << endl;
  cout << "5. Display a student's faculty advisor data" << endl;
  cout << "6. Display a faculty member's advisees" << endl;
  cout << "7. Add a new student" << endl;
  cout << "8. Delete a student" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member" << endl;
  cout << "11. Change a student's advisor" << endl;
  cout << "12. Remove advisee from faculty member" << endl;
  cout << "13. Rollback" << endl;
  cout << "14. Exit" << endl;
  cout << "Choose a command: ";
}

void DatabaseCommands::PrintAllStudents(){
  master_student_->PrintEntireTree();
}

void DatabaseCommands::PrintAllFaculty(){
  master_faculty_->PrintEntireTree();
}

void DatabaseCommands::DisplayStudent(){
  Student *temp_student = new Student();
  int student_id = -1;
  int loop_counter = 0;               //the number of iterations until the user enters acceptable data
  while(student_id < 0){
    cout << "Enter student ID: ";
    while (student_id < 0){
      student_id = error_checker_->CheckIntInput(loop_counter, "Enter student ID: ");   //checks if the user has entered an int
      loop_counter++;                                                                   //repeats until the user enters an int
    }
    temp_student->set_id(student_id);
    if(master_student_->SearchNode(*temp_student) == false){                            //if the sudent id doesn't match any data in the student BST
      cout << "Student does not exist." << endl;                                        //let's the user know and prompts them to try again
      student_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }
  Student *student = master_student_->AccessNode(*temp_student);                         //access student data from BST and prints it to the user
  cout << endl << *student;
}

void DatabaseCommands::DisplayFaculty(){
  Faculty *temp_faculty = new Faculty();                                                 //same code as DisplayStudent, but with Faculty objects
  int faculty_id = -1;
  int loop_counter = 0;
  while(faculty_id < 0){
    cout << "Enter faculty ID: ";
    while (faculty_id < 0){
      faculty_id = error_checker_->CheckIntInput(loop_counter, "Enter faculty ID: ");
      loop_counter++;
    }
    temp_faculty->set_id(faculty_id);
    if(master_faculty_->SearchNode(*temp_faculty) == false){
      cout << "Faculty member does not exist." << endl;
      faculty_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }
  Faculty *faculty = master_faculty_->AccessNode(*temp_faculty);
  cout << endl << *faculty;
}

void DatabaseCommands::PrintAdvisor(){
  Student *temp_student = new Student();
  int student_id = -1;
  int loop_counter = 0;
  while(student_id < 0){                                           //same error checking as DisplayStudent
    cout << "Enter student ID: ";
    while (student_id < 0){
      student_id = error_checker_->CheckIntInput(loop_counter, "Enter student ID: ");
      loop_counter++;
    }
    temp_student->set_id(student_id);
    if(master_student_->SearchNode(*temp_student) == false){
      cout << "Student does not exist." << endl;
      student_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }
  Student *student = master_student_->AccessNode(*temp_student);
  Faculty *temp_faculty = new Faculty();
  temp_faculty->set_id(student->get_advisor());
  Faculty *faculty = master_faculty_->AccessNode(*temp_faculty);      //searches master_faculty_ for the student's advisor and prints their data
  cout << *faculty << endl;
}

void DatabaseCommands::PrintAdvisees(){
  Faculty *temp_faculty = new Faculty();
  int faculty_id = -1;
  int loop_counter = 0;                        //same error checking code as DisplayFaculty
  while(faculty_id < 0){
    cout << "Enter faculty ID: ";
    while (faculty_id < 0){
      faculty_id = error_checker_->CheckIntInput(loop_counter, "Enter faculty ID: ");
      loop_counter++;
    }
    temp_faculty->set_id(faculty_id);
    if(master_faculty_->SearchNode(*temp_faculty) == false){
      cout << "Faculty member does not exist." << endl;
      faculty_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }
  Faculty *faculty = master_faculty_->AccessNode(*temp_faculty);
  for(int i = 0; i < faculty->get_advisees()->GetLength(); ++i){      //accesses the data of each student in the faculty's advisees list and prints their data
    Student *temp_student = new Student();
    temp_student->set_id(faculty->get_advisees()->GetDataFromPosition(i));
    Student *student = master_student_->AccessNode(*temp_student);
    cout << endl << *student << endl;
  }
}

void DatabaseCommands::AddStudent(){
  Student *s = new Student();
  cout << "Enter student name: ";
  string name;
  getline(cin, name);
  s->set_name(name);

  int id = -1;
  int loop_counter = 0;
  while(id < 0){
    cout << "Enter student ID: ";
    while(id < 0){                          //prompts userto enter a valid id until an int is entered
      id = error_checker_->CheckIntInput(loop_counter, "Enter student ID: ");
      loop_counter++;
    }
    Student *temp_student = new Student();
    temp_student->set_id(id);
    if(master_student_->SearchNode(*temp_student) == true){           //if the id is already in use by another student
      cout << "Invalid input. ID already in use." << endl;            //prompts the user to enter a different id
      loop_counter = 0;
      id = -1;
    } else {
      s->set_id(id);
    }
  }

  cout << "Enter student level: ";
  string level;
  getline(cin, level);
  s->set_level(level);

  cout << "Enter student major: ";
  string major;
  getline(cin, major);
  s->set_area_of_study(major);

  cout << "Enter student GPA: ";
  double gpa = -1;
  loop_counter = 0;
  while(gpa < 0 || gpa > 5.0){                //prompts the user to enter a valid gpa until they enter a double between 0 and 5 (allows for weighted gpas)
    gpa = error_checker_->CheckDoubleInput(loop_counter, "Enter student GPA: ");
    loop_counter++;
  }
  s->set_gpa(gpa);

  int advisor = -2;
  loop_counter = 0;
  cout << "Enter student advisor (-1 to skip): ";
  while(advisor != -1){           //prompts user to enter a valid id until an int is entered, or the user chooses to skip this step
    while(advisor < -1){
      advisor = error_checker_->CheckIntInput(loop_counter, "Enter student advisor (-1 to skip): ");
      loop_counter++;
    }
    if(advisor == -1){
      break;
    }
    Faculty *temp_faculty = new Faculty();
    temp_faculty->set_id(advisor);
    if(master_faculty_->SearchNode(*temp_faculty) == false){       //checks if the faculty member actually exists
      cout << "Advisor does not exist." << endl;
      cout << "Enter student advisor (-1 to skip): ";
      advisor = -2;
      loop_counter = 0;
    } else {
      Faculty *f = master_faculty_->AccessNode(*temp_faculty);      //once a valid id is entered, then the student's advisor is updated
      s->set_advisor(advisor);
      f->AddAdvisee(s->get_id());
      break;
    }
  }

  master_student_->InsertNode(*s);                        //once all data is collected from the user, the student is added to the BST
  TransactionRecord *t = new TransactionRecord(1, s);     //TransactionRecord is created and added to stack to potentially be rolled back later
  transaction_records_->Push(t);
  if(transaction_count_ < 5)                              //if the user has less than 5 rollbacks available, another rollback is now able to be accessed
    transaction_count_++;
}

void DatabaseCommands::AddFaculty(){

  Faculty *f = new Faculty();

  cout << "Enter faculty name: ";
  string name;
  getline(cin, name);
  f->set_name(name);

  int id = -1;
  int loop_counter = 0;
  while(id < 0){                    //prompts the user to enter a valid id until an int is entered
    cout << "Enter faculty ID: ";
    while(id < 0){
      id = error_checker_->CheckIntInput(loop_counter, "Enter faculty ID: ");
      loop_counter++;
    }
    Faculty *temp_faculty = new Faculty();
    temp_faculty->set_id(id);
    if(master_faculty_->SearchNode(*temp_faculty) == true){        //if the id is already in use, the user is prompted to try again
      cout << "Invalid input. ID already in use." << endl;
      loop_counter = 0;
      id = -1;
    } else {
      f->set_id(id);
    }
  }

  cout << "Enter faculty level: ";
  string level;
  getline(cin, level);
  f->set_level(level);

  cout << "Enter faculty department: ";
  string department;
  getline(cin, department);
  f->set_area_of_study(department);

  master_faculty_->InsertNode(*f);                      //once all data is collected, the faculty member is added to the faculty BST
  TransactionRecord *t = new TransactionRecord(2, f);   //TransactionRecord is created and added to stack to potentially be rolled back later
  transaction_records_->Push(t);
  if(transaction_count_ < 5)                            //if the user has less than 5 rollbacks available, another rollback is now able to be accessed
    transaction_count_++;
}

void DatabaseCommands::DeleteStudent(){
  Student *temp_student = new Student();
  int student_id = -1;
  int loop_counter = 0;
  while(student_id < 0){    //same code as DisplayStudent error handling
    cout << "Enter student ID: ";
    while (student_id < 0){
      student_id = error_checker_->CheckIntInput(loop_counter, "Enter student ID: ");
      loop_counter++;
    }
    temp_student->set_id(student_id);
    if(master_student_->SearchNode(*temp_student) == false){
      cout << "Student does not exist." << endl;
      student_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }

  Student *student = master_student_->AccessNode(*temp_student);
  int advisor_id = student->get_advisor();    //get's the id of the student's advisor to update their data
  master_student_->DeleteNode(*student);      //remove student from BST

  if(advisor_id != -1){                       //if the student has an advisor
    Faculty *temp_faculty = new Faculty();
    temp_faculty->set_id(advisor_id);
    Faculty *advisor = master_faculty_->AccessNode(*temp_faculty);
    advisor->RemoveAdvisee(student->get_id());       //the student is removed from the faculty's advisees list
  }

  TransactionRecord *t = new TransactionRecord(3, student, advisor_id); //TransactionRecord is created and added to stack to potentially be rolled back later
  transaction_records_->Push(t);
  if(transaction_count_ < 5)                     //if the user has less than 5 rollbacks available, another rollback is now able to be accessed
    transaction_count_++;
}

void DatabaseCommands::DeleteFaculty(){
  Faculty *temp_faculty = new Faculty();
  int faculty_id = -1;
  int loop_counter = 0;
  while(faculty_id < 0){     //same code as DisplayFaculty error handling
    cout << "Enter faculty advisor ID: ";
    while (faculty_id < 0){
      faculty_id = error_checker_->CheckIntInput(loop_counter, "Enter faculty advisor ID: ");
      loop_counter++;
    }
    temp_faculty->set_id(faculty_id);
    if(master_faculty_->SearchNode(*temp_faculty) == false){
      cout << "Faculty member does not exist." << endl;
      faculty_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }

  Faculty *faculty = master_faculty_->AccessNode(*temp_faculty);
  master_faculty_->DeleteNode(*faculty);           //Faculty member is removed from tree

  for(int i = 0; i < faculty->get_advisees()->GetLength(); ++i){             //Prompts the user to provide a new advisor for the faculty's advisees
    Student *temp_student = new Student();
    temp_student->set_id(faculty->get_advisees()->GetDataFromPosition(i));
    Student *student = master_student_->AccessNode(*temp_student);
    ChangeAdvisor(student);
  }

  TransactionRecord *t = new TransactionRecord(4, faculty);   //TransactionRecord is created and added to stack to potentially be rolled back later
  transaction_records_->Push(t);
  if(transaction_count_ < 5)                  //if the user has less than 5 rollbacks available, another rollback is now able to be accessed
    transaction_count_++;
}

void DatabaseCommands::ChangeAdvisor(){
  Student *temp_student = new Student();
  int student_id = -1;
  int loop_counter = 0;    //same code as DisplayStudent error handling
  while(student_id < 0){
    cout << "Enter student ID: ";
    while (student_id < 0){
      student_id = error_checker_->CheckIntInput(loop_counter, "Enter student ID: ");
      loop_counter++;
    }
    temp_student->set_id(student_id);
    if(master_student_->SearchNode(*temp_student) == false){
      cout << "Student does not exist." << endl;
      student_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }

  Faculty *temp_faculty = new Faculty();
  int faculty_id = -1;
  loop_counter = 0;                 //same code as DisplayFaculty error handling
  while(faculty_id < 0){
    cout << "Enter new faculty advisor ID: ";
    while (faculty_id < 0){
      faculty_id = error_checker_->CheckIntInput(loop_counter, "Enter new faculty advisor ID: ");
      loop_counter++;
    }
    temp_faculty->set_id(faculty_id);
    if(master_faculty_->SearchNode(*temp_faculty) == false){
      cout << "Faculty member does not exist." << endl;
      faculty_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }

  Student *student = master_student_->AccessNode(*temp_student);
  Faculty *new_advisor = master_faculty_->AccessNode(*temp_faculty);
  int previous_advisor = student->get_advisor();      //access the student's current advisor so we can update their data

  if(previous_advisor != -1){                         //if they had an advisor before the update
    Faculty *temp_advisor = new Faculty();
    temp_advisor->set_id(previous_advisor);
    Faculty *old_advisor = master_faculty_->AccessNode(*temp_advisor);
    old_advisor->RemoveAdvisee(student->get_id());    //remove the student as an advisee of the faculty member
  }

  student->set_advisor(new_advisor->get_id());
  new_advisor->AddAdvisee(student->get_id());
}

void DatabaseCommands::ChangeAdvisor(Student *student){
  Faculty *temp_faculty = new Faculty();
  int faculty_id = -1;
  int loop_counter = 0;
  while(faculty_id < 0){
    cout << "Enter new faculty advisor ID for " << student->get_name() << ": ";
    while (faculty_id < 0){             //prompts the user to enter a valid id until an int is entered
      faculty_id = error_checker_->CheckIntInput(loop_counter, "Enter new faculty advisor ID: ");
      loop_counter++;
    }
    temp_faculty->set_id(faculty_id);
    if(master_faculty_->SearchNode(*temp_faculty) == false){      //checks if faculty member exists
      cout << "Faculty member does not exist." << endl;
      faculty_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }

  Faculty *new_advisor = master_faculty_->AccessNode(*temp_faculty);

  student->set_advisor(new_advisor->get_id());
  new_advisor->AddAdvisee(student->get_id());
}

void DatabaseCommands::RemoveAdvisee(){
  Faculty *temp_faculty = new Faculty();
  int faculty_id = -1;
  int loop_counter = 0;     //same code as DisplayFaculty error handling
  while(faculty_id < 0){
    cout << "Enter faculty ID: ";
    while (faculty_id < 0){
      faculty_id = error_checker_->CheckIntInput(loop_counter, "Enter faculty ID: ");
      loop_counter++;
    }
    temp_faculty->set_id(faculty_id);
    if(master_faculty_->SearchNode(*temp_faculty) == false){
      cout << "Faculty member does not exist." << endl;
      faculty_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }

  Faculty *faculty = master_faculty_->AccessNode(*temp_faculty);

  Student *temp_student = new Student();
  int student_id = -1;
  loop_counter = 0;
  while(student_id < 0){              //repeats until an int is entered
    cout << "Enter student advisee ID: ";
    while (student_id < 0){
      student_id = error_checker_->CheckIntInput(loop_counter, "Enter student advisee ID: ");
      loop_counter++;
    }
    temp_student->set_id(student_id);
    if(master_student_->SearchNode(*temp_student) == false){         //repeats until a student in the BST is entered
      cout << "Student does not exist." << endl;
      student_id = -1;
      loop_counter = 0;
    } else if (faculty->get_advisees()->Search(student_id) == -1){     //repeats until an advisee of the faculty member is entered
      cout << "Student is not an advisee of choosen faculty member." << endl;
      student_id = -1;
      loop_counter = 0;
    } else {
      break;
    }
  }

  Student *student = master_student_->AccessNode(*temp_student);

  faculty->RemoveAdvisee(student_id);
  ChangeAdvisor(student);
}

void DatabaseCommands::Rollback(){
  if(transaction_records_->IsEmpty() || transaction_count_ == 0){  //won't allow the user to rollback if there's nothing on the stack, or if
    cout << "Cannot rollback." << endl;                            //they've already performed the last 5 rollbacks
  } else {
    TransactionRecord *t = transaction_records_->Pop();
    if(t->get_transaction_type() == 1){                           //if the user wants to rollback a student who was added to the tree
      Student *temp_student = t->get_student();
      Student *s = master_student_->AccessNode(*temp_student);
      if(s->get_advisor() != -1){                                 //if the student has an advisor
        Faculty *temp_faculty = new Faculty();
        temp_faculty->set_id(s->get_advisor());
        Faculty *faculty = master_faculty_->AccessNode(*temp_faculty);
        faculty->RemoveAdvisee(s->get_id());                      //remove the advisee from their advisees list
      }
      master_student_->DeleteNode(*s);                            //remove the student from the tree

    } else if (t->get_transaction_type() == 2){                   //if the user wants to rollback a faculty member who was added to the tree
      Faculty *temp_faculty = t->get_faculty();
      Faculty *f = master_faculty_->AccessNode(*temp_faculty);
      if(!f->get_advisees()->IsEmpty()){                          //if the faculty member has advisees
        for(int i = 0; i < f->get_advisees()->GetLength(); ++i){  //iterate through each student
          Student *temp_student = new Student();
          temp_student->set_id(f->get_advisees()->GetDataFromPosition(i));
          Student *s = master_student_->AccessNode(*temp_student);
          ChangeAdvisor(s);                                       //prompt the user to change the student's advisor
        }
      }
      master_faculty_->DeleteNode(*f);                            //remove the faculty from the tree

    } else if (t->get_transaction_type() == 3){                   //if the user wants to rollback a deleted student
      Student *s = t->get_student();
      if(s->get_advisor() != -1){                                 //if the student had an advisor
        Faculty *temp_faculty = new Faculty();
        temp_faculty->set_id(s->get_advisor());
        Faculty *faculty = master_faculty_->AccessNode(*temp_faculty);
        faculty->AddAdvisee(s->get_id());                         //add the student back to the faculty's list of advisees
      }
      master_student_->InsertNode(*s);                            //add the student to the student BST

    } else if (t->get_transaction_type() == 4){                   //if the user wants to rollback a deleted faculty member
      Faculty *f = t->get_faculty();
      if(!f->get_advisees()->IsEmpty()){                          //if the faculty member had advisees
        for(int i = 0; i < f->get_advisees()->GetLength(); ++i){
          Student *temp_student = new Student();
          temp_student->set_id(f->get_advisees()->GetDataFromPosition(i));
          Student *s = master_student_->AccessNode(*temp_student);
          s->set_advisor(f->get_id());                            //update the student to their old advisor
        }
      }
      master_faculty_->InsertNode(*f);                            //add the faculty member to the tree
    }
    transaction_count_--;                                         //decrement the amount of rollbacks the user has available to them
  }
}

void DatabaseCommands::WriteFiles(){
  file_->WriteFile(master_student_);
  file_->WriteFile(master_faculty_);
}

void DatabaseCommands::PopulateStudentBST(DoublyLinkedList<string> *student_data){
  if(student_data->GetLength() > 5){        //if the file contains at least one student
    for(int i = 0; i < student_data->GetLength() - 2; ++i){   //iterate through each line of the file containing data
      if(i % 6 == 0){
        Student *s = new Student();                 //create a new student object and set their data to match the file
        s->set_name(student_data->GetDataFromPosition(i));
        s->set_id(stoi(student_data->GetDataFromPosition(i + 1)));
        s->set_level(student_data->GetDataFromPosition(i + 2));
        s->set_area_of_study(student_data->GetDataFromPosition(i + 3));
        s->set_gpa(stod(student_data->GetDataFromPosition(i + 4)));
        s->set_advisor(stoi(student_data->GetDataFromPosition(i + 5)));
        master_student_->InsertNode(*s);
      }
    }
  }
}

void DatabaseCommands::PopulateFacultyBST(DoublyLinkedList<string> *faculty_data){
  faculty_data->RemoveBack();            //the last line of the file is always an empty line
  if(faculty_data->GetLength() > 4){           //if there is at least one faculty member
    while(!faculty_data->IsEmpty()){      //iterate until the end of the file is reached
      Faculty *f = new Faculty();         //create a new faculty object and update their data to match the file
      f->set_name(faculty_data->GetDataFromPosition(0));
      faculty_data->RemoveFront();
      f->set_id(stoi(faculty_data->GetDataFromPosition(0)));
      faculty_data->RemoveFront();
      f->set_level(faculty_data->GetDataFromPosition(0));
      faculty_data->RemoveFront();
      f->set_area_of_study(faculty_data->GetDataFromPosition(0));
      faculty_data->RemoveFront();
      while(faculty_data->GetDataFromPosition(0) != "-1"){      //add advisees until the -1 marker is found , indicating to create the next faculty member or end loop
        f->AddAdvisee(stoi(faculty_data->GetDataFromPosition(0)));
        faculty_data->RemoveFront();
      }
      faculty_data->RemoveFront();
      master_faculty_->InsertNode(*f);            //add the faculty member to the faculty BST 
    }
  }
}
