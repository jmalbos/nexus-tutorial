// -----------------------------------------------------------------------------
//  C++ Intro | 4-polymorphism.cpp
//
//  Polymorphism.
// -----------------------------------------------------------------------------

#include "Shapes.h"

#include <iostream>
#include <vector>


int main()
{
  std::cout << "\nC++ Intro | 4-polymorphism\n" << std::endl;

  std::vector<Shape*> vs;

  Shape* circle = new Circle(1.0);
  vs.push_back(circle);

  Shape* square = new Square(1.0);
  vs.push_back(square);

  for (auto i: vs) {
    i->PrintName();
    std::cout << "Area: " << i->Area() << std::endl;
  }

  return 0;
}
