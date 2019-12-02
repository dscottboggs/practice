#include <array>
#include <ostream>
#include <functional>
#include <execution>
#include <numeric>
#include <algorithm>
#include <cstdio>
namespace shape {
template <int Sides> class polygon {
protected:
  std::array<float, Sides> sides;

  void validate_sizes_are_gt_0();
  void validate_inequality();
  std::array<float, Sides> sorted_sides();
  // Return true if any side returns true when passed to pred.
  bool any_side(std::function<bool(float)> pred);
  // Return true if all sides return true when passed to pred.
  bool all_sides(std::function<bool(float)> pred);

public:
  polygon(std::array<float, Sides> s) : sides{s} { validate(); };
  // Throws std::domain_error if the polygon is not a valid shape
  void validate() {
    validate_sizes_are_gt_0();
    validate_inequality();
  };
  friend std::ostream &operator<<(std::ostream &out, const polygon &self) {
    out << "shape {number of sides: " << Sides << "; sides: [";
    for (auto side : self.sides)
      out << side << ", ";
    return out << "]}";
  }
};
} // namespace shape


