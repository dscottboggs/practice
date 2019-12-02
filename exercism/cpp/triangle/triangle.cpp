#include "triangle.h"
#include <iostream>

bool triangle::is_equilateral() {
  return all_sides([this](float side) { return side == sides[0]; });
}
bool triangle::is_isosceles() {
  // The order doesn't really matter anyway
  std::sort(sides.begin(), sides.end());
  // if any two sides are equal, it's isosceles (because equilateral was already
  // checked)
  return std::adjacent_find(sides.begin(), sides.end()) != sides.end();
}
triangle::flavor triangle::kind() {
  if (is_equilateral())
    return flavor::equilateral;
  if (is_isosceles())
    return flavor::isosceles;
  return flavor::scalene;
}
triangle::flavor triangle::kind(std::array<float, 3> list) {
  triangle *t = new triangle{list};
  flavor f = t->kind();
  delete t;
  return f;
}
