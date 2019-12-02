#ifndef TRINARY_H
#define TRINARY_H
#include <experimental/optional>
#include <iostream>
#include <numeric>
#include <string>
namespace trinary {
int for_position(int position, int digit);
int to_decimal(std::string value) noexcept;
} // namespace trinary

#endif // TRINARY_H