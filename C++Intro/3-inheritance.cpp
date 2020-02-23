// -----------------------------------------------------------------------------
//  C++ Intro | 3-inheritance.cpp
//
//  Class inheritance. Memory allocation.
// -----------------------------------------------------------------------------

#include "Inheritance.h"

#include <iostream>


int main()
{
  std::cout << "\nC++ Intro | 3-inheritance\n" << std::endl;

  {
    std::cout << "Instance of the base class." << std::endl;
    BaseClass bc;
    bc.Print();
  }

  std::cout << std::endl;

  {
    std::cout << "Instance of the derived class." << std::endl;
    DerivedClass dc("derived");
    dc.Print();
  }

  return 0;
}
