#include "polygon.h"
#include <array>
#include <functional>
#include <iostream>
#include <memory>
#define EXERCISM_RUN_ALL_TESTS

class triangle : public shape::polygon<3> {
private:
  // used to implement #flavor()
  bool is_equilateral();
  bool is_isosceles();

public:
  enum class flavor : char { equilateral, isosceles, scalene };
  triangle(std::array<float, 3> init) : shape::polygon<3>(init){};
  flavor kind();
  static flavor kind(std::array<float, 3> s);
  static flavor kind(float a, float b, float c) { return kind({a, b, c}); };
};
