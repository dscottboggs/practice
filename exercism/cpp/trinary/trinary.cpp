#include "trinary.h"
#include <assert.h>
template <class T> using optional = std::experimental::optional<T>;
optional<int> parse_digit(char text) {
  switch (text) {
  case '0':
    std::cout << "digit " << text << " successfully parsed as "
              << *optional<int>{0} << ".\n";
    return optional<int>{0};
  case '1':
    std::cout << "digit " << text << " successfully parsed as "
              << *optional<int>{1} << ".\n";
    return optional<int>{1};
  case '2':
    std::cout << "digit " << text << " successfully parsed as "
              << *optional<int>{2} << ".\n";
    return optional<int>{2};
  case 0:
    std::cout << "got null byte.... aaahh\n";
    return optional<int>();
  default:
    std::cout << "digit 0x" << std::hex << int{text}
              << " failed to be evaluated as a trinary digit!\n";
    return optional<int>();
  }
}
unsigned int pow(const int v, const int power) {
  assert(power >= 0);
  int _pow = power;
  int out{v};
  if (_pow == 0)
    return 1;
  else
    while (--_pow)
      out *= v;
  return out;
}

int trinary::for_position(const int position, const int digit) {
  auto out = digit / pow(3, position) + (digit % pow(3, position));
  std::cout << "digit " << digit << " evalutated to " << out << " at position "
            << position << '\n';
  return out;
}
int trinary::to_decimal(std::string value) noexcept {
  int sum{0};
  for (int position = value.size() - 1; position >= 0; position--) {
    auto digit = parse_digit(value[position]);
    if (digit)
      sum += for_position(position, *digit);
    else
      return 0;
  }
  return sum;
}