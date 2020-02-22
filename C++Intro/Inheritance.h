// -----------------------------------------------------------------------------
//  C++ Intro | Inheritance.h
//
//  Declaration of a base class and a derived one.
// -----------------------------------------------------------------------------

#ifndef INHERITANCE_H
#define INHERITANCE_H

#include <string>

////////////////////////////////////////////////////////////

class BaseClass
{
public:
  // Constructor
  BaseClass();

  // Destructor
  virtual ~BaseClass();

  // Public member function
  virtual void Print();

//private:
protected:
  // Accessors (setter and getter) to data member
  std::string GetName();
  void  SetName(std::string);

private:
  std::string name_; // Private data member
};

////////////////////////////////////////////////////////////

class DerivedClass: public BaseClass
{
public:
  // Constructor
  DerivedClass(std::string name);

  // Destructor
  ~DerivedClass();

  // Overriden function from base class
  void Print();
};

#endif
