// -----------------------------------------------------------------------------
//  C++ Intro | 1-classes.cpp
//
//  Class declaration and definition.
// -----------------------------------------------------------------------------

#include <iostream>

////////////////////////////////////////////////////////////
// Declaration of a class

class MyFirstClass
{
public:
  // Constructor
  MyFirstClass(int);

  // Destructor
  ~MyFirstClass();

  // A public member function.
  // Prints the value of the number stored by the class instance.
  void PublicMemberFunction();

private:
  // A private member function.
  // Prints the value of the number stored by the class instance.
  void PrivateMemberFunction();

private:
  int number_; // A private data member
};

////////////////////////////////////////////////////////////
// Main function of the program

int main()
{
  std::cout << "\nC++ Intro | 2-classes\n" << std::endl;

  // Create a class instance of MyFirstClass
  MyFirstClass class_instance(123);
  // Call the public member function of our instance
  class_instance.PublicMemberFunction();

  // Uncommenting the following line will result in a compilation error
  // class_instance.PrivateMemberFunction();

  return 0;
}

////////////////////////////////////////////////////////////
// Definition of the class

MyFirstClass::MyFirstClass(int number): number_(number)
{
  std::cout << "MyFirstClass::MyFirstClass()" << std::endl;
  PrivateMemberFunction();
}

MyFirstClass::~MyFirstClass()
{
  std::cout << "MyFirstClass::~MyFirstClass()" << std::endl;
}

void MyFirstClass::PublicMemberFunction()
{
  std::cout << "MyFirstClass::PublicMemberFunction()" << std::endl;
  std::cout << "The number is " << number_ << std::endl;
}

void MyFirstClass::PrivateMemberFunction()
{
  std::cout << "MyFirstClass::PrivateMemberFunction()" << std::endl;
  std::cout << "The number is " << number_ << std::endl;
}
