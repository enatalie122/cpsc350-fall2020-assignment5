/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 5: Building a Database with BSTs
*/

//gen_stack.h is the header file for, and the implementation of, the GenStack class.


#ifndef GEN_STACK_H
#define GEN_STACK_H

#include <iostream>
#include <exception>
using namespace std;

//The GenStack class is a template class for a basic array-based stack
template <class type> class GenStack{

public:
  /*Default constructor: GenStack
  Declares an array of specified type to hold 25 elements, sets top member variable to -1, and max_size_ to 25.
  */
  GenStack();
  //~GenStack
  ~GenStack();

  /*Push
  Parameters:
    data: a variable of a specified type representing data to be added to the top of the stack
  */
  void Push(type data);
  /*Pop
  Throws std::exception if the stack is empty
  Returns a variable of a specified type representing the top element that has been removed from the stack
  */
  type Pop();
  /*Peek
  Returns a variable of a specified type representing the current top element on the stack
  */
  type Peek();

  /*IsFull
  Returns a boolean representing whether or not the stack is full.
  */
  bool IsFull();
  /*IsEmpty
  Returns a boolean representing whether or not the stack is empty.
  */
  bool IsEmpty();
  /*GetSize
  Returns an int representing the number of elements on the stack.
  */
  int GetSize();
  //Print
  void Print();

private:
  //Reseize
  void Resize();

  /* *stack_array
  A pointer to an array representing the stack .
  */
  type *stack_array_;
  /* top_
  An int representing the index of the top element of the stack.
  */
  int top_;
  /* max_size_
  An int representing the current max amount of elements the stack can hold without resizing.
  */
  int max_size_;

};

template<class type> GenStack<type>::GenStack(){
  stack_array_ = new type[25];
  top_ = -1;
  max_size_ = 25;
}

template<class type> GenStack<type>::~GenStack(){
  delete stack_array_;
}

template<class type> void GenStack<type>::Push(type data){
  if(IsFull() == true){
    Resize();
  }
  stack_array_[++top_] = data;
}

template<class type> type GenStack<type>::Pop(){
  try{
    if(IsEmpty() == false){
      return stack_array_[top_--];
    } else {
      throw std::exception();
    }
  } catch (std::exception e){
    cout << "Unable to Pop, Stack is empty." << endl;
  }
}

template<class type> type GenStack<type>::Peek(){
  if(IsEmpty() == false){
    return stack_array_[top_];
  } else {
    return '\0';
  }
}

template<class type> bool GenStack<type>::IsFull(){
  return(top_== (max_size_ - 1));
}

template<class type> bool GenStack<type>::IsEmpty(){
  return (top_== -1);
}

template<class type> int GenStack<type>::GetSize(){
  return top_+ 1;
}

template<class type> void GenStack<type>::Print(){
  for(int i = 0; i <= top_; ++i){
    cout << stack_array_[i] << endl;
  }
}

template<class type> void GenStack<type>::Resize(){
  type *new_array = new type[max_size_ + 25];
  for(int i = 0; i < max_size_; ++i){
    new_array[i] = stack_array_[i];
  }
  max_size_ += 25;
  *stack_array_ = *new_array;
}
#endif
