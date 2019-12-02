#include "polygon.h"

bool is_not_positive(float value) { return value <= 0; }

template <int Sides>
std::array<float, Sides> shape::polygon<Sides>::sorted_sides() {
  std::array<float, Sides> sorted = sides;
  std::sort(sorted.begin(), sorted.end());
  return sorted;
}

template <int Sides> void shape::polygon<Sides>::validate_sizes_are_gt_0() {
  if (any_side(is_not_positive))
    throw std::domain_error("invalid triangle -- a size was 0 or negative");
}
template <int Sides> void shape::polygon<Sides>::validate_inequality() {
  auto sorted = sorted_sides();
  auto max = sorted[sorted.size() - 1];
  auto all_but_max =
      std::accumulate(sorted.begin(), sorted.end() - 1, float(0));
  if (all_but_max < max)
    throw std::domain_error(
        "all sides except for the maximally-long side add up to a greater "
        "length than the maximally-long side is long.");
}
template <int Sides>
bool shape::polygon<Sides>::any_side(std::function<bool(float)> pred) {
  return std::any_of(sides.begin(), sides.end(), pred);
}
template <int Sides>
bool shape::polygon<Sides>::all_sides(std::function<bool(float)> pred) {
  return std::all_of(sides.begin(), sides.end(), pred);
}


