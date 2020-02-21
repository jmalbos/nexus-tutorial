// -----------------------------------------------------------------------------
//  C++ Intro | 1-arguments.cpp
//
//  Passing arguments by value, reference and pointer.
// -----------------------------------------------------------------------------

#include <iostream>


int add_one_by_value(int number)
{
  return ++number;
}


int add_one_by_ref(int& number)
{
  return ++number;
}


int add_one_by_pointer(int* number)
{
  return ++(*number);
}


int main()
{
  std::cout << "\nC++ Intro | 1-arguments\n" << std::endl;

  //////////////////////////////////////////////////////////

  // Passing argument by value

  int number = 0;
  std::cout << "number: " << number << std::endl;
  std::cout << "add_one_by_value(number): " << add_one_by_value(number) << std::endl;
  std::cout << "number: " << number << "\n" << std::endl;

  //////////////////////////////////////////////////////////

  // Passing arguments by reference

  number = 0;
  std::cout << "number: " << number << std::endl;
  std::cout << "add_one_by_ref(number): " << add_one_by_ref(number) << std::endl;
  std::cout << "number: " << number << "\n" << std::endl;

  //////////////////////////////////////////////////////////

  // Passing arguments by pointer

  number = 0;
  int* pointer = nullptr;
  pointer = &number;

  std::cout << "number: " << number << std::endl;
  std::cout << "add_one_by_pointer(pointer): " << add_one_by_pointer(pointer) << std::endl;
  std::cout << "number: " << number << std::endl;

  return 0;
}
