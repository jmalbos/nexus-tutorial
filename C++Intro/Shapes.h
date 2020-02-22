// -----------------------------------------------------------------------------
//  C++ Intro | Shapes.h
//
//  Declaration of Shape abstract base class and several derived ones.
// -----------------------------------------------------------------------------

#ifndef SHAPES_H
#define SHAPES_H

#include <string>

////////////////////////////////////////////////////////////

class Shape
{
public:
  // Constructor
  Shape(std::string);

  // Destructor
  virtual ~Shape();

  // Returns area of shape.
  // Pure virtual (abstract) member function to be defined in derived classes.
  virtual float Area() = 0;

  void PrintName();

private:
  std::string name_; // Shape name
};

////////////////////////////////////////////////////////////

class Circle: public Shape
{
public:
  // Constructor
  Circle(float radius);

  // Destructor
  ~Circle();

  // Area of the circle
  float Area();

  void PrintName();

private:
  float radius_;
};

////////////////////////////////////////////////////////////

class Square: public Shape
{
public:
  // Constructor
  Square(float side);

  // Destructor
  ~Square();

  // Area of the circle
  float Area();

private:
  float side_;
};

////////////////////////////////////////////////////////////

inline Shape::Shape(std::string name): name_(name) {}
inline Shape::~Shape() {}

#endif
