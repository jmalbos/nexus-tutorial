// -----------------------------------------------------------------------------
//  C++ Intro | Shapes.cpp
//
//  Definition of Circle and Square shapes.
// -----------------------------------------------------------------------------

#include "Shapes.h"

#include <iostream>
#include <cmath>

////////////////////////////////////////////////////////////

void Shape::PrintName()
{
  std::cout << "This shape is called " << name_ << "." << std::endl;
}

////////////////////////////////////////////////////////////

Circle::Circle(float radius): Shape("circle"), radius_(radius)
{
}


Circle::~Circle()
{
}


float Circle::Area()
{
  return M_PI*radius_*radius_;
}


void Circle::PrintName()
{
  std::cout << "Circle::PrintName()" << std::endl;
  Shape::PrintName();
}

////////////////////////////////////////////////////////////

Square::Square(float side): Shape("square"), side_(side)
{
}


Square::~Square()
{
}


float Square::Area()
{
  return side_*side_;
}

////////////////////////////////////////////////////////////
