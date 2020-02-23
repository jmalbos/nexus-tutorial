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

  Shape* circle = new Circle(1.0);
  Shape* square = new Square(1.0);

  std::vector<Shape*> vs = {circle, square};
  //vs.push_back(circle);
  //vs.push_back(square);

  for (auto i: vs) {
    i->PrintName();
    std::cout << "Area: " << i->Area() << std::endl;
    delete i;
  }

  return 0;
}
