#include "etl.h"
#include <iostream>

namespace etl {

std::map<char, int>
transform(std::map<int, std::vector<char>> old)
{
  std::map<char, int> newdata;
  for (auto pair : old) {
    auto score = pair.first;
    for (auto letter : pair.second)
      newdata[std::tolower(letter)] = score;
  }
  return newdata;
}

} // namespace etl
