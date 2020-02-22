// -----------------------------------------------------------------------------
//  C++ Intro | Inheritance.cpp
//
//  Definition of an abstract base class and several derived ones.
// -----------------------------------------------------------------------------

#include "Inheritance.h"

#include <iostream>

////////////////////////////////////////////////////////////

BaseClass::BaseClass(): name_("<blank>")
{
  std::cout << "BaseClass::BaseClass()" << std::endl;
}

BaseClass::~BaseClass()
{
  std::cout << "BaseClass::~BaseClass()" << std::endl;
}

void BaseClass::Print()
{
  std::cout << "BaseClass::Print()" << std::endl;
  std::cout << "This class is called " << name_ << "." << std::endl;
}

std::string BaseClass::GetName()
{
  return name_;
}

void BaseClass::SetName(std::string name)
{
  name_ = name;
}

////////////////////////////////////////////////////////////

DerivedClass::DerivedClass(std::string name): BaseClass()
{
  std::cout << "DerivedClass::DerivedClass()" << std::endl;
  SetName(name);
}

DerivedClass::~DerivedClass()
{
  std::cout << "DerivedClass::~DerivedClass()" << std::endl;
}

void DerivedClass::Print()
{
  std::cout << "DerivedClass::Print()" << std::endl;
  std::cout << "This class is called " << GetName() << "." << std::endl;
}
