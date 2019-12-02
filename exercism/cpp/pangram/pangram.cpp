#include "pangram.h"
#include <algorithm>
#include <array>
#include <map>
#include <numeric>

// Build the array of letters in the alphabet.
const auto alphabet{[] {
  std::array<char, 26> ab;
  std::iota(ab.begin(), ab.end(), 'a');
  return ab;
}()};

bool pangram::is_pangram(const std::string &&text) {
  if (text.size() < 26)
    return false;
  std::map<char, bool> letters;
  for (auto letter : text) {
    letter = std::tolower(letter);
    if (std::find(alphabet.begin(), alphabet.end(), letter) != alphabet.end())
      letters[letter] = true;
  }
  return letters.size() == 26;
}
