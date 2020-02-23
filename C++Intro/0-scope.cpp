// -----------------------------------------------------------------------------
//  C++ Intro | 0-scope.cpp
//
//  Function declaration and definition. Scope of variables. Namespaces.
// -----------------------------------------------------------------------------

#include <iostream>

// Declaration of a function: we let the compiler know about our function's
// name (func), parameters (none) and return type (void, i.e. nothing).
void func();

// Definition of a variable with global scope
int var = 123;

// Definition of a variable inside of a namespace
namespace foo { int var = 456; }

// Main function. Must return always an int.
int main()
{
  std::cout << "\nC++ Intro | 0-scope\n" << std::endl;

  std::cout << "var = " << var << std::endl;
  func();
  std::cout << "var = " << var << std::endl;

  std::cout << "foo::var = " << foo::var << std::endl;

  return 0;
}

// Definition of func(): we provide the body (implementation) of the function
void func()
{
  std::cout << "var = " << var << std::endl;
  int var = 0;
  std::cout << "var = " << var << std::endl;
}
