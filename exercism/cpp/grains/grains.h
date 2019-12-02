#ifndef GRAINS_H
#define GRAINS_H
#define EXERCISM_RUN_ALL_TESTS
#include <cmath>
namespace grains {
constexpr unsigned long long square(unsigned char sqnum) {
  return std::pow(2ULL, sqnum - 1);
}
constexpr unsigned long long total() {
  unsigned char sq{65};
  unsigned long long out{0};
  while (--sq)
    out += square(sq);
  return out;
}
} // namespace grains
#endif // GRAINS_H