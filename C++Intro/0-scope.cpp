// -----------------------------------------------------------------------------
//  C++ Intro | 0-scope.cpp
//
//  Function declaration and definition. Scope of variables.
// -----------------------------------------------------------------------------

#include <iostream>

// Declaration of a function: we let the compiler know about our function's
// name (foo), parameters (none) and return type (void, i.e. nothing).
void foo();

// Definition of a variable with global scope
int var = 31415;

// Main function. Must return always an int.
int main()
{
  std::cout << "\nC++ Intro | 0-scope\n" << std::endl;

  std::cout << "var = " << var << std::endl;
  foo();
  std::cout << "var = " << var << std::endl;

  return 0;
}

// Definition of foo: we provide the body (implementation) of the function
void foo()
{
  std::cout << "var = " << var << std::endl;
  int var = 0;
  std::cout << "var = " << var << std::endl;
}
